#include "Main.h"

using namespace std;

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.majorVersion = 3;
	sf::RenderWindow rWindow(sf::VideoMode(800, 600), "MaFenetre", sf::Style::None | sf::Style::Titlebar | sf::Style::Close,  settings);
	Screen* screen = new Screen;
	Window window(rWindow, screen);
	window.eventThread();
	while(screen->isUsed());
	delete screen;
	cout << "deleted" << endl;
}