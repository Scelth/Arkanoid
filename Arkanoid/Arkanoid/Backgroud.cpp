#include "Backgroud.hpp"

Backgroud::Backgroud()
{
	objectTexture.loadFromFile("Resources/Assets/Background.jpg");
	objectSprite.setTexture(objectTexture);
}