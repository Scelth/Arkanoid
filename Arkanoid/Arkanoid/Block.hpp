#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Block
{
private:
	sf::Texture blockTexture;
	std::vector<sf::Texture> blockTextures;
	std::list<sf::Sprite> blockSprites;

public:
	Block();

	void DrawBlock(sf::RenderWindow& window);
	void SetBlocks();

	std::list<sf::Sprite>& GetBlockSprites();
};