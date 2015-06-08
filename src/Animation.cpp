#include "Animation.h"

/********************************************//**
* \class constructor
***********************************************/
Animation::Animation()
{
	/* Empty */
}

/********************************************//**
* \class destructor
**********************************	*************/
Animation::~Animation()
{
	/* Empty */
}

/********************************************//**
* \content loader
***********************************************/
void Animation::LoadContent( std::string text, sf::Texture, sf::Vector2f position )
{
	this->preText = text;
	this->image = image;
	this->position = position;

	alpha = 1.0f;
	textColor = sf::Color(114, 77, 255);

	if ( image.getSize().y > 0 )
		sprite.setTexture(image);

	sprite.setTexture(image);
	this->text.setString(text);
	active = false;
}

/********************************************//**
* \content unloader
***********************************************/
void Animation::UnloadContent()
{
	
}

/********************************************//**
* \update animation
***********************************************/
void Animation::Update( sf::RenderWindow &Window )
{

}

/********************************************//**
* \render the animation
***********************************************/
void Animation::Draw( sf::RenderWindow &Window )
{
	std::string str = text.getString();

	if ( str != "" )
		Window.draw(text);
	if ( sprite.getTexture() != NULL)
		Window.draw(sprite);
}

/********************************************//**
* \get animation alpha value
***********************************************/
float Animation::GetAlpha()
{
	return alpha;
}

/********************************************//**
* \set animation alpha value
***********************************************/
void Animation::SetAlpha( float value )
{
	alpha = value;
}

/********************************************//**
* \get animation alpha value
***********************************************/
void Animation::SetActive( bool value )
{
	active = value;
}