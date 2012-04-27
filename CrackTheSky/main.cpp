#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/container/vector.hpp>
#include <boost/foreach.hpp>
#include "TextureLoader.h"
#include "MovableActor.h"
#include "Pose.h"
#include "ActorManager.h"
#include "InputHandler.h"
#include "EventManagerImpl.h"

const int FRAMERATE = 60;
const float DT = 1.0/FRAMERATE;
const float EPSILON = 0.01;

EventManagerImpl* m_evtMgr;


int main ()
{
	boost::shared_ptr<sf::RenderWindow> Window(new sf::RenderWindow(sf::VideoMode(800,600,32),"Crack the Sky"));
	sf::ContextSettings cs = Window->getSettings();

	ActorManager::getNewMovableActor("cody");

	boost::container::vector<boost::shared_ptr<MovableActor> > actors;

	m_evtMgr = new EventManagerImpl("Super EventManager", true);

	boost::shared_ptr<MovableActor> cody(new MovableActor());
	cody->setTexture(*TextureLoader::getTexture("cody2_500x1000"));
	cody->setPosition(300.0,300.0);
	cody->setScale(0.2,0.2);
	actors.push_back(cody);

	std::cout << cody->getTextureRect().height << std::endl;
	std::cout << cody->getGlobalBounds().height << std::endl;

	boost::shared_ptr<MovableActor> astroid1(new MovableActor());
	astroid1->setTexture(*TextureLoader::getTexture("astroid1_600x500"));
	astroid1->setPosition(500.0,500.0);
	astroid1->setOrigin(300.0,250.0);
	astroid1->setScale(0.3,0.3);
	astroid1->accelerate(Pose(0.0,0.0,30));
	actors.push_back(astroid1);

	boost::shared_ptr<MovableActor> astroid2(new MovableActor());
	astroid2->setTexture(*TextureLoader::getTexture("astroid2_600x500"));
	astroid2->setPosition(300.0,400.0);
	astroid2->setOrigin(300.0,250.0);
	astroid2->setScale(0.4,0.4);
	astroid2->accelerate(Pose(0.0,0.0,50));
	actors.push_back(astroid2);

	boost::shared_ptr<MovableActor> astroid3(new MovableActor());
	astroid3->setTexture(*TextureLoader::getTexture("astroid3_550x700"));
	astroid3->setPosition(200.0,300.0);
	astroid3->setOrigin(225.0,350.0);
	astroid3->setScale(0.5,0.5);
	astroid3->accelerate(Pose(0.0,0.0,30));
	actors.push_back(astroid3);

	sf::Clock clock;

	float t = 0.0;
	float speed = 400.0;
	sf::Time currentTime = clock.getElapsedTime();

	Window->setFramerateLimit(FRAMERATE);

		
	std::cout << "Creating InputHandler" << std::endl;
	boost::shared_ptr<InputHandler> input(new InputHandler(Window));


	while (Window->isOpen())
	{
		sf::Time newTime = clock.getElapsedTime();
		float frameTime = newTime.asSeconds() - currentTime.asSeconds();
		//std::cout << " time  " << frameTime << std::endl;
        currentTime = newTime;
		
		input->handleKeys();

		sf::Vector2f direction = cody->getAcceleration().getDirection();
		//std::cout << "Acc x " << cody->getAcceleration().getDirection().x << "  y " << cody->getAcceleration().getDirection().y << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			direction.y = -speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			direction.y = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			direction.x = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			direction.x = -speed;
		}
		cody->accelerate(Pose(direction.x,direction.y,0));
		
		while ( frameTime > 0.0 - EPSILON)
         {
			const float deltaTime = std::min( frameTime, DT );

			BOOST_FOREACH (boost::shared_ptr<MovableActor> actor, actors) {
				actor->update(deltaTime);
			}

            frameTime -= DT;
            t += deltaTime;
         }
		Window->clear(sf::Color(0,255,255));
		BOOST_FOREACH (boost::shared_ptr<MovableActor> actor, actors) {
			Window->draw(*actor);
		}
		Window->display();
	}

	return 0;
}