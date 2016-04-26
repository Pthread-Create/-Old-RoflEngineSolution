#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>



namespace fi{
	class Window;
	class Screen{
	public:
		Screen();
		~Screen();
		virtual void create();
		virtual void render(sf::RenderWindow& window);
		virtual void processing(fi::Window& screenProcessing, sf::Time time);
		virtual void event(sf::RenderWindow& window);
		virtual void remove();
		bool isCreated();
		bool isUsed();
		void setCreated(bool created);
		void setUsed(bool used);
	private:
		bool m_created = false;
		bool m_used = false;
	};
}