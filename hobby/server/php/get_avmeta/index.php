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

		// ��AV��ͥ�ξ�������
		foreach($this->html_->find('.list') as $e){

			// �����ե�����
			$image    = $e->find('.pic', 0)->find('img', 0)->src;
			$url      = $e->children(1)->find('a', 0)->href;
			preg_match('!/actress_id=(\d+)/!', $url, $cid);
			$name     = $e->children(1)->plaintext;
			$namekana = $e->children(2)->plaintext;

			// ��Ͽ�ե�����
			$prepare->bindValue(':cid', $cid[1]);
			$prepare->bindValue(':actress_name', $name);
			$prepare->bindValue(':actress_name_kana', $namekana);

			// �¹�
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
			sleep(10);   // ���¦����٤򤫤��ʤ������ɬ��
		}
	}
}

class ActressDetailDB extends DatabaseUtil {

	public function execute(){
		$qry = $this->_oPdo->query("SELECT DISTINCT cid, actress_name, actress_name_kana FROM tmp_actress ");
		while($row = $qry->fetch(PDO::FETCH_ASSOC)){

			$data = array();
			// AV��ͥ�˴ؤ������ե�������ɤ߹��ߤޤ�
			$data = sprintf("./data/actress/%d.txt", $row['cid']);
			$readActress = FileUtil::SimpleReadFile($data);
			$html = str_get_html($readActress);

			// AV��ͥ�˴ؤ�����ǯ���������¡���շ������������п��ϡ��õ�����̣�����
			$i = 0;
			foreach($html->find("#mu table tbody tr td table tbody tr td table tbody tr") as $e){
				if($i > 5){  // ;ʬ�ʤ�Τ����äĤ��Ƥ���Τ�6��(��ǯ���������¡���շ������������п��ϡ��õ�)������
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

			// �����ե�����
			$prepare  = $this->_oPdo->prepare("INSERT INTO actress (cid, actress_name, actress_name_kana, birthdate, asterism, bloodtype, hometown, figure, hobby) VALUES(:cid, :actress_name, :actress_name_kana, :birthdate, :asterism, :bloodtype, :hometown, :figure, :hobby)");

			// ��Ͽ�ե�����
			$prepare->bindValue(':cid',               $row['cid']);
			$prepare->bindValue(':actress_name',      $row['actress_name']);
			$prepare->bindValue(':actress_name_kana', $row['actress_name_kana']);
			$prepare->bindValue(':birthdate', $birthdate);
			$prepare->bindValue(':asterism',  $asterism);
			$prepare->bindValue(':bloodtype', $bloodtype);
			$prepare->bindValue(':hometown',  $hometown);
			$prepare->bindValue(':figure',    $figure);
			$prepare->bindValue(':hobby',     $hobby);

			// �¹�
			$prepare->execute();

			// �����
			$html->clear();                                               // ���ε��Ҥ򤷤ʤ��ȥ���꡼���ˤʤ�ޤ�
			$data = null;
		}
	}
}

///////////////////////////////////////////////////////////
// 0. �ǡ�������
///////////////////////////////////////////////////////////
$get_idx_data        = false;  // INDEX�ǡ�������
$insert_idx_data     = false;  // PDO�ˤ��ǡ�����Ͽ
$get_actress_data    = false;  // AV��ͥ�������
$insert_actress_data = false;  // AV��ͥ�ܺپ������

///////////////////////////////////////////////////////////
// 0.1. ����ǡ���
///////////////////////////////////////////////////////////
	// FIXME: ɬ�פ���м��������ǡ��������Ƥ���������
	// �ڡ�������ư��������褦�ˤ��뤳��
	// DMM.com�θ����������������Ԥ���(�����ϥڡ�������ɽ���ޤ�)
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
// 1. INDEX�ǡ�������( �֤��׹Ԣ֤͡��׹� �� ....  )
///////////////////////////////////////////////////////////
// �ǡ���������������true�����ꤷ�ޤ�
if( $get_idx_data == true ){
	foreach($aryIdxData as $key => $value){

		// �ڡ�����ʬ�롼�פ��ޤ���
		for($i = 1; $i < (int)$value; $i++){
			$url  = sprintf("http://actress.dmm.co.jp/-/list/=/keyword=%s/page=%d/", $key, $i);
			$file = "./data/$key-$i.txt";
			echo $file ." FILE GETTING START\n";
			$output = ClientUrlUtil::getUrl($url);
			$mode = "w";
			FileUtil::SimpleWriteFile($output, $file, $mode);
			sleep(3);   // ���¦����٤򤫤��ʤ������ɬ��
		}

	}
}

///////////////////////////////////////////////////////////
// 2. PDO��Ȥäƥǡ�����Ͽ��Ԥ�
///////////////////////////////////////////////////////////

if( $insert_idx_data == true ){
	$hd = new TmpDB();
	$hd->setDatabaseName("AVLIST");
	$hd->setDatabaseAccount("root");
	$hd->setDatabasePasswd("");
	// INDEX�˱����ƥ롼��
	foreach($aryIdxData as $key => $value){
		// �ڡ����͡�������ʬ����
		for($i = 1; $i < (int)$value; $i++){
			$data = "./data/$key-$i.txt";
			echo "$data START\n";
			$readActress = FileUtil::SimpleReadFile($data);
			$html = str_get_html($readActress);
			$hd->setHtmlTemplate($html);
			$hd->connect();
			$readActress = null;
			$html->clear();                                               // ���ε��Ҥ򤷤ʤ��ȥ���꡼���ˤʤ�ޤ�
		}
	}
	$hd = null;
}

///////////////////////////////////////////////////////////
// 3. �ƸĿͤ�AV��ͥ������������
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
// 4. �ƸĿͤ�AV��ͥ�����DB����Ͽ����
///////////////////////////////////////////////////////////
if( $insert_actress_data == true ){
	$hd = new ActressDetailDB();
	$hd->setDatabaseName("AVLIST");
	$hd->setDatabaseAccount("root");
	$hd->setDatabasePasswd("");
	$hd->connect();
}

?>
