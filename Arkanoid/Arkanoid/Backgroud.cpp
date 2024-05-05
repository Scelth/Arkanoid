#include "Backgroud.hpp"

Backgroud::Backgroud()
{
	backgroundTexture.loadFromFile("Resources/Assets/Background.jpg");
	backgroundSprite.setTexture(backgroundTexture);
}

void Backgroud::DrawBackground(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}