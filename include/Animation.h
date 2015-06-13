/********************************************//**
* \Animation.h
* \Class to handle all game's animation
***********************************************/
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

		virtual void LoadContent( std::string text, sf::Texture &image, sf::Vector2f position ); // Load the content on the screen
		virtual void UnloadContent(); // Unload the content on the screen
		virtual void Update( sf::RenderWindow &Window ); // Update the screen content
		virtual void Draw( sf::RenderWindow &Window ); // Print the content on the screen

		virtual void SetAlpha( float alpha ); // Set the alpha to fade transition

		// Get functions
		float &GetAlpha();
		bool &GetActive();
		float &GetScale();
		sf::Text &GetText();
		sf::Vector2f &GetPosition();

		// Set function
		template <typename T>
		void SetValue( T &variable, T value )
		{
			variable = value;
		}

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

		float scale;

	/*!
     * Private section
	*/
	private:

};