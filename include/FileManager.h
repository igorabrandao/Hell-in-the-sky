/********************************************//**
* \FileManager.h
* \Class to deals with file's issues
***********************************************/
#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>

class FileManager
{
	/*! 
     * Public section
	*/
	public:
		/*! Functions */
		FileManager( void );  // class destructor
		~FileManager( void ); // class constructor	

		/*! Load content from file */
		void LoadContent( const char* filename, std::vector<std::vector<std::string>> &attributes,
			std::vector<std::vector<std::string>> &contents );

		/*! Load content from file */
		void LoadContent( const char* filename, std::vector<std::vector<std::string>> &attributes,
			std::vector<std::vector<std::string>> &contents,
			std::string id);

	/*!
     * Protected section
	*/
	protected:

	/*!
     * Private section
	*/
	private:

		/*! Attributes */
		std::vector<std::string> tempAttributes;
		std::vector<std::string> tempContents;

		bool idFound;
};