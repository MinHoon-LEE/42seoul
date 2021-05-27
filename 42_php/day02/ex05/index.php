<?php
include 'TemplateEngine.php';
$elem = new Elem('html');
$body = new Elem('head');
$body->pushElement(new Elem('meta','',['charset' => 'utf-8']));
$body->pushElement(new Elem('title','minlee'));
$elem->pushElement($body);
$bb = new Elem('body');
$bb->pushElement(new Elem('p', '하기시렁 ㅠㅠㅠㅠㅠㅋㅋ', ['class' => 'text-muted']));
$elem->pushElement($bb);
$template = new TemplateEngine($elem);
if ($elem->validPage())
	$template ->createFile("minlee.html");
?>
