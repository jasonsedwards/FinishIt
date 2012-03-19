<?php
include('inc/Config.inc');
/**
 * Installs and configures a database schema for a given product
 *
 * @author edwardsj
 */
class Install {
    
    public static function buildDB(){
        $settings = Config::read('settings.inc');
        $con = mysql_connect($settings['host'],$settings['username'],$settings['password']);
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        }
        
        // make foo the current db
        $db_selected = mysql_select_db($settings['database'], $con);
        if (!$db_selected) {
            die ('Can\'t use database : ' . mysql_error());
        }
        $file = include("install/schema.sql"); 
        mysql_query($file) or exit(mysql_error()); 
        mysql_close($con);
    }
}

?>
