<?php

include 'TemplateEngine.php';
$template = new TemplateEngine();
$coffee = new Coffee("Americano","15","50%","Super tasty","JMT");
$Tea = new Tea("Lilac","11","80%","Super hot","10JMT");
$template->createFile($coffee);
$template->createFile($Tea);
?>

