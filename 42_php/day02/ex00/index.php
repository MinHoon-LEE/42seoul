<?php

	include 'TemplateEngine.php';
	$tmp = new TemplateEngine();
	$arr = array(
		"nom" => "Welcome to minlee's store!",
		"auteur" => "minlee",
		"description" => "Python",
		"prix" => "1,000,000",
	);
	$tmp->createFile("minlee.html","book_description.html",$arr);
?>
