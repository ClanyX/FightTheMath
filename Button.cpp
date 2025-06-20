#include "Button.h"

//Private functions
void Button::initButton(std::string label)
{
	this->btnLabel = label;

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
void Button::drawBtn(sf::RenderWindow& window)
{
	window.draw(this->button);
	window.draw(this->text);
}

bool Button::isClicked(sf::Vector2f& mousePos)
{
	if (this->button.getGlobalBounds().contains(mousePos)) {
		return true;
	}
	return false;
}

void Button::setPosition(sf::Vector2f position)
{
	this->button.setPosition(position);
	initButton(label());
}

std::string Button::label() const
{
	return btnLabel;
}
