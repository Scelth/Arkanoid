#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "GameObject.hpp"

class Menu : public GameObject
{
private:
	static const int maxMenuOptions = 2;

	int menuSelected;
	int gameOverSelected;

	sf::Font menuTextFont;

	sf::Text mainMenuText[maxMenuOptions];
	sf::Text gameOverMenuText[maxMenuOptions];

public:
	Menu();

	void MainMenuDraw(sf::RenderWindow& window);
	void GameOverMenuDraw(sf::RenderWindow& window);
	void MainMenuMove(const sf::Event& event);
	void GameOverMenuMove(const sf::Event& event);

	int GetMenuSelected();
	int GetGameOverSelected();
};