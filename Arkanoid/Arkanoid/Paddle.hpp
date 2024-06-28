#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Paddle : public GameObject
{
private:
	float paddleSpeed = 0;

public:
	Paddle();

	void UpdatePaddle(float appWidth);
	void SetPaddlePosition(const sf::Vector2f& position);
	void SetPaddleSpeed(float speed);
	void MovePaddle(float speed, float positionY);

	float GetPaddleSpeed();
};