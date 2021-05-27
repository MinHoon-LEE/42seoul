<?php
include "Elem.php";
class TemplateEngine
{
	private $string;
	public function __construct(Elem $Element)
	{
		$this->string = $Element->getHTML();
	}
	function createFile($fileName)
	{
		$fp = fopen($fileName,"w");
		fwrite($fp,$this->string);
		fclose($fp);
	}
}
?>

