#include "Calculator.h"
#include "Button.h"

//Private function
void Calculator::initCalculator()
{
	this->calculator.setScale(
		sf::Vector2f(
			(window.getSize().x * 0.3f) / calculator.getTexture().getSize().x,
			(window.getSize().y * 0.8f) / calculator.getTexture().getSize().y
		)
	);
	auto bounds = calculator.getLocalBounds();
	this->calculator.setOrigin({ bounds.size.x / 2, bounds.size.y / 2 });
	auto size = window.getSize();
	this->calculator.setPosition({ static_cast<float>(size.x) / 4, static_cast<float>(size.y) / 2 });
}

void Calculator::initButtons()
{
	Button btn1(window, btnTextureN, font, "5");
	btn1.drawBtn();
}

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
}

void Calculator::updateEvent() const
{
}
