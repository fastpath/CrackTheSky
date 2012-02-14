#include "Pose.h"


Pose::Pose(void)
{
	m_position = sf::Vector2f(0.0,0.0);
	m_rotation = 0.0;
}

Pose::Pose(float x, float y, float rot){
	m_position = sf::Vector2f(x,y);
	m_rotation = rot;
};

float Pose::getRotation() {
	return m_rotation;
}

sf::Vector2f Pose::getDirection() {
	return m_position;
}


Pose::~Pose(void)
{
}
