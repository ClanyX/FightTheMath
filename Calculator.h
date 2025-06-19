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
	sf::Texture btnTextureN;
	sf::Texture btnTextureO;
	sf::Texture btnEquals;

	//Buttons
	Button* btn1;
	Button* btn2;
	//Button buttons[14];

	//Private function
	void initCalculator();
	void initButtons();

public:
	//Construktor
	Calculator(
		sf::RenderWindow& window,
		const sf::Texture& texture,
		sf::Font& font
	) : window(window), calculator(texture), font(font)
	{
		if (!btnTextureN.loadFromFile("assets/ButtonsN.png")) std::cout << "Texture not found (buttons N)" << std::endl;
		if (!btnTextureO.loadFromFile("assets/ButtonsO.png")) std::cout << "Texture not found (buttons O)" << std::endl;
		if (!btnEquals.loadFromFile("assets/ButtonsEquals.png")) std::cout << "Texture not found (buttons equals)" << std::endl;
		initCalculator();
		initButtons();
	}

	//Function
	void draw() const;

	void clickCheck(sf::Vector2f& mousePos) const;
};
