#pragma once

#define PolarEngine_h
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <iostream>
#include "GameObjectManager.h"

class SplashScreen
{
public: 
	void  Show(sf::RenderWindow& window);
};