#include "GameObject.h"

//Private function
void GameObject::initObject()
{
	//Right-Bottom circle
	this->circle.setRadius(this->window.getView().getSize().x / 4);
	this->circle.setFillColor(sf::Color(50,50,50));
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

	//CurrentNumber
	this->currentNumber.setString("0");
	this->currentNumber.setCharacterSize(120.f);
	this->currentNumber.setStyle(sf::Text::Bold);
	this->currentNumber.setFillColor(sf::Color::White);
	this->currentNumber.setPosition(
		sf::Vector2f(
			window.getSize().x - 200,
			430.f
		)
	);

	//FinalNumber
	this->finalNumber.setString("0");
	this->finalNumber.setCharacterSize(120.f);
	this->finalNumber.setStyle(sf::Text::Bold);
	this->finalNumber.setFillColor(sf::Color::White);
	this->finalNumber.setPosition(
		sf::Vector2f(
			window.getSize().x - 200,
			575.f
		)
	);
}

//Function
void GameObject::draw() const
{
	this->window.draw(circle);
	this->window.draw(line);
	this->window.draw(currentNumber);
	this->window.draw(finalNumber);
}

void GameObject::regenerateNumber()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(1, 100);

	setCurrentNumber(distribution(generator));
	setFinalNumber(distribution(generator));
}

int GameObject::getCurrentNumber()
{
	std::string convert = currentNumber.getString();
	return std::stoi(convert);
}

void GameObject::setCurrentNumber(int label)
{
	currentNumber.setString(std::to_string(label));
}

int  GameObject::getFinalNumber()
{
	std::string convert = finalNumber.getString();
	return std::stoi(convert);
}

void GameObject::setFinalNumber(int label)
{
	finalNumber.setString(std::to_string(label));
}
