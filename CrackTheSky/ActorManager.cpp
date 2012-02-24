#include "ActorManager.h"

boost::container::map<int,boost::shared_ptr<AbstractActor> > ActorManager::s_actorMap;
std::string ActorManager::s_xmlFolder = "../CrackTheSky/data/xml/";

boost::shared_ptr<AbstractActor> ActorManager::getNewMovableActor(std::string actorName) {
	pugi::xml_document doc;
	std::string fileName = s_xmlFolder+"MovableActors.xml";

	pugi::xml_parse_result result = doc.load_file(fileName.c_str());
	std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("root").child("actor").attribute("name").value() << std::endl;

	boost::shared_ptr<AbstractActor> smartPtr(new MovableActor());

	return smartPtr;
}

