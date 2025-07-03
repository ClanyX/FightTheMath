#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <string>

/// <summary>
/// Game Object class
/// 
/// 1.Creating non functionality objects
/// 2.Rendering objects
/// </summary>

class GameObject
{
private:
	//Window object
	sf::RenderWindow& window;

	//Private variables
	sf::CircleShape circle;
	sf::RectangleShape line;

	//Private function
	void initObject();

public:
	sf::Text currentNumber;
	sf::Text finalNumber;

	//Construktor
    GameObject(sf::RenderWindow& window, const sf::Font& font) : window(window), currentNumber(font), finalNumber(font) {
		currentNumber.setFont(font);
		finalNumber.setFont(font);
		initObject();
	}

	//Function
	void draw() const;

	//strings
	void regenerateNumber();

	int getCurrentNumber();
	void setCurrentNumber(int label);

	int getFinalNumber();
	void setFinalNumber(int label);
};

