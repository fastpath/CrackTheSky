#pragma once
#include "AbstractActor.h"
#include "Pose.h"
#include <iostream>

class MovableActor : public AbstractActor
{
public:
	MovableActor(void);
	MovableActor(int id);

	void accelerate(Pose& pose);
	Pose& getAcceleration();
	void update(float dt);

	~MovableActor(void);

private:
	Pose m_acceleration;
};

