#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "GameObject.hpp"

class Block : public GameObject
{
private:
	std::list<sf::Sprite> blockSprites;

public:
	Block();

	void Draw(sf::RenderWindow& window) override;
	void SetBlocks();

	std::list<sf::Sprite>& GetBlockSprites();
};