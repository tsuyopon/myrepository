<?php

/* vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4: */

/**
 * Scraping URL Utility
 *
 * Utilities for Scraping Web Pages.
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

class ScrapeUtil
{

    /**
    * Normalization Process into HTML.
    * @param    $str HTML String.
    * @return   Normalized HTML Data.
    */
    public function cleanString($str){
        $strData = str_replace( array(chr(10), chr(13), chr(9)), chr(32), $str);    // chr() args => 10: LineField, 13: NewLine, 9: Tab, 32: Space
        while( strpos( $strData, str_repeat(chr(32), 2), 0 ) != false ){                // Eliminate Redundunt Space.
            $strData = str_replace(str_repeat(chr(32), 2), chr(32), $strData);
        } 
        return(trim($strData));
    }

    /**
    * Get Target HTML Source Code.
    * @param    $start Start Tag Prefix
    * @param    $end End Tag Prefix
    * @param    $src HTML SourceCode
    * @param    $prefix Prefix before $start.
    * @return   Partial HTML Source Code .
    */
    public function getBlock($start, $end, $src, $prefix=true){
        $strData = null;
        $srhStart = strpos( strtolower($src), strtolower($start), 0);
        if( $srhStart === false ){
            return $strData;
        }
        $srhStart = ($prefix == false) ? $srhStart + strlen($start) : $srhStart;
        $srhEnd   = strpos( strtolower($src), strtolower($end), $start);

//        echo 'START: ' . $srhStart."\n";
//        echo 'END: ' . $srhEnd."\n";
        if($srhEnd > $srhStart){
            $strData = trim( substr($src, $srhStart, $srhEnd - $srhStart) );
        }
        return $strData;
    }

    /**
    * Get Target HTML Source Code.
    * @param    $start Start Tag Prefix
    * @param    $end End Tag Prefix
    * @param    $src HTML SourceCode
    * @param    $prefix Prefix before $start.
    * @return   Partial HTML Source Code .
    */
    public function getElement($elem, $src){
        $strData = null;
        $elem = strtolower($elem);
        $srhStart = strpos( strtolower($src), chr(60) . $elem, 0);
        $srhStart = strpos( $src, chr(62), $srhStart) + 1;
        $srhEnd   = strpos( strtolower($src), "</" . $elem . chr(62) , $srhStart);
        if( $srhStart > strlen($elem) && $srhEnd > $srhStart ){
            $strData = trim( substr($src, $srhStart, $srhEnd - $srhStart) );
        }
        return $strData;

    }

}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
*/
?>
