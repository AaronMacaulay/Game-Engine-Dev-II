#pragma once

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "..\GameObjectManager.h"
#include "..\BaseComponent.h"
#include "SFML\Graphics\Transform.hpp"


#define X_AXIS sf::Vector2 (1,0)
#define Y_AXIS sf::Vector2 (0,1)


struct Vector2
{

	Vector2() : x(0.0f), y(0.0f){}
	Vector2(float _x, float _y) : x(_x), y(_y){}

	float x, y;
};

class Transform : public BaseComponent {
public:
	Transform() : m_Position(), m_Rotation(), m_Scale(1, 1) {}
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	bool SendMessage(BaseMessage* msg) { return false; }
	Vector2 m_Position;
	float m_Rotation;
	Vector2 m_Scale;

	sf::Transform transform;

};

#endif 