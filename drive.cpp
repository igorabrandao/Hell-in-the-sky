/********************************************//**
* \drive.cpp
* \Main
***********************************************/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"

using namespace std;

int main()
{
	/*! Generate new windows */
	sf::RenderWindow Window( sf::VideoMode( screenWidth, screenHeight, 32 ), 
								"Windows Title");

	/*! ScreenManager instance */
	ScreenManager<std::string> scrm;
	scrm.Initialize();
	scrm.LoadContent();

	/*! Infinite loop that keeps screen */
	while ( Window.isOpen() )
	{
		/*! Event instance */
		sf::Event event;

		/*! Catch the window events */
		if ( Window.pollEvent(event) )
		{
			/*! Check if it's a close event */
			if ( event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape  )
			{
				Window.close();
			}
		}

		/*! Run SplashScreen */
		scrm.Update();
		scrm.Draw(Window);

		/*! Keep the screen showing */
		Window.display();
	}

	return 0;
}