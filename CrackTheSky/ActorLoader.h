#include <boost/container/map.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <iostream>

class ActorLoader
{
public:
	ActorLoader(void);
	~ActorLoader(void);

	static boost::shared_ptr<sf::Texture> getNewMovableActor(std::string fileName);

private:
	static std::string s_textureFolder;
};

