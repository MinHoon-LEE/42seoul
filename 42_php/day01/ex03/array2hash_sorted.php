<?php
function array2hash($arr)
{
	$n = 0;
	$new_arr = [];
	while ($arr[$n])
	{
		$new_arr[$arr[$n][0]] = $arr[$n][1];
		$n++;
	}
	return($new_arr);
}
function array2hash_sorted($arr)
{
	$new_arr = array2hash($arr);
	krsort($new_arr);
	return ($new_arr);
}
?>
