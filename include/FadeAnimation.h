#pragma once

#include "Animation.h"

class FadeAnimation : public Animation
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		FadeAnimation(void);
		~FadeAnimation(void);

		void LoadContent( std::string text, sf::Texture, sf::Vector2f position ); // Load the content on the screen
		void UnloadContent(); // Unload the content on the screen
		void Update( sf::RenderWindow &Window ); // Update the screen content
		void Draw( sf::RenderWindow &Window ); // Print the content on the screen

		virtual void SetAlpha( float alpha ); // Set the alpha to fade transition
	/*!
     * Protected section
	*/
	protected:

	/*!
     * Private section
	*/
	private:
		/*! Attributes */
		bool increase;
		float fadeSpeed;
};