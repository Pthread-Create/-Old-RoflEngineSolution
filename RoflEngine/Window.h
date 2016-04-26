#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <thread>
#include "Screen.h"

namespace fi{
	class Window{
	public:
		Window(sf::RenderWindow& window, fi::Screen* screen);
		~Window();
		void eventThread();
		inline sf::RenderWindow* getWindow();
		inline std::thread* getRenderThread();
		void setScreen(fi::Screen* screen);
	private:
		void renderThread();
		void processingThread();
		sf::RenderWindow* m_window;
		fi::Screen* m_screen;
		std::thread m_renderThread;
		std::thread m_processingThread;
		bool m_oldscrrender = false;
		bool m_oldscrprocessing = false;
		bool m_oldscrevent = false;
		bool m_canchangescreen = true;
	};
}