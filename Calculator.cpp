#include "Calculator.h"

//Private function
void Calculator::initVariables()
{
	sf::Texture btnTextureN;
	if (!btnTextureN.loadFromFile("assets/ButtonsN.png")) std::cout << "Texture not found (buttons N)" << std::endl;

	sf::Texture btnTextureO;
	if (!btnTextureN.loadFromFile("assets/ButtonsO.png")) std::cout << "Texture not found (buttons O)" << std::endl;

	sf::Texture btnEquals;
	if (!btnTextureN.loadFromFile("assets/ButtonsEquals.png")) std::cout << "Texture not found (buttons equals)" << std::endl;
}

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

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
}
