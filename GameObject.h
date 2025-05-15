#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

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

	//Private init
	void initObject();

public:
	//Construktor
    GameObject(sf::RenderWindow& window) : window(window) {
		initObject();
	}

	//Functions
	void draw() const;
};

