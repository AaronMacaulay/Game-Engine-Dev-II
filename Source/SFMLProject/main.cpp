#include "PolarEngine.h"
#include "stdlib.h"
#include <iostream>
#include <SFML/Audio.hpp>


int main(int argc, char** argv)
{
	PolarEngine::Initialize();
	PolarEngine::Start();

	sf::Music music;
	if (!music.openFromFile("gamemusic.wav"))
	{
		return -1;
	}
	music.play();

	
}