#include "Calculator.h"

//Private function
void Calculator::initCalculator()
{
	this->calculator.setScale(
		sf::Vector2f(
			(window.getSize().x * 0.3f) / calculator.getTexture().getSize().x,
			(window.getSize().y * 0.8f) / calculator.getTexture().getSize().y
		)
	);
	auto bounds = calculator.getLocalBounds();
	this->calculator.setOrigin({ bounds.size.x / 2, bounds.size.y / 2 });
	auto size = window.getSize();
	this->calculator.setPosition({ static_cast<float>(size.x) / 4, static_cast<float>(size.y) / 2 });
}

void Calculator::initButtons()
{
	//Variables
	const sf::Vector2f start = { static_cast<float>(window.getSize().x) / 7, static_cast<float>(window.getSize().y) / 2 - 60};
	const sf::Vector2f spacing = { 15.f, 15.f };
	sf::Vector2f itemSize = { 55.f,55.f };
	const int col = 4;
	const int row = (15 + col - 1) / col;

	buttons[0] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "+", btnTextureO);
	buttons[1] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "1", btnTextureN);
	buttons[2] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "2", btnTextureN);
	buttons[3] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "3", btnTextureN);
	buttons[4] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "-", btnTextureO);
	buttons[5] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "4", btnTextureN);
	buttons[6] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "5", btnTextureN);
	buttons[7] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "6", btnTextureN);
	buttons[8] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "/", btnTextureO);
	buttons[9] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "7", btnTextureN);
	buttons[10] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "8", btnTextureN);
	buttons[11] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "9", btnTextureN);
	buttons[12] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "*", btnTextureO);
	buttons[13] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "0", btnEquals);
	buttons[14] = new Button(font, sf::Vector2f(110.f + spacing.x,55.f), sf::Vector2f(300.f, 50.f), "=", btnTextureO);

	for (size_t i = 0; i < 15; i++)
	{
		int colums = i % col;
		int rows = i / col;
		buttons[i]->setPosition(
			sf::Vector2f(
				start.x + colums * (itemSize.x + spacing.x),
				start.y + rows * (itemSize.y + spacing.y)
			)
		);
	}
}

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
	for (size_t i = 0; i < 15; i++)
	{
		buttons[i]->drawBtn(window);
	}
}

void Calculator::clickCheck(sf::Vector2f& mousePos) const
{
	for (size_t i = 0; i < 15; i++)
	{
		if (buttons[i]->isClicked(mousePos)) {
			std::cout << buttons[i]->label() << std::endl;
		}
	}
}
