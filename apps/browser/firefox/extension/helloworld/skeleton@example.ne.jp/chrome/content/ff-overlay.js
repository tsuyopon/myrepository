{
	let tm;
	var skeletonNs={
		// グローバル・オブジェクトを書く
		onMenuItemCommand:function(){


			alert('Hello World1');
			window.open(" chrome://skeleton/content/prefs.xul", "bmarks", "chrome,width=600,height=300");
		}
	};

	let init=function() {
		window.clearTimeout(tm);
		// 拡張の初期化処理を書く
	};

	tm=window.setTimeout(init,500);
}
