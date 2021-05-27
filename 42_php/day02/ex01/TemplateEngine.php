<?php
include "Text.php";
class TemplateEngine
{
	function createFile($fileName, Text $text)
	{
		$fp = fopen($fileName,"w");
		fwrite($fp,"<!DOCTYPE html><html><head><title>minlee</title></head><body><h1>MinLEE</h1>");
		$i = 0;
		while ($text->array[$i])
		{
			fwrite($fp, $text->array[$i]);
			$i++;
		}
		fwrite($fp,"</body></html>");
		fclose($fp);
	}
}
?>
