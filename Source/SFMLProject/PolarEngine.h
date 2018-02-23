#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"

class PolarEngine
{
public:
	static void Start();
	static void Initialize();

private:
	static bool IsExiting();
	static void GameLoop();
	static void LevelLoaded();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

	static GameObjectManager _gameObjectManager;
};

