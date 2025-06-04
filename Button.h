#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
///	Class that representing the buttons.
/// </summary>

class Button
{
private:
	// Private variables
	sf::RectangleShape button{ sf::Vector2f(55.f, 55.f) };
	sf::Text text;

	// Private functions
	void initButton(std::string label);

public:
	//Constructor
	Button(
		const sf::Texture& btntexture,
		const sf::Font& font,
		const std::string& label
	) : text(font)
	{
		button.setTexture(&btntexture);
		initButton(label);
	}
	
	//Functions
	void drawBtn(sf::RenderWindow& window) const;
};

