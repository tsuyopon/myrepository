<?php

/* vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4: */

/**
 * Database Utility
 *
 * Database Utility for Accessing Database.
 *
 * PHP versions 4 and 5
 *
 * LICENSE: This source file is subject to version 3.0 of the PHP license
 * that is available through the world-wide-web at the following URI:
 * http://www.php.net/license/3_0.txt.  If you did not receive a copy of
 * the PHP License and are unable to obtain it through the web, please
 * send a note to license@php.net so we can mail you a copy immediately.
 *
 * @category   CategoryName
 * @package    <MyPackage>
 * @author     tsuyopon <tsuyoppy@r2.dion.ne.jp>
 * @copyright  1997-2005 The PHP Group
 * @license    http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version    1.0
 * @link       http://pear.php.net/package/<MyPackage>
 */

/*
 * This class Requires PDO Package.
 * User must extends this class(example. MyDBClass extends DatabaseUtil)
 * And, you must define MyDBClass#execute() method.
 * This class is abstracted class.
*/
abstract class DatabaseUtil
{

    private $_iPort   ="3306";
    private $_sMethod ="mysql";
    private $_sHost   ="localhost";
    private $_sDbname;
    private $_sAccount;
    private $_sPasswd;
    protected $_oPdo;

    /**
    * Constructor
    * @param    void
    * @return   void
    */
    public function __construct(){
        if (!extension_loaded('pdo')) {
            return FALSE;
        }
    }

    /**
    * Destructor
    * @param    void
    * @return   void
    */
    public function __destruct(){
        $this->_oPdo = null;
    }

    /**
    * DB Port Setting
    * @param    $port Port Number for Accessing Database.
    * @return   void
    */
    public function setDatabasePort($port=3306){
        $this->_iPort = 3306;
    }

    /**
    * DB Method Setting
    * @param    $port Port Number for Accessing Database.
    * @return   void
    */
    public function setDatabaseMethod($method="mysql"){
        $this->_sMethod = $method;
    }

    /**
    * DB Hostname Setting
    * @param    $hostname Hostname for Accessing Database.
    * @return   void
    */
    public function setDatabaseHost($hostname){
        $this->_sHost = $hostname;
    }

    /**
    * DB DatabaseName Setting
    * @param    $dbname Database Name for Accessing Database.
    * @return   void
    */
    public function setDatabaseName($dbname){
        $this->_sDbname = $dbname;
    }

    /**
    * DB Account Setting
    * @param    $account Port Number for Accessing Database.
    * @return   void
    */
    public function setDatabaseAccount($account){
        $this->_sAccount = $account;
    }

    /**
    * DB Password Setting
    * @param    $passwd Password for Accessing Database.
    * @return   void
    */
    public function setDatabasePasswd($passwd){
        $this->_sPasswd = $passwd;
    }

    /**
    * Connection for Database Interface.
    * @param    void
    * @return   void
    */
    public function connect(){
        try {
            $arg = sprintf("%s:host=%s; port=%s; dbname=%s", $this->_sMethod, $this->_sHost, $this->_iPort, $this->_sDbname);
            $this->_oPdo = new PDO($arg, $this->_sAccount, $this->_sPasswd);
            $this->execute();
        } catch(PDOException $e){
            var_dump($e->getMessage());
        }
    }

    /**
    * Abstract method called by connect()
    * @param    void
    * @return   
    */
    abstract public function execute();

}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
*/
?>
