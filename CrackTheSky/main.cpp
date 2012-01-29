#include <SFML/Graphics.hpp>

int main ()
{
	sf::RenderWindow Window(sf::VideoMode(800,600,32),"SFML DEMO");
	
	while (Window.IsOpen())
	{
		sf::Event Event;
		while (Window.PollEvent(Event))
		{
			switch (Event.Type)
			{
			case sf::Event::Closed:
				Window.Close();
				break;
			default:
				break;
			}
		}

		Window.Clear(sf::Color(0,255,255));
		Window.Display();
	}

	return 0;
}