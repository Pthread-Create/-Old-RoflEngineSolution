#include <SFML/Graphics.hpp>
#include "Window.h"
#include "TestScreen.h"
#include <iostream>

using namespace std;

// change main to WinMain in order to not show the console.

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 3;
	sf::RenderWindow rWindow(sf::VideoMode(800, 600), "MaFenetre", sf::Style::None | sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize,  settings);
	fi::TestScreen* screen = new fi::TestScreen();
	fi::Window window(rWindow, (fi::Screen*)screen);
	window.eventThread();
	while(((fi::Screen*)screen)->isUsed());
	delete screen;
	cout << " free";
	while(true);
}