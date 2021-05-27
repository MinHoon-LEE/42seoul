<?php
	include 'TemplateEngine.php';
	$tmp = new TemplateEngine();
	$data = new Text(array("Auteur: minlee","Description: Python","Prix: 1,000,000 €","Etc..."));
	$data->add_string("bbbcbc");
	$tmp->createFile("minlee.html",$data);
?>
