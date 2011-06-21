<?php

/* vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4: */

/**
 * Client URL Utility
 *
 * Client URL Utility for accessing Web Pages.
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

class ClientUrlUtil
{

    public    $aryData;
    protected $strUrl;
    private   $_flag;

    /**
    * Get Url Results. 
    * @param    $url Target URL you want to get.
    * @return   URL Response.
    */
    public static function getUrl($url){
        // create curl resource
        $ch = curl_init();

        // set url
        curl_setopt($ch, CURLOPT_URL, $url);

        //return the transfer as a string
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

        // $output contains the output string
        $output = curl_exec($ch);

        // close curl resource to free up system resources
        curl_close($ch);      

        return $output;
    }

}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
*/
?>
