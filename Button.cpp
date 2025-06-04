#include "Button.h"

//Private functions
void Button::initButton(std::string label)
{
	//this->button.setFillColor(sf::Color::Green);
	this->button.setPosition({ 10.f,10.f });
	
	this->text.setString(label);
	this->text.setCharacterSize(35.f);
	this->text.setStyle(sf::Text::Bold);
	this->text.setFillColor(sf::Color::White);
	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(
		sf::Vector2f(
			textRect.position.x + textRect.size.x / 2.f,
			textRect.position.y + textRect.size.y / 2.f
		)
	);
	sf::Vector2f buttonPos = this->button.getPosition();
	sf::Vector2f buttonSize = this->button.getSize();
	this->text.setPosition(
		sf::Vector2f(
			buttonPos.x + buttonSize.x / 2.f,
			buttonPos.y + buttonSize.y / 2.f
		)
	);
}

//Functions
void Button::drawBtn(sf::RenderWindow& window) const
{
	window.draw(button);
	window.draw(text);
}
