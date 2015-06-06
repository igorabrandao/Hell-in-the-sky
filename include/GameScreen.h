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

		virtual void LoadContent();
		virtual void UnloadContent();
		virtual void Update();
		virtual void Draw( sf::RenderWindow &Window );

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