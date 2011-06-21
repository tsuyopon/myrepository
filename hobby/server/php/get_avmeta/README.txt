DESCRIPTION:
	1. THIS SCRIPT GETS AV ACTRESS INFO.
	2. INSERT DB INTO DETAILED META DATA.

USAGE:
	1. mysql -uxxxxx -p < mysql/schema.xml
	2. If you want to activate phase, you change variables into true.
	$ vi index.php
	----------------------------
	$get_idx_data        = false;
	$insert_idx_data     = false;
	$get_actress_data    = false;
	$insert_actress_data = false;
	----------------------------
	3. php index.php    // this takes a long time.
	4. finish

