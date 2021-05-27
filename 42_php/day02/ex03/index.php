<?php
include 'TemplateEngine.php';
$elem = new Elem('html');
$body = new Elem('body');
$body->pushElement(new Elem('p', 'Lorem ipsum'));
$elem->pushElement($body);
echo $elem->getHTML();
$template = new TemplateEngine($elem);
$template ->createFile("minlee.html");
?>
