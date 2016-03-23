#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Screen {
public:
	Screen();
	virtual ~Screen();
	virtual void create();
	virtual void render(sf::RenderWindow& window);
	virtual void processing(sf::Time time);
	virtual void event(sf::RenderWindow& window);
	virtual void remove();
	bool isCreated();
	bool isUsed();
	void setUsed(bool used);
private:
	bool m_created = false;
	bool m_used = false;
};