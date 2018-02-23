#pragma once
#ifndef PolarEngine_h
#define PolarEngine_h
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <iostream>
#include "GameObjectManager.h"


class PolarEngine
{
public:
	static void Start();
	static void Initialize();

private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

	static GameState _gameState;
	static GameObjectManager _gameObjectManager;
	static sf::RenderWindow _mainWindow;
};

