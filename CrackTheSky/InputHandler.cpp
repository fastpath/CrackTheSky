#include "InputHandler.h"


InputHandler::InputHandler(boost::shared_ptr<sf::RenderWindow> p_app)
{
	m_app = p_app;
	m_running = false;
}


InputHandler::~InputHandler(void)
{
}

void InputHandler::handleKeys() {
		sf::Event Event;
		while (m_app->pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				m_app->close();
				break;
			case sf::Event::KeyReleased:
				std::cout << "Taste losgelassen" << std::endl;
				IBaseEventManager::Get()->VProcessEvents(5);
			default:
				break;
			}
		}

		
}
