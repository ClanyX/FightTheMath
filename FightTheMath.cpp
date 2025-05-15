#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

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

	GameObject gameObject(window);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear(sf::Color(220, 220, 220));
		gameObject.draw();
		window.display();
	}
}