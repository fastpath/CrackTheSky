#pragma once
#include <boost/shared_ptr.hpp>
#include "EventType.h"

class IEvent;
typedef boost::shared_ptr<IEvent> IEventPtr;

class IEvent
{
public:
	virtual const EventType& VGetEventType(void) const = 0;
	virtual float GetTimeStamp(void) const = 0;
	virtual IEventPtr VCopy(void) const = 0;
	virtual const char* GetName(void) const = 0;

};

class Event
{
	const EventType m_type;
	const float m_timeStamp;

public:
	explicit Event( const EventType p_type, const float p_timeStamp = 0.0f) : m_timeStamp(p_timeStamp), m_type(p_type) { };
	~Event(void) { }

	const EventType& GetEventType(void) {return m_type; }

	float GetTimeStamp(void) const {return m_timeStamp; }
};

