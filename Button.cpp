#include "Button.h"

//Private functions
void Button::initButton(std::string label)
{
	this->button.setSize({ 40.f,20.f });
	this->button.setFillColor(sf::Color::Green);
	this->button.setPosition({ 0.f,0.f });
	
	this->text.setString(label);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition({ 0.f,0.f });
	sf::Vector2f ori = this->text.getOrigin();
	std::cout << ori.x << " - " << ori.y << std::endl;
}

//Functions
void Button::drawBtn() const
{
	this->window.draw(this->button);
	this->window.draw(this->text);
}
