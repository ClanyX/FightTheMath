#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Calculator.h"

int main() {
	sf::RenderWindow window(sf::VideoMode({ 1280,720 }), "Fight The Math", sf::Style::Close, sf::State::Windowed);
	window.setFramerateLimit(60);
	sf::Vector2u screenResolution = sf::VideoMode::getDesktopMode().size;
	window.setPosition(
		sf::Vector2i(
			(screenResolution.x - window.getSize().x) / 2,
			(screenResolution.y - window.getSize().y - 100) / 2
		)
	);

	//Textures
	sf::Texture calTexture;
	if (!calTexture.loadFromFile("assets/Calculator.png")) std::cout << "Texture not found (calculator)" << std::endl;

	//Font
	sf::Font font;
	if (!font.openFromFile("assets/Roboto.ttf")) std::cout << "Font not found" << std::endl;

	GameObject gameObject(window);

	Calculator calculator(window, calTexture, font);


	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

		}

		window.clear(sf::Color(220, 220, 220));
		gameObject.draw();
		calculator.draw();
		window.display();
	}
}