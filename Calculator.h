#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
/// Calculator class
/// 
/// 1. Create calculator sprite
/// </summary>

class Calculator
{
private:
	//Window object
	sf::RenderWindow& window;

	//Private variables
	sf::Sprite calculator;

	//Private function
	void initCalculator();
public:
	//Construktor
	Calculator(sf::RenderWindow& window, const sf::Texture& texture) : window(window),calculator(texture) {
		initCalculator();
	}

	//Function
	void draw() const;
};

