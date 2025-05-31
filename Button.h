#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
/// Tøída reprezentující tlaèítko, které je spojeno s oknem sf::RenderWindow.
/// </summary>

class Button
{
private:
	//Windows object
	sf::RenderWindow& window;

	//Private variables

	//Private functions

public:
	//Constructor
	Button(sf::RenderWindow& window) : window(window) {

	}

	//Functions
};

