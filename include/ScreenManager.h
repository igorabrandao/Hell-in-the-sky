/********************************************//**
* \ScreenManager.h
* \Class to handle screen issues
***********************************************/
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>
#include "GameScreen.h"
#include "SplashScreen.h"

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

		void Initialize();
		void LoadContent();
		void UnloadContent();
		void Update();
		void Draw( sf::RenderWindow &Window );
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