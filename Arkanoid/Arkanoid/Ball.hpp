#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Ball : public GameObject
{
private:
    sf::Vector2f ballPosition;
    sf::Vector2f ballDirection;

public:
    Ball();

    void SetBallPosition(const sf::Vector2f& position);
    void SetBallDirection(const sf::Vector2f& direction);
    void UpdateBall(sf::Vector2f size);

    sf::Vector2f GetBallDirection() const;
};