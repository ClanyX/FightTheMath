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

	//States
	enum CalculatorState {
		INPUT_FIRST_NUMBER,
		OPERAND_ENTERED,
		INPUT_SECOND_NUMBER,
		RESULT_DISPLAY
	};

	CalculatorState state;
	int firstNumber = 0;
	int secondNumber = 0;
	char currentOperand = '\0';
	std::string currentString;

	sf::Font& font;
	sf::Texture btnTextureN;
	sf::Texture btnTextureO;
	sf::Texture btnEquals;

	//Buttons
	Button* buttons[14];

	//Private function
	void initCalculator();
	void initButtons();
	void performCalculation();

public:
	//Construktor
	Calculator(
		sf::RenderWindow& window,
		const sf::Texture& texture,
		sf::Font& font
	) : window(window), calculator(texture), font(font), state(INPUT_FIRST_NUMBER)
	{
		if (!btnTextureN.loadFromFile("assets/ButtonsN.png")) std::cout << "Texture not found (buttons N)" << std::endl;
		if (!btnTextureO.loadFromFile("assets/ButtonsO.png")) std::cout << "Texture not found (buttons O)" << std::endl;
		if (!btnEquals.loadFromFile("assets/ButtonsEquals.png")) std::cout << "Texture not found (buttons equals)" << std::endl;
		initCalculator();
		initButtons();
		currentString.reserve(30);
	}

	//Function
	void draw() const;

	void clickCheck(sf::Vector2f& mousePos);

	void proccesChar(char ch);

	void resetOperation();
};
