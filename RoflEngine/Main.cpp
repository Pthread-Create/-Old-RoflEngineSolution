#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Screen.h"
#include <iostream>
#include "Point.h"

using namespace std;

// change main to WinMain in order to not show the console.

int main() {
	fi::Point point(5, 5);
	cout << point << endl;
	fi::Point point2(6, 6);
	cout << point2 << endl;
	fi::Point point3 = point2 + point;
	cout << point3 << endl;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 3;
	sf::RenderWindow rWindow(sf::VideoMode(800, 600), "MaFenetre", sf::Style::None | sf::Style::Titlebar | sf::Style::Close,  settings);
	fi::Screen* screen = new fi::Screen;
	fi::Window window(rWindow, screen);
	window.eventThread();
	while(screen->isUsed());
	delete screen;
	cout << "deleted" << endl;
}