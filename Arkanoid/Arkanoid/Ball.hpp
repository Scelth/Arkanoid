#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::Texture ballTexture;
    sf::Sprite ballSprite;

    sf::Vector2f ballPosition;
    sf::Vector2f ballDirection;

public:
    Ball();

    void DrawBall(sf::RenderWindow& window);
    void SetBallPosition(const sf::Vector2f& position);
    void SetBallDirection(const sf::Vector2f& direction);
    void UpdateBall(sf::Vector2f size);

    sf::FloatRect GetBallRect();
    sf::Vector2f GetBallPosition() const;
    sf::Vector2f GetBallDirection() const;
};