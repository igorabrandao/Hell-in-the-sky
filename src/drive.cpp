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
								"Hell in the Sky");

	/*! Object to handle fade geometric */
	sf::RectangleShape Fade = sf::RectangleShape( sf::Vector2f(screenWidth, screenHeight) );
	Fade.setFillColor( sf::Color(255, 255, 255) );

	/*! ScreenManager instance */
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
		Window.clear( sf::Color(0.0f, 0.0f, 0.0f, ScreenManager::GetInstance().GetAlpha()) );

		/*! Run SplashScreen */
		ScreenManager::GetInstance().Update(Window, event);
		Fade.setFillColor( sf::Color(0, 0, 0, 255 * ScreenManager::GetInstance().GetAlpha()) );

		ScreenManager::GetInstance().Draw(Window);
		Window.draw(Fade);

		/*! Keep the screen showing */
		Window.display();
	}

	return 0;
}