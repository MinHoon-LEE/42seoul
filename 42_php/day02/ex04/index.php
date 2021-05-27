<?php
include 'TemplateEngine.php';
$elem = new Elem('html');
$body = new Elem('body');
$body->pushElement(new Elem('p', 'Lorem ipsum'));
$body->pushElement(new Elem('p', 'Lorem ipsum', ['class' => 'text-muted']));
$elem->pushElement($body);
echo $elem->getHTML();
$template = new TemplateEngine($elem);
$template ->createFile("minlee.html");
?>
