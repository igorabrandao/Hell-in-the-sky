/********************************************//**
* \ScreenManager.h
* \Class to handle screen issues
***********************************************/
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>
#include "GameScreen.h"
#include "SplashScreen.h"

/*! CONSTANTS */
#define screenWidth 1200
#define screenHeight 768

template <typename T>
class ScreenManager
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		~ScreenManager(); // class destructor
		ScreenManager();  // class constructor				
		ScreenManager( ScreenManager const& ); // class constructor override

		void Initialize(); // Initialize the screen
		void LoadContent(); // Load the content on the screen
		void UnloadContent(); // Unload the content on the screen
		void Update(); // Update the screen content
		void Draw( sf::RenderWindow &Window ); // Print the content on the screen

		void AddScreen( GameScreen *screen ); // Add a new screen
	/*! 
     * Protected section
	*/
	protected:

	/*!
     * Private section
	*/
	private:
		//GameScreen *currentScreen, *newScreen;

		/*! Operators */
		const ScreenManager & operator=( const ScreenManager & ); // operator equal
};

#include "ScreenManager.hpp"
#endif // SCREENMANAGER_H