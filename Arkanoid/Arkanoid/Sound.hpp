#pragma once
#include <SFML/Audio.hpp>

class Sound
{
private:
	sf::SoundBuffer winSoundBuffer;
	sf::Sound winSound;

	sf::SoundBuffer loseSoundBuffer;
	sf::Sound loseSound;

public:
	Sound();

	void GetWinSound();
	void GetLoseSound();
};