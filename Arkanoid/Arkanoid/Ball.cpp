#include "Ball.hpp"

Ball::Ball()
{
    objectTexture.loadFromFile("Resources/Assets/Ball.png");
    objectSprite.setTexture(objectTexture);
}

void Ball::UpdateBall(sf::Vector2f size)
{
    if (ballPosition.x <= 0)
    {
        ballDirection.x = -ballDirection.x;
        ballPosition.x = 0;
    }
    
    if (ballPosition.x >= size.x - GetObjectRect().width)
    {
        ballDirection.x = -ballDirection.x;
        ballPosition.x = size.x - GetObjectRect().width;
    }

    if (ballPosition.y < 0)
    {
        ballDirection.y = -ballDirection.y;
        ballPosition.y = 0;
    }
}

void Ball::SetBallPosition(const sf::Vector2f& position)
{
    ballPosition = position;
	objectSprite.setPosition(ballPosition);
}

void Ball::SetBallDirection(const sf::Vector2f& direction)
{
    ballDirection = direction;
}

sf::Vector2f Ball::GetBallDirection() const
{
    return ballDirection;
}