#include "Paddle.hpp"

Paddle::Paddle()
{
	objectTexture.loadFromFile("Resources/Assets/Paddle.png");
	objectSprite.setTexture(objectTexture);
	SetPaddleSpeed(0);
}

void Paddle::UpdatePaddle(float appWidth)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
        (GetObjectPosition().x < appWidth - GetObjectRect().width))
    {
        SetPaddleSpeed(6.f);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
        (GetObjectPosition().x > 0.f))
    {
        SetPaddleSpeed(-6.f);
    }

    if (GetPaddleSpeed() != 0.f)
    {
        MovePaddle(GetPaddleSpeed(), 0.f);
    }
}

void Paddle::SetPaddlePosition(const sf::Vector2f& position)
{
	objectSprite.setPosition((position.x - GetObjectRect().width) / 2, position.y - GetObjectRect().height);
}

void Paddle::SetPaddleSpeed(float speed)
{
	paddleSpeed = speed;
}

void Paddle::MovePaddle(float speed, float positionY)
{
	objectSprite.move(speed, positionY);
}

float Paddle::GetPaddleSpeed()
{
	return paddleSpeed;
}