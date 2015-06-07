/********************************************//**
* \ScreenManager.hpp
* \Implements ScreenManager class functions
***********************************************/
#include "ScreenManager.h"

GameScreen *currentScreen, *newScreen;

/********************************************//**
* \instance generator
***********************************************/
ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

/********************************************//**
* \class destructor
***********************************************/
ScreenManager::~ScreenManager()
{ }

/********************************************//**
* \generate new screen instance
***********************************************/
void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen();
}

/********************************************//**
* \screen's content loader
***********************************************/
void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
}

/********************************************//**
* \screen's content unloader
***********************************************/
void ScreenManager::Update( sf::RenderWindow &Window, sf::Event event )
{
	currentScreen->Update( Window, event );
}

/********************************************//**
* \print the content on screen
***********************************************/
void ScreenManager::Draw( sf::RenderWindow &Window )
{
	currentScreen->Draw( Window );
}

/********************************************//**
* \add a new screen
***********************************************/
void ScreenManager::AddScreen( GameScreen *screen )
{
	// Unload the previous screen content
	currentScreen->UnloadContent();

	// Delete the previous screen
	delete currentScreen;

	// Create a new screen
	currentScreen = screen;

	// Load the new content
	currentScreen->LoadContent();
}