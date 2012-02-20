#include "AbstractActor.h"


AbstractActor::AbstractActor(void)
{
	m_id = 0;
}


AbstractActor::~AbstractActor(void)
{
}

AbstractActor::AbstractActor(int id) {
	m_id = id;
}

int AbstractActor::getId() {
	return m_id;
}
