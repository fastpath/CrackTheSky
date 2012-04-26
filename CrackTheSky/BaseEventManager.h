#pragma once
#include "Events.h"
#include "EventListener.h"
#include <boost/container/list.hpp>


class BaseEventManager
{
public:
	BaseEventManager(void);
	~BaseEventManager(void);

	virtual bool VAddEventListener(const EventListener& p_listener, const boost::container::list<EventType> p_types) = 0;
	virtual bool VRemoveEventListener(const EventListener& p_listener) = 0;
	virtual bool VAddEventTypeToListener(const EventListener& p_listener, const boost::container::list<EventType> p_types);

	virtual bool VAddScriptEventListener(const EventListener& p_listener, const boost::container::list<EventType> p_types);
	virtual bool VRemoveScriptEventListener(const EventListener& p_listener);
	
	virtual void processEvents(long time);
	virtual bool triggerEvent(Event p_event);

	virtual bool VValidateType(EventType type);


};

