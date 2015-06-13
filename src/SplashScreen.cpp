#include "SplashScreen.h"

/********************************************//**
* \class constructor
***********************************************/
SplashScreen::SplashScreen()
{std::cout << "SplashScreen::SplashScreen()" << std::endl;
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
{std::cout << "SplashScreen::LoadContent()" << std::endl;
	imageNumber = 0;

	if ( !font.loadFromFile("assets/fonts/8-BIT_WONDER.TTF") )
	{
		std::cout << "Could not find the specific font" << std::endl;
	}

	text.setString("SplashScreen");
	text.setFont(font);

	/* Keys that trigger the event */
	keys.push_back(sf::Keyboard::Return);

	file.LoadContent("assets/settings/splash.hell", attributes, contents);

	for ( int unsigned i = 0; i < attributes.size(); i++ )
	{
		for ( int unsigned j = 0; j < attributes[i].size(); j++ )
		{
			std::string att = attributes[i][j];

			if ( att == "Image" )
			{
				sf::Vector2f pos(0, 0);
				image.loadFromFile(contents[i][j]);
				fade.push_back(new FadeAnimation);
				fade[fade.size() - 1]->LoadContent("", image, pos);
				fade[fade.size() - 1]->SetValue(fade[fade.size() - 1]->GetActive(), true);
				fade[fade.size() - 1]->SetValue(fade[fade.size() - 1]->GetScale(), 1.25f);
			}
		}
	}
}

/********************************************//**
* \unload screen's content
***********************************************/
void SplashScreen::UnloadContent()
{std::cout << "SplashScreen::UnloadContent()" << std::endl;
	GameScreen::UnloadContent();

	for ( int unsigned i = 0; i < fade.size(); i++ )
	{
		fade[i]->UnloadContent();
		delete fade[i];
	}
	fade.clear();
}

/********************************************//**
* \update screen content
***********************************************/
void SplashScreen::Update( sf::RenderWindow &Window, sf::Event event )
{std::cout << "SplashScreen::Update(): " << imageNumber << " - " << fade.size() << std::endl;
	input.Update( event );

	if ( fade[imageNumber]->GetAlpha() <= 0.0f )
		imageNumber++;

	if ( imageNumber != fade.size() - 1 );
		fade[imageNumber]->Update(Window);

	if ( input.KeyPressed(keys) || imageNumber >= fade.size() - 1 )
	{
		std::cout << "*************************" << std::endl;
		std::cout << "=======TitleScreen=======" << std::endl;
		std::cout << "*************************" << std::endl;
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
	}
}

/********************************************//**
* \print the screen content
***********************************************/
void SplashScreen::Draw( sf::RenderWindow &Window )
{std::cout << "SplashScreen::Draw(): " << imageNumber << std::endl;
	//Window.draw(text);
	fade[imageNumber]->Draw(Window);
}