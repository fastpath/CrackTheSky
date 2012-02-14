#pragma once
#include <SFML/Graphics.hpp>
class AbstractActor : public sf::Sprite
{
public:
	AbstractActor(void);

	virtual void update(float dt) = 0;

	~AbstractActor(void);
};

