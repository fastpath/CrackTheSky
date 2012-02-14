#pragma once
#include <SFML/System.hpp>

class Pose
{
public:
	Pose(void);
	Pose(float x, float y, float rot);
	~Pose(void);

	sf::Vector2f getDirection();
	float getRotation();
private:
	sf::Vector2f m_position;
	float m_rotation;

};

