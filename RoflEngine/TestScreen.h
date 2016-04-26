#pragma once
#include "Screen.h"

namespace fi{
	class TestScreen : public fi::Screen{
	public:
		TestScreen();
		~TestScreen();
		virtual void create();
		virtual void render(sf::RenderWindow& window);
		virtual void processing(fi::Window& screenProcessing, sf::Time time);
		virtual void remove();
	private:
		sf::CircleShape* circle = nullptr;
		double time;
		fi::TestScreen* newscreen = nullptr;
	};
}
