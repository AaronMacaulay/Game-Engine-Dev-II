#pragma once
#define PolarEngine_h
#define PolarEngine_h
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
<<<<<<< HEAD
#include "GameObjectManager.h"
=======
#include <stdio.h>
#include <iostream>
#include "GameObjectManager.h"

>>>>>>> master

class PolarEngine
{
public:
	static void Start();
	static void Initialize();
	static void LevelLoaded();

private:
	static bool IsExiting();
	static void GameLoop();
	static void LevelLoaded();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

public :static GameState _gameState;
	static GameObjectManager _gameObjectManager;
	static GameObject _gameObject;
	static sf::RenderWindow _mainWindow;

	static GameObjectManager _gameObjectManager;
};

