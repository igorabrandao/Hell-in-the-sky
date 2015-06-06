all:
	g++ drive.cpp src/GameScreen.cpp -I include -lsfml-graphics -lsfml-window -lsfml-system -o drive