<?php
class TemplateEngine
{
	function createFile($fileName, $templateName, $parameters)
	{
		$fp = fopen($fileName,"w");
		$tp = fopen($templateName, "r");
		while(($tmp = fgets($tp)) !== false)
		{
			list($s1,$s2) = explode("{",$tmp,2);
			list($s2,$s3) = explode("}",$s2, 2);
			if (array_key_exists($s2,$parameters))
				$s2 = $parameters[$s2];
			fwrite($fp,$s1 . $s2 . $s3);
		}
		fclose($tp);
		fclose($fp);
	}
}
?>
