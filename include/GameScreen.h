#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "InputManager.h"

class GameScreen
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		GameScreen();  // class constructor
		~GameScreen(); // class destructor

		virtual void LoadContent(); // Load the content on the screen
		virtual void UnloadContent(); // Unload the content on the screen
		virtual void Update( sf::RenderWindow &Window, sf::Event event ); // Update the screen content
		virtual void Draw( sf::RenderWindow &Window ); // Print the content on the screen

	/*!
     * Protected section
	*/
	protected:
		InputManager input;
		std::vector<int> keys;

	/*!
     * Private section
	*/
	private:
};

#endif // GAMESCREEN_H