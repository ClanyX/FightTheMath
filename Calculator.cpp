#include "Calculator.h"

//Private function
void Calculator::initCalculator()
{
	this->calculator.setScale({ 1.3,1.3 });
	this->calculator.setPosition(
		sf::Vector2f(
			400.f,
			300.f
		)
	);
}

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
}
