#include "Sound.hpp"

Sound::Sound()
{
	winSoundBuffer.loadFromFile("Resources/Audio/Win.wav");
	winSound.setBuffer(winSoundBuffer);

	loseSoundBuffer.loadFromFile("Resources/Audio/Lose.wav");
	loseSound.setBuffer(loseSoundBuffer);
}

void Sound::GetWinSound()
{
	if (winSound.getStatus() != sf::Sound::Playing)
	{
		winSound.play();
	}
}

void Sound::GetLoseSound()
{
	if (loseSound.getStatus() != sf::Sound::Playing)
	{	
		loseSound.play();
	}
}