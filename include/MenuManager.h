/********************************************//**
* \MenuManager.h
* \Class to handle menu's issues
***********************************************/
#pragma once

/*#include "Animation.h"
#include "FadeAnimation.h"
#include "InputManager.h"
#include "FileManager.h"*/

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3


class MenuManager
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		MenuManager();
		~MenuManager();	

		void LoadContent( float width, float height );
		void MoveDown(); // Unload memory allocation
		void MoveUp(); // Update the screen content
		void Draw( sf::RenderWindow &Window ); // Print the content on the screen
		int GetPressedItem() { return selectedItemIndex; }
	/*! 
     * Protected section
	*/
	protected:

	/*! 
     * Private section
	*/
	private:
		/*! Attributes */
		int selectedItemIndex;
		sf::Font font;
		sf::Text menu[MAX_NUMBER_OF_ITEMS];
};