#ifndef LevelScreen_H
#define LevelScreen_H

#include "GameScreen.h"
#include "ScreenManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class LevelScreen : public GameScreen
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		LevelScreen();
		~LevelScreen();

		void LoadContent(); // Load the content on the screen
		void UnloadContent(); // Unload the content on the screen
		void Update( sf::RenderWindow &Window, sf::Event event ); // Update the screen content
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
		sf::Texture background;
		sf::Sprite image;
		sf::Clock clock;

		sf::SoundBuffer buffer;
		sf::Sound sound;

		sf::Texture pTexture;
		sf::Sprite playerImage;

		int level;
		//list<int/*Enemies object*/> enemies;
		//GameObject player; // Instance player class
};

#endif // LevelScreen_H