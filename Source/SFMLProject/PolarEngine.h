#pragma once
#define PolarEngine_h
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
	static void LevelLoaded();
	static void PushStateToStack(State::Ptr state);
	static void PopStateStack();
private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

public :static GameState _gameState;
	static GameObjectManager _gameObjectManager;
	static GameObject _gameObject;

};

