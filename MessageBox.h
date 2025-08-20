#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class MessageBox
{
private:

public:
	MessageBox(std::string title) {
		sf::RenderWindow window(sf::VideoMode({ 320,180 }), title, sf::Style::Close, sf::State::Windowed);

		while (window.isOpen()) {
			while (const std::optional event = window.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
					window.close();
			}

			window.clear(sf::Color(220, 220, 220));
			window.display();
		}
	}

};

