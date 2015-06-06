#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "GameScreen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class TitleScreen : public GameScreen
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		TitleScreen();
		~TitleScreen();

		void Initialize(); // Initialize the screen
		void LoadContent(); // Load the content on the screen
		void UnloadContent(); // Unload the content on the screen
		void Update(); // Update the screen content
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
		sf::Text text;
		sf::Font font;
};

#endif // SPLASHSCREEN_H