#include "SFML\Graphics\Transform.hpp"
#include "TransformComponent.hpp"

void Transform::Awake() {
	sf::Transform transform;
	transform.translate(m_Position.x, m_Position.y);
	transform.rotate(m_Rotation);
	transform.scale(m_Scale.x, m_Scale.y);
	transform = transform;
}

void Transform::Start() {
	sf::Transform transform;
	transform.translate(m_Position.x, m_Position.y);
	transform.rotate(m_Rotation);
	transform.scale(m_Scale.x, m_Scale.y);
	transform = transform;
}

void Transform::Update() {

}

void Transform::LateUpdate() {

}