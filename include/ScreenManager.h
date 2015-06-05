/********************************************//**
* \ScreenManager.h
* \Class to handle screen issues
***********************************************/
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>

template <typename T>
class ScreenManager
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		~ScreenManager(); // class destructor
		ScreenManager(); // class constructor				
		ScreenManager( ScreenManager const& ); // class constructor override

		void setText( T _text ); // set screen text
		void drawText(); // print text on the screen

	/*! 
     * Protected section
	*/
	protected:

	/*! 
     * Private section
	*/
	private:
		/*! Operators */
		const ScreenManager & operator=( const ScreenManager & ); // operator equal

		/*! Attributes */
		T text; // 
};

#include "ScreenManager.hpp"
#endif // SCREENMANAGER_H