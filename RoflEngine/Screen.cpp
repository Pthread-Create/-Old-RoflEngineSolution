#include "Screen.h"

fi::Screen::Screen(){
}

fi::Screen::~Screen(){
}

void fi::Screen::create(){
	m_created = true;
}

void fi::Screen::render(sf::RenderWindow& window){
	sf::CircleShape shape(50,3);
	shape.setFillColor(sf::Color(100, 250, 50));
	window.draw(shape);
}

void fi::Screen::processing(sf::Time time){
	////////////////////////////////////////

}

void fi::Screen::event(sf::RenderWindow& window){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed)
			window.close();
	}
}

void fi::Screen::remove(){
}

bool fi::Screen::isCreated(){
	return m_created;
}

bool fi::Screen::isUsed(){
	return m_used;
}

void fi::Screen::setUsed(bool used){
	m_used = used;
}
