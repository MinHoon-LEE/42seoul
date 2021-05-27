<?php
class HotBeverage
{
	private $name;
	private $price;
	private $resistance;

	public function __construct($name, $price, $resistance)
	{
		$this->name = $name;
		$this->price = $price;
		$this->resistance = $resistance;
	}
	public function getname() {
        return $this->name;
	}
	public function getprice() {
        return $this->price;
	}
	public function getresistance() {
        return $this->resistance;
    }
}
?>
