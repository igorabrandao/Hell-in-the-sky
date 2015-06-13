#pragma once

#include "Animation.h"
#include "FadeAnimation.h"
#include "InputManager.h"
#include "FileManager.h"
/********************************************//**
* \MenuManager.h
* \Class to handle menu's issues
***********************************************/
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class MenuManager
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		MenuManager(void);
		~MenuManager(void);	

		void LoadContent( std::string menuID ); // Load the content on the screen
		void UnloadContent(); // Unload memory allocation
		void Update( sf::RenderWindow &Window, InputManager input ); // Update the screen content
		void Draw( sf::RenderWindow &Window ); // Print the content on the screen
	/*! 
     * Protected section
	*/
	protected:

	/*! 
     * Private section
	*/
	private:
		/*! Attributes */

		/** Vectors that receive configs parameters from file
		 * attributes -> stores attributes param
		 * contents -> stores attributes content
		*/
		std::vector<std::vector<std::string>> attributes;
		std::vector<std::vector<std::string>> contents;

		sf::Texture image; // Image that'll be loaded
		sf::Texture null; // Default image

		/*! Classes instances */
		FileManager file;

		/** Vector that stores menu items and animtions type
		 * @[0] -> menu items
		 * @[1] -> animations type (Fade, Zoom, etc...)
		*/
		std::vector<std::vector<Animation*>> animation;
		std::vector<Animation*> tempAnimation;

		std::vector<sf::Texture> menuImages;
		std::vector<std::string> menuItems;

		sf::Vector2f position;
		int axis;
		std::string align;
		std::vector<std::string> animationTypes;

		int unsigned itemNumber;

		/*! Functions */
		void EqualizeMenuItems();
		void SetAnimations();
		void SetPositions();
};