#include "LevelScreen.h"

/*! Direction enum */
enum Direction { Down, Left, Right, Up };
sf::Vector2i source(1, Down);
int firstImageX = 280, firstImageY = 38;

float frameCounter = 0, switchFrame = 100, frameSpeed = 1000;

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
{
	keys.push_back( sf::Keyboard::Z );
	keys.push_back( sf::Keyboard::Return );

	//if ( !pTexture.loadFromFile("assets/sprites/player.png", sf::IntRect(0, 0, 100, 85)) )
	if ( !pTexture.loadFromFile("assets/sprites/player.png") )
	{
		std::cout << "Could not load PlayerManager image" << std::endl;
	}
	else
	{
		playerImage.setTexture(pTexture);
		//playerImage.setPosition(100, 100);
	}

	/*! Load screen music */
	if ( !buffer.loadFromFile("assets/sounds/level_theme.ogg") )
	{
		std::cout << "Could not find the menu music" << std::endl;
	}
	else
	{
		/* Initialize and play the sound */
		sound.setBuffer(buffer);
		sound.setLoop(true);
		sound.play();
	}

	/*! Load background image */
	if ( !background.loadFromFile("assets/images/menu/background.png") )
	{
		std::cout << "Could not find the background image" << std::endl;
	}
	else
	{
		image.setTexture(background);
	}
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

	/* Catch window event */
	switch ( event.type )
	{
		case sf::Event::Closed:
			Window.close();
			break;
	}

	if ( input.KeyDown(Window, sf::Keyboard::Up) )
	{
		source.y = Up;
		playerImage.move(0, -7);
	}
	else if ( input.KeyDown(Window, sf::Keyboard::Down) )
	{
		source.y = Down;
		playerImage.move(0, 7);
	}
	else if ( input.KeyDown(Window, sf::Keyboard::Right) )
	{
		source.y = Right;
		playerImage.move(7, 0);
	}
	else if ( input.KeyDown(Window, sf::Keyboard::Left) )
	{
		source.y = Left;
		playerImage.move(-7, 0);
	}

	// Delay  between changes
	/*sf::Time delayTime = sf::milliseconds(0.075);
	sf::sleep(delayTime);*/

	// Change the sprites
	frameCounter += frameSpeed * clock.restart().asSeconds();
	if ( frameCounter >= switchFrame )
	{
		frameCounter = 0;
		source.x++;

		if( firstImageX > 272 )
			firstImageX = 272;
		else 
			firstImageX = 400;
	}
}

/********************************************//**
* \print the screen content
***********************************************/
void LevelScreen::Draw( sf::RenderWindow &Window )
{
	Window.draw(image);
	playerImage.setTextureRect(sf::IntRect( firstImageX, firstImageY, 120, 50));
	Window.draw( playerImage );
}