/********************************************//**
* \ScreenManager.hpp
* \Implements ScreenManager class functions
***********************************************/
#include "ScreenManager.h"

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
* \function to set the text to the screen
***********************************************/
template< typename T >
void ScreenManager<T>::setText( T text_ )
{
    this->text = text_;
}

/********************************************//**
* \function to print the text on screen
***********************************************/
template< typename T >
void ScreenManager<T>::drawText()
{
    std::cout << this->text << std::endl;
}