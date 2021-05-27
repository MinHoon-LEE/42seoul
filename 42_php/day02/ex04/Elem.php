<?php
include 'MyException.php';
class Elem
{
	private $tag = array("meta", "img", "hr", "br", "html", "head",
		"body", "title", "h1", "h2", "h3", "h4", "h5", "h6", "p", "span",
		"div", "tr", "th", "td", "ul", "ol", "li");
	private $Start;
	private $Middle;
	private $End;
	public function __construct(...$string)
	{
		if (in_array($string[0],$this->tag))
		{
			$this->Start = "<".$string[0];
			$this->End = "</".$string[0].">";
			if (func_num_args() >= 2)
			{
				$this->Middle = $string[1];
				if (func_num_args() >=3)
				{
					$array = array_keys($string[2]);
					$i = 0;
					while ($array[$i])
					{
						$this->Start = $this->Start." ".$array[$i]."=\"".$string[2][$array[$i]]."\"";
						$i++;
					}
				}
			}
			$this->Start = $this->Start.">";
		}
		else
			throw new MyException("Ivalid Tag\n");
	}
	public function pushElement(Elem $Element)
	{
		$this->Middle = $this->Middle.$Element->getHTML();
	}
	public function getHTML()
	{
		return $this->Start . $this->Middle . $this->End;
	}
}
?>
