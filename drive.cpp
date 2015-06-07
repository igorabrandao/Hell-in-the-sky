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
	/*ScreenManager scrm;
	scrm.Initialize();
	scrm.LoadContent();*/
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

	Window.setKeyRepeatEnabled(false);

	/*! Infinite loop that keeps screen */
	while ( Window.isOpen() )
	{
		/*! Event instance */
		sf::Event event;

		/*! Catch the window events */
		if ( Window.pollEvent(event) )
		{
			/*! Check if it's a close event */
			if ( event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape )
			{
				Window.close();
			}
		}

		/*! Clear screen before load a new content */
		Window.clear();

		/*! Run SplashScreen */
		/*scrm.Update(event);
		scrm.Draw(Window);*/
		ScreenManager::GetInstance().Update(Window, event);
		ScreenManager::GetInstance().Draw(Window);

		/*! Keep the screen showing */
		Window.display();
	}

	return 0;
}