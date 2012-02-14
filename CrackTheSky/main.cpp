#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/container/vector.hpp>
#include <boost/foreach.hpp>
#include "TextureLoader.h"
#include "MovableActor.h"
#include "Pose.h"

const int FRAMERATE = 60;
const float DT = 1.0/FRAMERATE;
const float EPSILON = 0.01;



int main ()
{
	sf::RenderWindow Window(sf::VideoMode(800,600,32),"SFML DEMO");
	sf::ContextSettings cs = Window.GetSettings();


	boost::container::vector<boost::shared_ptr<MovableActor> > actors;

	boost::shared_ptr<MovableActor> cody(new MovableActor());
	cody->SetTexture(*TextureLoader::getTexture("cody2_500x1000"));
	cody->SetPosition(300.0,300.0);
	cody->SetScale(0.2,0.2);
	actors.push_back(cody);

	boost::shared_ptr<MovableActor> astroid1(new MovableActor());
	astroid1->SetTexture(*TextureLoader::getTexture("astroid1_600x500"));
	astroid1->SetPosition(500.0,500.0);
	astroid1->SetOrigin(300.0,250.0);
	astroid1->SetScale(0.3,0.3);
	astroid1->accelerate(Pose(0.0,0.0,30));
	actors.push_back(astroid1);

	boost::shared_ptr<MovableActor> astroid2(new MovableActor());
	astroid2->SetTexture(*TextureLoader::getTexture("astroid2_600x500"));
	astroid2->SetPosition(300.0,400.0);
	astroid2->SetOrigin(300.0,250.0);
	astroid2->SetScale(0.4,0.4);
	astroid2->accelerate(Pose(0.0,0.0,50));
	actors.push_back(astroid2);

	boost::shared_ptr<MovableActor> astroid3(new MovableActor());
	astroid3->SetTexture(*TextureLoader::getTexture("astroid3_550x700"));
	astroid3->SetPosition(200.0,300.0);
	astroid3->SetOrigin(225.0,350.0);
	astroid3->SetScale(0.5,0.5);
	astroid3->accelerate(Pose(0.0,0.0,30));
	actors.push_back(astroid3);

	sf::Clock clock;

	float t = 0.0;
	float speed = 200.0;
	sf::Time currentTime = clock.GetElapsedTime();

	Window.SetFramerateLimit(FRAMERATE);
	while (Window.IsOpen())
	{
		sf::Time newTime = clock.GetElapsedTime();
		float frameTime = newTime.AsSeconds() - currentTime.AsSeconds();
		//std::cout << " time  " << frameTime << std::endl;
        currentTime = newTime;
		

		sf::Event Event;
		while (Window.PollEvent(Event))
		{
			switch (Event.Type)
			{
			case sf::Event::Closed:
				Window.Close();
				break;
			case sf::Event::KeyReleased:
					cody->accelerate(Pose(0,0,0));
			default:
				break;
			}
		}

		sf::Vector2f direction = cody->getAcceleration().getDirection();
		if (sf::Keyboard::IsKeyPressed(sf::Keyboard::W)) {
			direction.y = -speed;
		}
		if (sf::Keyboard::IsKeyPressed(sf::Keyboard::S)) {
			direction.y = speed;
		}
		if (sf::Keyboard::IsKeyPressed(sf::Keyboard::D)) {
			direction.x = speed;
		}
		if (sf::Keyboard::IsKeyPressed(sf::Keyboard::A)) {
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
		Window.Clear(sf::Color(0,255,255));
		BOOST_FOREACH (boost::shared_ptr<MovableActor> actor, actors) {
			Window.Draw(*actor);
		}
		Window.Display();
	}

	return 0;
}