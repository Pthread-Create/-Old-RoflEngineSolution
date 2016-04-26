#include "Screen.h"

fi::Screen::Screen(){
}

fi::Screen::~Screen(){
}

void fi::Screen::create(){
}

void fi::Screen::render(sf::RenderWindow& window){
}

void fi::Screen::processing(fi::Window& screenProcessing, sf::Time time){
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

void fi::Screen::setCreated(bool created){
	m_created = created;
}

void fi::Screen::setUsed(bool used){
	m_used = used;
}
