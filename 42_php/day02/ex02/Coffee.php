<?php
include 'HotBeverage.php';
class Coffee extends HotBeverage
{
	private $description;
	private $comment;
	public function __construct($name, $price, $resistance, $description, $comment)
	{
		parent::__construct($name, $price, $resistance);
		$this->description = $description;
		$this->comment = $comment;
	}
	public function getdescription() {
        return $this->description;
	}
	public function getcomment() {
        return $this->comment;
	}
}

?>
