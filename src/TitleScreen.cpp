#include "TitleScreen.h"

/********************************************//**
* \class constructor
***********************************************/
TitleScreen::TitleScreen()
{
	/* Empty */
}

/********************************************//**
* \class destructor
***********************************************/
TitleScreen::~TitleScreen()
{
	/* Empty */
}

/********************************************//**
* \load content on screen
***********************************************/
void TitleScreen::LoadContent()
{
	if ( !font.loadFromFile("fonts/8-BIT_WONDER.TTF") )
	{
		std::cout << "Could not find the specific font" << std::endl;
	}

	text.setString("TitleScreen");
	text.setFont(font);
}

/********************************************//**
* \unload screen's content
***********************************************/
void TitleScreen::UnloadContent()
{

}

/********************************************//**
* \update screen content
***********************************************/
void TitleScreen::Update()
{

}

/********************************************//**
* \print the screen content
***********************************************/
void TitleScreen::Draw( sf::RenderWindow &Window )
{
	Window.draw( text );
}