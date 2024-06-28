#include "Block.hpp"
#include "Constants.hpp"

Block::Block()
{
	objectTexture.loadFromFile("Resources/Assets/Block.png");
}

void Block::Draw(sf::RenderWindow& window)
{
    for (auto& block : blockSprites)
    {
        window.draw(block);
    }
} 

void Block::SetBlocks()
{
    std::list<sf::Sprite> blocks;

    for (int i = 1; i <= Constants::BLOCKS_COUNT.x; i++)
    {
        for (int j = 1; j <= Constants::BLOCKS_COUNT.y; j++)
        {
            sf::Sprite block;
            block.setTexture(objectTexture);
            block.setPosition(i * (objectTexture.getSize().x + 4), 10 + j * (objectTexture.getSize().y + 4));
            blocks.push_back(block);
        }
    }

    blockSprites = blocks;
}

std::list<sf::Sprite>& Block::GetBlockSprites()
{
    return blockSprites;
}