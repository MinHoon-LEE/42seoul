<?php
class Text{
	public $array = array(); 
	public function render($string)
    {
        return ("<p>".$string."</p>");
    }
	public function __construct($text_arr)
	{
		$i = 0;
		while ($text_arr[$i])
		{
			$this->array[$i] = $this->render($text_arr[$i]);
			$i++;
		}
	}
	public function add_string($string)
	{
		array_push($this->array,$this->render($string));
	}
}	
?>
