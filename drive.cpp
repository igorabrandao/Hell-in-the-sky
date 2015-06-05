/********************************************//**
* \drive.cpp
* \Main
***********************************************/
#include <iostream>
#include "ScreenManager.h"

using namespace std;

int main()
{
	ScreenManager<std::string> obj;
	obj.setText("Testing");
	obj.drawText();

	std::cin.get();
	return 0;
}