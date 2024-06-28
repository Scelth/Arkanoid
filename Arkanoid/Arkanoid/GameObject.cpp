#include "GameObject.hpp"

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(objectSprite);
}

const sf::Vector2f& GameObject::GetObjectPosition()
{
	return objectSprite.getPosition();
}

const sf::FloatRect& GameObject::GetObjectRect()
{
	return objectSprite.getGlobalBounds();
}