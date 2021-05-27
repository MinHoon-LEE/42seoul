<?php
include 'MyException.php';
class Elem
{
	private $tag = array("meta", "img", "hr", "br", "html", "head",
		"body", "title", "h1", "h2", "h3", "h4", "h5", "h6", "p", "span",
		"div", "tr", "th", "td", "ul", "ol", "li");
	private $single_tag = array("meta", "hr", "br", "img");
	private $once_tag = array("body", "html", "title", "meta");
	private $Start;
	private $Middle;
	private $End;
	public $head_tag = array();
	public $middle_tag = array();
	public $end_tag = array();
	public function __construct(...$string)
	{
		if (in_array($string[0],$this->tag))
		{
			array_push($this->head_tag, $string[0]);
			$s = $string[0] . "_";
			$this->Start = "<".$string[0];
			if (in_array($string[0],$this->single_tag) == 0)
			{
				array_push($this->end_tag, $s);
				$this->End = "</".$string[0].">";
			}
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
		$j = 0;
		array_push($this->middle_tag, $Element->head_tag[0]);
		while ($Element->middle_tag[$j])
		{
			array_push($this->middle_tag, $Element->middle_tag[$j]);
			$j++;
		}
		if ($Element->end_tag[0])
			array_push($this->middle_tag, $Element->end_tag[0]);
		$this->tag_array = $tmp;
		$this->Middle = $this->Middle.$Element->getHTML();
	}
	public function getHTML()
	{
		return $this->Start . $this->Middle . $this->End;
	}
	public function validPage()
	{
		$i = 0;
		$title_flag = 0;
		$meta_flag = 0;
		$ol_flag = 0;
		$ul_flag = 0;
		$tr_flag = 0;
		$table_flag = 0;
		if ($this->head_tag[0] != 'html')
			return False;
		while ($this->middle_tag[$i])
		{
			if ($i == 0)
				if ($this->middle_tag[$i] != 'head')
					return False;
			if ($i == 1 or $i == 2 or $i == 3)
			{
				if ($this->middle_tag[$i] == 'title')
					$title_flag = 1;
				if ($this->middle_tag[$i] == 'meta')
					$meta_flag = 1;
			}
			if ($i ==4 and !($title_flag == 1 and $meta_flag == 1))
					return False;
			if ($i == 5)
				if ($this->middle_tag[$i] != 'body')
					return False;
			if ($i >= 6)
			{
				if (in_array($this->middle_tag[$i],$this->once_tag))
					return False;
				if ($this->middle_tag[$i] == 'p')
				{
					if ($this->middle_tag[$i+1] =='p_')
						$i++;
					else
						return False;
				}
				if ($this->middle_tag[$i] == 'ol')
					$ol_flag = 1;
				if ($this->middle_tag[$i] == 'ul')
					$ul_flag = 1;
				if ($this->middle_tag[$i] == 'table')
					$table_flag = 1;
				if ($this->middle_tag[$i] == 'tr')
					$tr_flag = 1;
				if ($this->middle_tag[$i] == 'ol_')
					$ol_flag = 0;
				if ($this->middle_tag[$i] == 'ul_')
					$ul_flag = 0;
				if ($this->middle_tag[$i] == 'tr_')
					$tr_flag = 0;
				if ($this->middle_tag[$i] == 'table_')
					$table_flag = 0;
				if ($ol_flag == 1)
				{
					if ($this->middle_tag[$i] != 'li' and  $this->middle_tag[$i] != 'li_')
						return False;
				}
				if ($ul_flag == 1)
				{
					if ($this->middle_tag[$i] != 'li' and  $this->middle_tag[$i] != 'li_')
						return False;
				}
				if ($table_flag == 1)
				{
					if($tr_flag == 0)
					{
						if($this->middle_tag[$i] != 'tr')
							return False;
					}
					if($tr_flag == 1)
					{
						if($this->middle_tag[$i] != 'th' and $this->middle_tag[$i] != 'td')
							return False;
					}
				}
			}
			$i++;
		}
		return True;
	}
}
?>
