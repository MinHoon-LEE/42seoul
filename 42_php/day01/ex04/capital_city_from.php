<?php
function capital_city_from($city)
{
	$states = [
		'Oregon' => 'OR',
		'Alabama' => 'AL',
		'New Jersey' => 'NJ',
		'Colorado' => 'CO',
	];
	$capitals = [
		'OR' => 'Salem',
		'AL' => 'Montgomery',
		'NJ' => 'trenton',
		'KS' => 'Topeka',
	];
	if (array_key_exists($city,$states))
		if(array_key_exists($states[$city],$capitals))
			return ($capitals[$states[$city]] . "\n");
		else
			return ("Unknown\n");	
	else
		return ("Unknown\n");
}
?>
