#include <SFML/Graphics.hpp>
#include "Window.h"
#include "TestScreen.h"
#include <iostream>
#include "Point.h"
#include "Segment.h"

using namespace std;

// change main to WinMain in order to not show the console.

void windowThread() {
	cout << "Opening Windows" << endl;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 3;
	sf::RenderWindow rWindow(sf::VideoMode(1366, 768), "MaFenetre", sf::Style::None | sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, settings);
	rWindow.setVerticalSyncEnabled(true);
	rWindow.setFramerateLimit(60);
	fi::TestScreen* screen = new fi::TestScreen();
	fi::Window window(rWindow, (fi::Screen*)screen);
	window.eventThread();
	delete screen;
	cout << "Closing Windows" << endl;
}

int main() {
	thread windowthread = thread(&windowThread);
	fi::Point a(0, 1), b(2,1), c(1,0), d(1,2);
	fi::Segment seg1(a, b), seg2(c, d);
	cout << endl;
	cout << seg1 << " " << seg2 << endl;
	cout << *seg1.intersect(seg2) << endl;
	windowthread.join();
	return 0;
}