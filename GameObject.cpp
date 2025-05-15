#include "GameObject.h"

void GameObject::initObject()
{
	//Right-Bottom circle
	this->circle.setRadius(this->window.getView().getSize().x / 4);
	this->circle.setFillColor(sf::Color::Blue);
	this->circle.setPosition(
		sf::Vector2f(
			this->window.getView().getSize().x - circle.getRadius() - circle.getRadius() / 10,
			this->window.getView().getSize().y - circle.getRadius() - circle.getRadius() / 10
		)
	);

	//Line
	this->line.setSize({ this->circle.getRadius(), 4.f });
	this->line.setPosition(this->circle.getPosition());
	this->line.move(sf::Vector2f(
		circle.getRadius() / 6,
		circle.getRadius() / 1.5
	));
}

//Functions
void GameObject::draw() const
{
	this->window.draw(circle);
	this->window.draw(line);
}
