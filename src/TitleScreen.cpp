#include "TitleScreen.h"

/********************************************//**
* \class constructor
***********************************************/
TitleScreen::TitleScreen()
{std::cout << "TitleScreen::TitleScreen()" << std::endl;
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
{std::cout << "TitleScreen::LoadContent()" << std::endl;
	if ( !font.loadFromFile("assets/fonts/8-BIT_WONDER.TTF") )
	{
		std::cout << "Could not find the specific font" << std::endl;
	}

	text.setString("TitleScreen");
	text.setFont(font);

	keys.push_back( sf::Keyboard::Z );
	keys.push_back( sf::Keyboard::Return );

	menu.LoadContent("Title");
}

/********************************************//**
* \unload screen's content
***********************************************/
void TitleScreen::UnloadContent()
{std::cout << "TitleScreen::UnloadContent()" << std::endl;
	GameScreen::UnloadContent();
	menu.UnloadContent();
}

/********************************************//**
* \update screen content
***********************************************/
void TitleScreen::Update( sf::RenderWindow &Window, sf::Event event )
{std::cout << "TitleScreen::Update()" << std::endl;
	input.Update( event );

	if ( input.KeyPressed(keys) )
	{
		//ScreenManager::GetInstance().AddScreen(new SplashScreen);
	}

	menu.Update(Window, input);
}

/********************************************//**
* \print the screen content
***********************************************/
void TitleScreen::Draw( sf::RenderWindow &Window )
{std::cout << "TitleScreen::Draw()" << std::endl;
	//Window.draw( text );
	menu.Draw(Window);
}