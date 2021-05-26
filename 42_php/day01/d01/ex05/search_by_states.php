<?php
function search_by_states($string)
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
	$arr = explode(", ",$string);
	foreach($arr as $var)
	{
	if (array_key_exists($var,$states))
		if(array_key_exists($states[$var],$capitals))
			echo ($capitals[$states[$var]] . " is the capital of " . $var . ".\n");
		else
		{
			$key = array_search($var,$capitals);
			if($key != NULL)
			{
				$key2 = array_search($key,$states);
				if ($key2 != NULL)
				{
					echo ($var . " is the capital of " . $key2 . ".\n");
				}
				else
					echo ($var . " is neither a capital nor a state.\n");
			}
			else
				echo ($var . " is neither a capital nor a state.\n");
		}
	else
	{
		$key = array_search($var,$capitals);
            if($key != NULL)
            {
                $key2 = array_search($key,$states);
                if ($key2 != NULL)
                {
                    echo ($var . " is the capital of " . $key2 . ".\n");
                }
                else
                    echo ($var . " is neither a capital nor a state.\n");
			}
			else
				echo ($var . " is neither a capital nor a state.\n");
	}
	}
}
?>
