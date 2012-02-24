#include <boost/container/map.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "AbstractActor.h"
#include "MovableActor.h"
#include <string>
#include <iostream>
#include "libs\pugixml\pugixml.hpp"

class ActorManager
{
public:
	static boost::container::map<int,boost::shared_ptr<AbstractActor> > s_actorMap;

	ActorManager(void);
	~ActorManager(void);

	static boost::shared_ptr<AbstractActor> getNewMovableActor(std::string fileName);

private:
	static std::string s_xmlFolder;


};

