#include "LevelScreen.h"

/********************************************//**
* \class constructor
***********************************************/
LevelScreen::LevelScreen()
{
	/* Empty */
}

/********************************************//**
* \class destructor
***********************************************/
LevelScreen::~LevelScreen()
{
	/* Empty */
}

/********************************************//**
* \load content on screen
***********************************************/
void LevelScreen::LoadContent()
{std::cout << "LevelScreen::LoadContent()" << std::endl;
	if ( !font.loadFromFile("assets/fonts/8-BIT_WONDER.TTF") )
	{
		std::cout << "Could not find the specific font" << std::endl;
	}

	text.setString("LevelScreen");
	text.setFont(font);

	keys.push_back( sf::Keyboard::Z );
	keys.push_back( sf::Keyboard::Return );
}

/********************************************//**
* \unload screen's content
***********************************************/
void LevelScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

/********************************************//**
* \update screen content
***********************************************/
void LevelScreen::Update( sf::RenderWindow &Window, sf::Event event )
{
	input.Update( event );

	/*if ( input.KeyPressed(keys) )
	{
		ScreenManager::GetInstance().AddScreen( new TitleScreen );
	}*/
}

/********************************************//**
* \print the screen content
***********************************************/
void LevelScreen::Draw( sf::RenderWindow &Window )
{
	Window.draw( text );
}