<?php
$fp = fopen("ex01.txt", "r") or die("Unable to open file!");
while(!feof($fp)) {
	$tmp = fgetc($fp);
	if ($tmp != ',')
		echo $tmp;
	else
		echo "\n";
}
echo "\n";
fclose($fp);
?>
