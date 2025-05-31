#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Button.h"

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

	sf::Font& font;
	sf::Texture& btnTextureN;
	sf::Texture& btnTextureO;
	sf::Texture& btnEquals;

	//Private function
	void initCalculator();
	void initButtons();

public:
	//Construktor
	Calculator(
		sf::RenderWindow& window,
		const sf::Texture& texture,
		sf::Font& font,
		sf::Texture& btnN,
		sf::Texture& btnO,
		sf::Texture& btnE
	) : window(window),calculator(texture),font(font), btnTextureN(btnN), btnTextureO(btnO), btnEquals(btnE) {


		initCalculator();
		initButtons();
	}

	//Function
	void draw() const;

	void updateEvent() const;
};

