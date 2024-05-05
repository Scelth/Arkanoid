#include "Ball.hpp"

Ball::Ball()
{
	ballTexture.loadFromFile("Resources/Assets/Ball.png");
	ballSprite.setTexture(ballTexture);
}

void Ball::UpdateBall(sf::Vector2f size)
{
    if (ballPosition.x <= 0)
    {
        ballDirection.x = -ballDirection.x;
        ballPosition.x = 0;
    }

    if (ballPosition.x >= size.x - GetBallRect().width)
    {
        ballDirection.x = -ballDirection.x;
        ballPosition.x = size.x - GetBallRect().width;
    }

    if (ballPosition.y < 0)
    {
        ballDirection.y = -ballDirection.y;
        ballPosition.y = 0;
    }
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	window.draw(ballSprite);
}

void Ball::SetBallPosition(const sf::Vector2f& position)
{
    ballPosition = position;
	ballSprite.setPosition(ballPosition);
}

void Ball::SetBallDirection(const sf::Vector2f& direction)
{
    ballDirection = direction;
}

sf::FloatRect Ball::GetBallRect()
{
	return ballSprite.getGlobalBounds();
}

sf::Vector2f Ball::GetBallPosition() const
{
    return ballPosition;
}

sf::Vector2f Ball::GetBallDirection() const
{
    return ballDirection;
}