#pragma once
#include "EventData.h"

class EventListener
{
public:
	EventListener(void);
	~EventListener(void);

	virtual bool processEvent(BaseEvent Event);
};

