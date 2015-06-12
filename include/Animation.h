#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		Animation();
		~Animation();

		virtual void LoadContent( std::string text, sf::Texture image, sf::Vector2f position ); // Load the content on the screen
		virtual void UnloadContent(); // Unload the content on the screen
		virtual void Update( sf::RenderWindow &Window ); // Update the screen content
		virtual void Draw( sf::RenderWindow &Window ); // Print the content on the screen

		virtual void SetAlpha( float alpha ); // Set the alpha to fade transition
		float GetAlpha(); // Get the alpha value from fade transition

		void SetActive( bool value );
	/*!
     * Protected section
	*/
	protected:
		/*! Attributes */
		float alpha;
		std::string preText;
		sf::Text text;
		sf::Texture image;
		sf::Sprite sprite;
		sf::Vector2f position;
		sf::Color textColor;

		sf::IntRect sourceRect;
		bool active;

	/*!
     * Private section
	*/
	private:

};