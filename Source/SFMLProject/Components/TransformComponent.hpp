#pragma once

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "..\GameObjectManager.h"
#include "BaseComponent.hpp"
#include <SFML\Main.hpp>
#include "SFML\Graphics\Transform.hpp"
#include "SFML\OpenGL.hpp"

#define X_AXIS sf::vector3(1,0,0)
#define Y_AXIS sf::vector3(0,1,0)
#define Z_AXIS sf::vector3(0,0,1)

struct Vector3
{
public:
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	float x, y, z;
};

class Transform : public BaseComponent {
public:
	Transform() : m_Position(), m_Rotation(), m_Scale(1, 1, 1) {}
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	bool SendMessage(BaseMessage* msg) { return false; }
	Vector3 m_Position;
	Vector3 m_Rotation;
	Vector3 m_Scale;

};

#endif /* Transform_hpp */