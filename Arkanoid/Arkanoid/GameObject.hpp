#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
	sf::Texture objectTexture;
	sf::Sprite objectSprite;

public:
	virtual void Draw(sf::RenderWindow& window);
	const sf::Vector2f& GetObjectPosition();
	const sf::FloatRect& GetObjectRect();
	virtual ~GameObject() = default;
};