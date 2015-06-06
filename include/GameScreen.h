#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>

class GameScreen
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		GameScreen();  // class destructor
		~GameScreen(); // class constructor	

		virtual void LoadContent(); // Load the content on the screen
		virtual void UnloadContent(); // Unload the content on the screen
		virtual void Update(); // Update the screen content
		virtual void Draw( sf::RenderWindow &Window ); // Print the content on the screen

	/*! 
     * Protected section
	*/
	protected:

	/*!
     * Private section
	*/
	private:
};

#endif // GAMESCREEN_H