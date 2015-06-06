#include "SplashScreen.h"

/********************************************//**
* \class constructor
***********************************************/
SplashScreen::SplashScreen()
{
	/* Empty */
}

/********************************************//**
* \class destructor
***********************************************/
SplashScreen::~SplashScreen()
{
	/* Empty */
}

/********************************************//**
* \load content on screen
***********************************************/
void SplashScreen::LoadContent()
{
	if ( !font.loadFromFile("fonts/8-BIT_WONDER.TTF") )
	{
		std::cout << "Could not find the specific font" << std::endl;
	}

	text.setString("SplashScreen");
	text.setFont(font);
}

/********************************************//**
* \unload screen's content
***********************************************/
void SplashScreen::UnloadContent()
{

}

/********************************************//**
* \update screen content
***********************************************/
void SplashScreen::Update()
{

}

/********************************************//**
* \print the screen content
***********************************************/
void SplashScreen::Draw( sf::RenderWindow &Window )
{
	Window.draw( text );
}