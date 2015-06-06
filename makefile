all:
	g++ drive.cpp src/GameScreen.cpp src/SplashScreen.cpp src/TitleScreen.cpp -I include -lsfml-graphics -lsfml-window -lsfml-system -o drive