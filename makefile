all:
	g++ -std=c++0x drive.cpp src/ScreenManager.cpp src/InputManager.cpp src/GameScreen.cpp src/SplashScreen.cpp src/TitleScreen.cpp -I include/ -lsfml-graphics -lsfml-window -lsfml-system -o drive