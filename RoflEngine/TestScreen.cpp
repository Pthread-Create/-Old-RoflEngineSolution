#include "TestScreen.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Window.h"

using namespace std;

fi::TestScreen::TestScreen(){
}


fi::TestScreen::~TestScreen(){
	delete newscreen;
}

void fi::TestScreen::create(){
	time = 0.0;
	std::srand(std::time(0)); // use current time as seed for random generator
	int random_variable = std::rand();
	circle = new sf::CircleShape(std::rand()%1000, 150);
	if(random_variable % 4 == 0)
		circle->setFillColor(sf::Color::Blue);
	else if(random_variable % 4 == 1)
		circle->setFillColor(sf::Color::Red);
	else if(random_variable % 4 == 2)
		circle->setFillColor(sf::Color::Yellow);
	else if(random_variable % 4 == 3)
		circle->setFillColor(sf::Color::Green);
	newscreen = new fi::TestScreen();
}

void fi::TestScreen::render(sf::RenderWindow & window){
	window.draw(*circle);
}

void fi::TestScreen::processing(fi::Window& screenProcessing, sf::Time time){
	this->time += time.asSeconds();
		screenProcessing.setScreen(newscreen);
}

void fi::TestScreen::remove(){
	delete circle;
}
