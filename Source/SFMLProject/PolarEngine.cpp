#include "PolarEngine.h"


void PolarEngine::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Lions Arc");
	_gameState = PolarEngine::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

