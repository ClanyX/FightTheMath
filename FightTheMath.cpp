#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode({ 1280,720 }), "Fight The Math", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Vector2u screenResolution = sf::VideoMode::getDesktopMode().size;
	window.setPosition(
		sf::Vector2i(
			(screenResolution.x - window.getSize().x) / 2,
			(screenResolution.y - window.getSize().y - 100) / 2
		)
	);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent())
		{
			if (event->is < sf::Event::Closed>())
				window.close();
		}

		window.clear(sf::Color(220, 220, 220));
		window.display();
	}
}