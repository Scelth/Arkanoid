#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
private:
	sf::Texture paddleTexture;
	sf::Sprite paddleSprite;
	float paddleSpeed = 0;

public:
	Paddle();

	void DrawPaddle(sf::RenderWindow& window);
	void UpdatePaddle(float appWidth);
	void SetPaddlePosition(const sf::Vector2f& position);
	void SetPaddleSpeed(float speed);
	void MovePaddle(float speed, float positionY);

	float GetPaddleSpeed();

	sf::FloatRect GetPaddleRect();
	sf::Vector2f GetPaddlePosition();
};