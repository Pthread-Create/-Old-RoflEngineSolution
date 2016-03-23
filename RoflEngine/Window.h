#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <thread>
#include "Screen.h"

class Window {
public:
	Window(sf::RenderWindow& window, Screen* screen);
	~Window();
	void eventThread();
	inline sf::RenderWindow* getWindow();
	inline std::thread* getRenderThread();
	void setScreen(Screen* screen);
private:
	void renderThread();
	void processingThread();
	sf::RenderWindow* m_window;
	Screen* m_screen;
	std::thread m_renderThread;
	std::thread m_processingThread;
	bool m_oldscrrender = false;
	bool m_oldscrprocessing = false;
	bool m_oldscrevent = false;
};