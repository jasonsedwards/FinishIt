<?php

/**
 * Reads settings in from a specified config file.
 *
 * @author edwardsj
 */
class Config {
    public static function read($filename){
        $config = include $filename;
        return $config;
    }
    public static function write($filename, array $config){
        $config = var_export($config, true);
        file_put_contents($filename, "<?php return $config ;");
    }
}

?>
