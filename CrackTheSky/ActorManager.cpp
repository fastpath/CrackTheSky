#include "ActorManager.h"

boost::container::map<std::string,boost::shared_ptr<AbstractActor> > ActorManager::s_actorMap;
std::string ActorManager::s_xmlFolder = "../CrackTheSky/data/xml/";

boost::shared_ptr<AbstractActor> getNewMovableActor(std::string fileName) {
	
}

