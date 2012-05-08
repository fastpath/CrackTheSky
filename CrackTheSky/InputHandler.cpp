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
		//TProperty<int>* bla =static_cast<TProperty<int>*>(tmp);

		sf::Event sfmlEvent;
		while (m_app->pollEvent(sfmlEvent))
		{
			EventPtr keyEvent(new Event(KEY_PRESSED,0.0f));
			PropertyPtr key;
			switch (sfmlEvent.type)
			{
			case sf::Event::Closed:
				m_app->close();
				break;
			case sf::Event::KeyPressed:
				key = PropertyPtr(new TProperty<sf::Keyboard::Key>(KEY,sfmlEvent.key.code));
				keyEvent->addProperty(key);
				break;
			case sf::Event::KeyReleased:
				std::cout << "Taste losgelassen" << std::endl;
				IBaseEventManager::Get()->VProcessEvents(5);
			default:
				break;
			}

			IBaseEventManager::Get()->VQueueEvent(keyEvent);
		}

		
}
