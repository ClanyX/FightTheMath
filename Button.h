#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
///	Class that representing the buttons.
/// </summary>

class Button
{
private:
	//Windows object
	sf::RenderWindow& window;

	//Private variables
	sf::RectangleShape button;
	sf::Text text;

	//Private functions
	void initButton(std::string label);

public:
	//Constructor
	Button(sf::RenderWindow& window, const sf::Texture& btntexture, const sf::Font& font, const std::string& label) : window(window), text(font) {
		initButton(label);
	}

	//Functions
	void drawBtn() const;
};

