<?php
include 'Coffee.php';
include 'Tea.php';
class TemplateEngine
{
	public function createFile(HotBeverage $text)
	{
		$array = array();
		$array[0] = $text->getname();
		$array[1] = $text->getname();
		$array[2] = $text->getprice();
		$array[3] = $text->getresistance();
		$array[4] = $text->getdescription();
		$array[5] = $text->getcomment();
		$fp = fopen("$array[0].html","w");
		$tp = fopen("template.html", "r");
		$i = 0;
		while(($tmp = fgets($tp)) !== false)
		{
			list($s1,$s2) = explode("{",$tmp,2);
			list($s2,$s3) = explode("}",$s2, 2);
			if ($s2 != NULL)
			{
				$s2 = $array[$i];
				$i++;
			}
			fwrite($fp,$s1 . $s2 . $s3);
		}
		fclose($tp);
		fclose($fp);
	}
}
?>
