#include "PolarEngine.h"

GameObjectManager PolarEngine::_gameObjectManager;

void PolarEngine::Initialize() {
	//Attept to show splash

	//check for minimum requirements.

	_gameState = Initialized;

}

void PolarEngine::GameLoop() {
	// update all systems
	_gameObjectManager.Update(0); // change to tick later

								  // late update all systems
	_gameObjectManager.LateUpdate(0); // change to tick later
}

void PolarEngine::LevelLoaded() {
	_gameObjectManager.Awake();
	// awake other systems

	_gameObjectManager.Start();
	// start other systems
}

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

