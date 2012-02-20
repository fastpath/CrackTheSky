#pragma once
#include <SFML/Graphics.hpp>
class AbstractActor : public sf::Sprite
{
public:
	AbstractActor(void);
	AbstractActor(int id);
	~AbstractActor(void);

	virtual void update(float dt) = 0;

	int getId();

private:
	int m_id;
};

