#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/// <summary>
///	Class that representing the buttons.
/// Parametrs
/// Font, Size, Position, Label, Texture
/// </summary>

class Button
{
private:
	// Private variables
	sf::RectangleShape button;
	sf::Text text;

	// Private functions
	void initButton(std::string label);

public:
	//Constructor
	Button(
		const sf::Font& font,
		const sf::Vector2f& size,
		const sf::Vector2f& position,
		const std::string& label,
		const sf::Texture& btntexture
	) : text(font), button(size)
	{
		button.setTexture(&btntexture);
		button.setPosition(position);
		text.setFont(font);
		initButton(label);
	}
	
	//Functions
	void drawBtn(sf::RenderWindow& window) const;
};

