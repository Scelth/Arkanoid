#include "Paddle.hpp"

Paddle::Paddle()
{
	paddleTexture.loadFromFile("Resources/Assets/Paddle.png");
	paddleSprite.setTexture(paddleTexture);
	SetPaddleSpeed(0);
}

void Paddle::UpdatePaddle(float appWidth)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
        (GetPaddlePosition().x < appWidth - GetPaddleRect().width))
    {
        SetPaddleSpeed(6.f);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
        (GetPaddlePosition().x > 0.f))
    {
        SetPaddleSpeed(-6.f);
    }

    if (GetPaddleSpeed() != 0.f)
    {
        MovePaddle(GetPaddleSpeed(), 0.f);
    }
}

void Paddle::DrawPaddle(sf::RenderWindow& window)
{
	window.draw(paddleSprite);
}

void Paddle::SetPaddlePosition(const sf::Vector2f& position)
{
	paddleSprite.setPosition((position.x - GetPaddleRect().width) / 2, position.y - GetPaddleRect().height);
}

void Paddle::SetPaddleSpeed(float speed)
{
	paddleSpeed = speed;
}

void Paddle::MovePaddle(float speed, float positionY)
{
	paddleSprite.move(speed, positionY);
}

sf::FloatRect Paddle::GetPaddleRect()
{
	return paddleSprite.getGlobalBounds();
}

sf::Vector2f Paddle::GetPaddlePosition()
{
	return paddleSprite.getPosition();
}

float Paddle::GetPaddleSpeed()
{
	return paddleSpeed;
}