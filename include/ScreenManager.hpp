/********************************************//**
* \ScreenManager.hpp
* \Implements ScreenManager class functions
***********************************************/
#include "ScreenManager.h"

GameScreen *currentScreen, *newScreen;
/********************************************//**
* \class constructor
***********************************************/
template< typename T >
ScreenManager<T>::ScreenManager()
{ 

}

/********************************************//**
* \class destructor
***********************************************/
template< typename T >
ScreenManager<T>::~ScreenManager()
{ }

/********************************************//**
* \generate new screen instance
***********************************************/
template< typename T >
void ScreenManager<T>::Initialize()
{
	currentScreen = new SplashScreen;
}

/********************************************//**
* \screen's content loader
***********************************************/
template< typename T >
void ScreenManager<T>::LoadContent()
{
	currentScreen->LoadContent();
}

/********************************************//**
* \screen's content unloader
***********************************************/
template< typename T>
void ScreenManager<T>::Update()
{
	currentScreen->Update();
}

/********************************************//**
* \print the content on screen
***********************************************/
template< typename T >
void ScreenManager<T>::Draw( sf::RenderWindow &Window )
{
	currentScreen->Draw( Window );
}