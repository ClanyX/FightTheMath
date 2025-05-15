#include "Calculator.h"

//Private function
void Calculator::initCalculator()
{
	this->calculator.setScale({ 1.3,1.3 });
}

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
}
