#pragma once

#define PolarEngine_h
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <iostream>
#include "GameObjectManager.h"
#include <SFML/Audio.hpp>

class SplashScreen
{
public: 
	void  Show(sf::RenderWindow& window);
};