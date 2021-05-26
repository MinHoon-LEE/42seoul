<?php
	
	function split_arr($tmp)
	{
		$answer = array();
		list($name, $remain) = explode(" = ", $tmp, 2);
		list($position, $number, $small, $molar, $electron) = explode(", ", $remain, 5);
		list($pos, $position) = explode(":", $position, 2);
		list($pos, $number) = explode(":", $number, 2);
		list($pos, $small) = explode(": ", $small, 2);
		list($pos, $molar) = explode(":", $molar, 2);
		list($pos, $electron) = explode(":", $electron, 2);
			return (array($name, $position,$number, $small, $molar, $electron));
	}
	$file = fopen("mendeleiev.html", "w") or die("Unable to open file!");
	fwrite($file,"<html><head><title><h1>peroidic_table</h1></title></head><body>");
	fwrite($file,"<table style=\"font-size:0.5em;\"><tr>");
	$data = fopen("ex06.txt","r") or die("Unable to open file!");
	$cnt = 0;
	while(($tmp = fgets($data)) !== false)
	{
		$arr = split_arr($tmp);
		for ($cnt; $cnt < $arr[1]; $cnt++)
			fwrite($file,"<td></td>");
		fwrite($file,"<td style=\"border: 1px solid black; padding:10px\">");
		fwrite($file,"<h4>$arr[0]</h4><ul style=\"padding-left:10px\">");
		fwrite($file,"<li>No $arr[2]</li>");
		fwrite($file,"<li>$arr[3]</li>");
		fwrite($file,"<li>$arr[4]</li>");
		fwrite($file,"<li style=\"font-size:7px\">$arr[5] electron</li></ul></td>");
		$cnt++;
		if ($cnt == 18)
		{
			fwrite($file,"<tr></tr>");
			$cnt = 0;
		}
		if ($data == NULL)
			break ;
	}
	fwrite($data,"</tr></table></html>");
	fclose($data);
	fclose($file);
?>
