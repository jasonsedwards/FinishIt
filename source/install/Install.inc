<?php
include('../inc/Config.inc');
/**
 * Installs and configures a database schema for a given product
 *
 * @author edwardsj
 */
class Install {
    
    public static function buildDB($settingsfile, $sqlfile){
        //grab the SQL
        $settings = Config::read($settingsfile);
        $con = mysql_connect($settings['host'],$settings['username'],$settings['password']);
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        }
        
        // select the DB
        $db_selected = mysql_select_db($settings['database'], $con);
        if (!$db_selected) {
            die ('Can\'t use database : ' . mysql_error());
        }
        //break the file into separate lines using ; as the delimeter.
        $sql = explode(";\n", file_get_contents($sqlfile));
        //iterate through each line passing it to mysql_query for execution.
        foreach ($sql as $key => $val) {
            mysql_query($val);
        }
    }
}

?>
