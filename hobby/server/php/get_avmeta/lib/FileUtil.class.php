<?php

/* vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4: */

/**
 * File Utility
 *
 * Utilities for Operate File.
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

class FileUtil
{

    /**
    * Simple Method To Write File.
    * @param    $str  String which you want to write into $file.
    * @param    $file Target file name you want to write.
    * @param    $mode Write Mode(ie. r, r+, w, w+, a, a+)
    * @return   URL Response.
    */
    public static function SimpleWriteFile($str, $file, $mode){
        $fh = fopen($file, $mode);
        fwrite($fh, $str);
        fclose($fh);
        return TRUE;
    }

    /**
    * Simple Method To Read File.
    * @param    $file Target file name you want to write.
    * @return   URL Response.
    */
    public static function SimpleReadFile($file){

        if (! ($fp = fopen ($file, "rb"))) {
            return FALSE;
        }
        $load=fread($fp, filesize($file) );
        fclose($fp);
        return $load;
    }

}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
*/
?>
