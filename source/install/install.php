<?php
    include('Install.inc');
    $settings = Config::read('../settings.inc');
    if($settings['installed'] == 'no'){
        Install::buildDB('../settings.inc', 'schema.sql');
        $settings['installed'] = 'yes';
        Config::write('../settings.inc', $settings);
    }
    else{
        echo("FinishIt is already installed");
    }
?>
