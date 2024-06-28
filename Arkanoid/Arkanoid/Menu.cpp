#include "Menu.hpp"

Menu::Menu()
{
	objectTexture.loadFromFile("Resources/Assets/Menu.png");
	objectSprite.setTexture(objectTexture);

	menuTextFont.loadFromFile("Resources/Font/Font.ttf");

	mainMenuText[0].setFont(menuTextFont);
	mainMenuText[0].setFillColor(sf::Color::Yellow);
	mainMenuText[0].setString("Play");
	mainMenuText[0].setCharacterSize(40.f);
	mainMenuText[0].setPosition(Constants::SCREEN_SIZE.x / 2.f - 50.f, Constants::SCREEN_SIZE.y / 4.f);

	mainMenuText[1].setFont(menuTextFont);
	mainMenuText[1].setFillColor(sf::Color::White);
	mainMenuText[1].setString("Exit");
	mainMenuText[1].setCharacterSize(40.f);
	mainMenuText[1].setPosition(Constants::SCREEN_SIZE.x / 2.f - 50.f, (Constants::SCREEN_SIZE.y / 4.f) * 2.3f);

	menuSelected = 0;


	gameOverMenuText[0].setFont(menuTextFont);
	gameOverMenuText[0].setFillColor(sf::Color::Yellow);
	gameOverMenuText[0].setString("Restart");
	gameOverMenuText[0].setCharacterSize(40.f);
	gameOverMenuText[0].setPosition(Constants::SCREEN_SIZE.x / 2.f - 80.f, Constants::SCREEN_SIZE.y / 4.f);

	gameOverMenuText[1].setFont(menuTextFont);
	gameOverMenuText[1].setFillColor(sf::Color::White);
	gameOverMenuText[1].setString("Exit");
	gameOverMenuText[1].setCharacterSize(40.f);
	gameOverMenuText[1].setPosition(Constants::SCREEN_SIZE.x / 2.f - 50.f, (Constants::SCREEN_SIZE.y / 4.f) * 2.3f);

	gameOverSelected = 0;
}

void Menu::MainMenuDraw(sf::RenderWindow& window)
{
	window.clear();

	window.draw(objectSprite);

	for (int i = 0; i < maxMenuOptions; i++)
	{
		window.draw(mainMenuText[i]);
	}

	window.display();
}

void Menu::GameOverMenuDraw(sf::RenderWindow& window)
{
	window.clear();

	window.draw(objectSprite);

	for (int i = 0; i < maxMenuOptions; i++)
	{
		window.draw(gameOverMenuText[i]);
	}

	window.display();
}

void Menu::MainMenuMove(const sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Down)
	{
		if (menuSelected + 1 <= maxMenuOptions)
		{
			mainMenuText[menuSelected].setFillColor(sf::Color::White);
			menuSelected++;

			if (menuSelected == maxMenuOptions)
			{
				menuSelected = 0;
			}

			mainMenuText[menuSelected].setFillColor(sf::Color::Yellow);
		}
	}

	else if (event.key.code == sf::Keyboard::Up)
	{
		if (menuSelected - 1 >= -1)
		{
			mainMenuText[menuSelected].setFillColor(sf::Color::White);
			menuSelected--;

			if (menuSelected == -1)
			{
				menuSelected = 1;
			}

			mainMenuText[menuSelected].setFillColor(sf::Color::Yellow);
		}
	}
}

void Menu::GameOverMenuMove(const sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Down)
	{
		if (gameOverSelected + 1 <= maxMenuOptions)
		{
			gameOverMenuText[gameOverSelected].setFillColor(sf::Color::White);
			gameOverSelected++;

			if (gameOverSelected == maxMenuOptions)
			{
				gameOverSelected = 0;
			}

			gameOverMenuText[gameOverSelected].setFillColor(sf::Color::Yellow);
		}
	}

	else if (event.key.code == sf::Keyboard::Up)
	{
		if (gameOverSelected - 1 >= -1)
		{
			gameOverMenuText[gameOverSelected].setFillColor(sf::Color::White);
			gameOverSelected--;

			if (gameOverSelected == -1)
			{
				gameOverSelected = 1;
			}

			gameOverMenuText[gameOverSelected].setFillColor(sf::Color::Yellow);
		}
	}
}

int Menu::GetMenuSelected()
{
	return menuSelected;
}

int Menu::GetGameOverSelected()
{
	return gameOverSelected;
}