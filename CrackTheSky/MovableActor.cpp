#include "MovableActor.h"


MovableActor::MovableActor(void)
{
	
}

void MovableActor::update(float dt) {
	sf::Vector2f offset = m_acceleration.getDirection()*dt;
	float rotateOffset = m_acceleration.getRotation()*dt;
	this->Move(offset);
	this->Rotate(rotateOffset);
	//std::cout << "acc  (" << offset.x << "," << offset.y << ")" << std::endl;
}

void MovableActor::accelerate(Pose& pose) {
	m_acceleration = pose;
}

Pose& MovableActor::getAcceleration() {
	return m_acceleration;
}

MovableActor::~MovableActor(void)
{
}
