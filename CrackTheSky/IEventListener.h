#pragma once
#include "Events.h"
#include <boost/shared_ptr.hpp>

class IEventListener
{
public:
	IEventListener(void);
	~IEventListener(void);

	virtual bool processEvent(boost::shared_ptr<Event> p_event) = 0;
};

