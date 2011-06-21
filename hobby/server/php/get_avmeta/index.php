<?php
	require_once('./lib/ClientUrlUtil.class.php');
	require_once('./lib/FileUtil.class.php');
	require_once('./lib/ScrapeUtil.class.php');
	require_once('./lib/simple_html_dom.php');
	require_once('./lib/DatabaseUtil.class.php');

class TmpDB extends DatabaseUtil {

	public $html_;

	public function setHtmlTemplate($html){
		$this->html_ = $html;
	}

	public function execute(){

		$prepare  = $this->_oPdo->prepare("INSERT INTO tmp_actress (cid, actress_name, actress_name_kana) VALUES(:cid, :actress_name, :actress_name_kana)");

		// 各AV女優の情報を取得
		foreach($this->html_->find('.list') as $e){

			// 準備フェーズ
			$image    = $e->find('.pic', 0)->find('img', 0)->src;
			$url      = $e->children(1)->find('a', 0)->href;
			preg_match('!/actress_id=(\d+)/!', $url, $cid);
			$name     = $e->children(1)->plaintext;
			$namekana = $e->children(2)->plaintext;

			// 登録フェーズ
			$prepare->bindValue(':cid', $cid[1]);
			$prepare->bindValue(':actress_name', $name);
			$prepare->bindValue(':actress_name_kana', $namekana);

			// 実行
			$prepare->execute();

		}
		$this->html_ = null;
	}
}

class ActressDB extends DatabaseUtil {

	public function execute(){
		$qry = $this->_oPdo->query("SELECT * FROM tmp_actress");
		$i = 1;
		while($row = $qry->fetch(PDO::FETCH_ASSOC)){
			//echo $row['pkid'] . "  " . $row['cid']."\n";
			$url  = sprintf("http://actress.dmm.co.jp/-/detail/=/actress_id=%s/", $row['cid']);
			$output = ClientUrlUtil::getUrl($url);
			$file = "./data/actress/".$row['cid'].".txt";
			echo $file ." FILE GETTING START\n";
			$mode = "w";
			FileUtil::SimpleWriteFile($output, $file, $mode);
			sleep(10);   // 相手側に負荷をかけないために必須
		}
	}
}

class ActressDetailDB extends DatabaseUtil {

	public function execute(){
		$qry = $this->_oPdo->query("SELECT DISTINCT cid, actress_name, actress_name_kana FROM tmp_actress ");
		while($row = $qry->fetch(PDO::FETCH_ASSOC)){

			$data = array();
			// AV女優に関する情報ファイルを読み込みます
			$data = sprintf("./data/actress/%d.txt", $row['cid']);
			$readActress = FileUtil::SimpleReadFile($data);
			$html = str_get_html($readActress);

			// AV女優に関する生年月日、星座、血液型、サイズ、出身地、特技・趣味を取得
			$i = 0;
			foreach($html->find("#mu table tbody tr td table tbody tr td table tbody tr") as $e){
				if($i > 5){  // 余分なものがくっついてくるので6個(生年月日、正座、血液型、サイズ、出身地、特技)に制限
					break;
				}

				$data = $e->children(1)->plaintext;
				if( $i == 0){
					$birthdate = $data;
				} else if($i == 1){
					$asterism = $data;
				} else if($i == 2){
					$bloodtype = $data;
				} else if($i == 3){
					$hometown = $data;
				} else if($i == 4){
					$figure = $data;
				} else if($i == 5){
					$hobby = $data;
				}
				$i++;
			}

			// 準備フェーズ
			$prepare  = $this->_oPdo->prepare("INSERT INTO actress (cid, actress_name, actress_name_kana, birthdate, asterism, bloodtype, hometown, figure, hobby) VALUES(:cid, :actress_name, :actress_name_kana, :birthdate, :asterism, :bloodtype, :hometown, :figure, :hobby)");

			// 登録フェーズ
			$prepare->bindValue(':cid',               $row['cid']);
			$prepare->bindValue(':actress_name',      $row['actress_name']);
			$prepare->bindValue(':actress_name_kana', $row['actress_name_kana']);
			$prepare->bindValue(':birthdate', $birthdate);
			$prepare->bindValue(':asterism',  $asterism);
			$prepare->bindValue(':bloodtype', $bloodtype);
			$prepare->bindValue(':hometown',  $hometown);
			$prepare->bindValue(':figure',    $figure);
			$prepare->bindValue(':hobby',     $hobby);

			// 実行
			$prepare->execute();

			// 後処理
			$html->clear();                                               // この記述をしないとメモリリークになります
			$data = null;
		}
	}
}

///////////////////////////////////////////////////////////
// 0. データ準備
///////////////////////////////////////////////////////////
$get_idx_data        = false;  // INDEXデータ取得
$insert_idx_data     = false;  // PDOによるデータ登録
$get_actress_data    = false;  // AV女優情報取得
$insert_actress_data = false;  // AV女優詳細情報取得

///////////////////////////////////////////////////////////
// 0.1. 初期データ
///////////////////////////////////////////////////////////
	// FIXME: 必要あれば取得したデータを除去してください。
	// ページ数を自動取得するようにすること
	// DMM.comの牽引検索から取得を行う為(数字はページ数を表します)
	$aryIdxData = array( 'a' => 16, 'i' => 7,  'u' => 3,  'e' => 1, 'o' => 6,
						'ka' => 9,  'ki' => 5, 'ku' => 4, 'ke' => 1, 'ko' => 5,
						'sa' => 10, 'si' => 6, 'su' => 3, 'se' => 2, 'so' => 1,
						'ta' => 6,  'ti' => 1, 'tu' => 2, 'te' => 1, 'to' => 2,
						'na' => 7,  'ni' => 2, 'nu' => 1, 'ne' => 1, 'no' => 1,
						'ha' => 6,  'hi' => 4, 'hu' => 5, 'he' => 1, 'ho' => 4,
						'ma' => 6,  'mi' => 9, 'mu' => 1, 'me' => 1, 'mo' => 4,
						'ya' => 3,  'yu' => 3, 'yo' => 3,
						'ra' => 1,  'ri' => 1, 'ru' => 1, 're' => 1, 'ro' => 1,
						'wa' => 2
	);

///////////////////////////////////////////////////////////
// 1. INDEXデータ取得( 「あ」行⇒「い」行 ⇒ ....  )
///////////////////////////////////////////////////////////
// データを取得する場合にtrueと設定します
if( $get_idx_data == true ){
	foreach($aryIdxData as $key => $value){

		// ページ数分ループします。
		for($i = 1; $i < (int)$value; $i++){
			$url  = sprintf("http://actress.dmm.co.jp/-/list/=/keyword=%s/page=%d/", $key, $i);
			$file = "./data/$key-$i.txt";
			echo $file ." FILE GETTING START\n";
			$output = ClientUrlUtil::getUrl($url);
			$mode = "w";
			FileUtil::SimpleWriteFile($output, $file, $mode);
			sleep(3);   // 相手側に負荷をかけないために必須
		}

	}
}

///////////////////////////////////////////////////////////
// 2. PDOを使ってデータ登録を行う
///////////////////////////////////////////////////////////

if( $insert_idx_data == true ){
	$hd = new TmpDB();
	$hd->setDatabaseName("AVLIST");
	$hd->setDatabaseAccount("root");
	$hd->setDatabasePasswd("");
	// INDEXに応じてループ
	foreach($aryIdxData as $key => $value){
		// ページネーション数分処理
		for($i = 1; $i < (int)$value; $i++){
			$data = "./data/$key-$i.txt";
			echo "$data START\n";
			$readActress = FileUtil::SimpleReadFile($data);
			$html = str_get_html($readActress);
			$hd->setHtmlTemplate($html);
			$hd->connect();
			$readActress = null;
			$html->clear();                                               // この記述をしないとメモリリークになります
		}
	}
	$hd = null;
}

///////////////////////////////////////////////////////////
// 3. 各個人のAV女優情報を取得する
///////////////////////////////////////////////////////////
if( $get_actress_data == true ){
	$hd = new ActressDB();
	$hd->setDatabaseName("AVLIST");
	$hd->setDatabaseAccount("root");
	$hd->setDatabasePasswd("");
	$hd->connect();
	$hd->null;
}

///////////////////////////////////////////////////////////
// 4. 各個人のAV女優情報をDBに登録する
///////////////////////////////////////////////////////////
if( $insert_actress_data == true ){
	$hd = new ActressDetailDB();
	$hd->setDatabaseName("AVLIST");
	$hd->setDatabaseAccount("root");
	$hd->setDatabasePasswd("");
	$hd->connect();
}

?>
