#include "Screen.h"

Screen::Screen(){
}

Screen::~Screen(){
}

void Screen::create(){
	m_created = true;
}

void Screen::render(sf::RenderWindow& window){
	sf::CircleShape shape(50,3);
	shape.setFillColor(sf::Color(100, 250, 50));
	window.draw(shape);
}

void Screen::processing(sf::Time time){
	////////////////////////////////////////

}

void Screen::event(sf::RenderWindow& window){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed)
			window.close();
	}
}

void Screen::remove(){
}

bool Screen::isCreated(){
	return m_created;
}

bool Screen::isUsed(){
	return m_used;
}

void Screen::setUsed(bool used){
	m_used = used;
}
