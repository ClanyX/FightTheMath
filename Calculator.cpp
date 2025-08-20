#include "Calculator.h"

#include <string>
#include <cctype>

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

bool isDigit(char ch) {
	return (ch >= '0' && ch <= '9');
}
bool isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
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
	buttons[13] = new Button(font, itemSize, sf::Vector2f(300.f, 50.f), "0", btnTextureN);
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

void Calculator::performCalculation()
{
	int result = 0;
	std::cout << "Number: " << firstNumber << " " << currentOperand << " " << secondNumber << " = ";

	switch (currentOperand) {
	case '+':
		result = firstNumber + secondNumber;
		break;
	case '-':
		result = firstNumber - secondNumber;
		break;
	case '*':
		result = firstNumber * secondNumber;
		break;
	case '/':
		if (secondNumber != 0) {
			result = firstNumber / secondNumber;
		}
		else {
			result = firstNumber;
		}
		break;
	default:
		break;
	}	
	gameObject.setCurrentNumber(result);
	std::cout << result << std::endl;
}

//Function
void Calculator::draw() const
{
	this->window.draw(calculator);
	for (int8_t i = 0; i < 15; i++)
	{
		buttons[i]->drawBtn(window);
	}
}

void Calculator::clickCheck(sf::Vector2f& mousePos)
{
	for (int8_t i = 0; i < 15; i++)
	{
		if (buttons[i]->isClicked(mousePos)) {
			proccesChar(this->buttons[i]->label().at(0));
		}
	}
}

void Calculator::proccesChar(char ch)
{
	firstNumber = gameObject.getCurrentNumber();
	switch (state) {
	case OPERAND_ENTERED:
		if (isOperator(ch)) {
			currentOperand = ch;
			state = INPUT_SECOND_NUMBER;
		}
		break;

	case INPUT_SECOND_NUMBER:
		if (isDigit(ch)) {
			currentString += ch;
		}
		else if (ch == '=') {
			if (currentString.empty()) {
				resetOperation();
				return;
			}
			secondNumber = std::stoi(currentString);
			performCalculation();
			state = RESULT_DISPLAY;
			resetOperation();
		}
		else if (isOperator(ch)) {
			if (currentString.empty()) {
				resetOperation();
				return;
			}
			secondNumber = std::stoi(currentString);
			performCalculation();
			currentOperand = ch;
			currentString.clear();
			state = OPERAND_ENTERED;
		}
		break;

	case RESULT_DISPLAY:
		resetOperation();
		proccesChar(ch);
		break;
	}
}

void Calculator::resetOperation()
{
	state = OPERAND_ENTERED;
	currentString.clear();
	firstNumber = 0;
	secondNumber = 0;
	currentOperand = '\0';
}
