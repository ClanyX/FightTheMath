#include "Calculator.h"

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
	btn1 = new Button(font, sf::Vector2f(55.f, 55.f), sf::Vector2f(30.f, 50.f), "4", btnTextureO);
	btn2 = new Button(font, sf::Vector2f(55.f, 55.f), sf::Vector2f(300.f, 50.f), "+", btnTextureN);
	//this->buttons[0] = Button(btnTextureN, font, "5");
}

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
	this->btn1->drawBtn(window);
	this->btn2->drawBtn(window);
}

void Calculator::clickCheck(sf::Vector2f& mousePos) const
{
	//need to add array research for clicked button
	if (this->btn1->isClicked(mousePos)) {
		std::cout << "Clicked" << std::endl;
	}
	if (this->btn2->isClicked(mousePos)) {
		std::cout << "Clicked btn2" << std::endl;
	}
}
