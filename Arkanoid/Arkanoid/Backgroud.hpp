#pragma once
#include <SFML/Graphics.hpp>

class Backgroud
{
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

public:
	Backgroud();
	void DrawBackground(sf::RenderWindow& window);
};