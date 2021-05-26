<?php
function array2hash($arr)
{
	$n = 0;
	$new_arr = [];
	while ($arr[$n])
	{
		$new_arr[$arr[$n][1]] = $arr[$n][0];
		$n++;
	}
	return($new_arr);
}
?>
