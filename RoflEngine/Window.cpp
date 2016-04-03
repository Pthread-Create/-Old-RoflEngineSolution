#include "Window.h"

using namespace std;

fi::Window::Window(sf::RenderWindow& window, fi::Screen* screen){
	m_window = &window;
	m_screen = screen;
	window.setVerticalSyncEnabled(true);
	window.setActive(false);
	screen->setUsed(true);
	screen->create();
	m_renderThread = thread(&Window::renderThread, this);
	m_processingThread = thread(&Window::processingThread, this);
}

fi::Window::~Window() {
	m_renderThread.join();
	m_processingThread.join();
}

sf::RenderWindow* fi::Window::getWindow() {
	return m_window;
}

std::thread* fi::Window::getRenderThread() {
	return &m_renderThread;
}

void fi::Window::setScreen(fi::Screen* screen){
	m_screen = screen;
}

void fi::Window::renderThread(){
	fi::Screen* screen = m_screen;
	fi::Screen* oldscreen = nullptr;
	while (m_window->isOpen()) {
		if(!m_oldscrrender && screen != m_screen){
			oldscreen = m_screen;
			screen = m_screen;
			screen->setUsed(true);
			screen->create();
			m_oldscrrender = true;
		}
		if(m_oldscrrender && m_oldscrevent && m_oldscrprocessing){
			m_oldscrrender = false;
			m_oldscrevent = false;
			m_oldscrprocessing = false;
			oldscreen->setUsed(false);
			oldscreen = nullptr;

		}
		m_window->clear();
		screen->render(*m_window);
		m_window->display();
	}
	m_oldscrrender = true;
}

void fi::Window::processingThread(){
	fi::Screen* screen = m_screen;
	sf::Clock clock;
	while (m_window->isOpen()) {
		if(!m_oldscrprocessing && screen != m_screen && m_screen->isCreated()){
			screen = m_screen;
			m_oldscrprocessing = true;
		}
		screen->processing(clock.restart());
	}
	m_oldscrprocessing = true;
}

void fi::Window::eventThread() {
	fi::Screen* screen = m_screen;
	if(screen != m_screen)
		screen = m_screen;
	while (m_window->isOpen()) {
		if(!m_oldscrevent && screen != m_screen && m_screen->isCreated()){
			screen = m_screen;
			m_oldscrevent = true;
		}
		screen->event(*m_window);
	}
	m_oldscrevent = true;
	while(!m_oldscrprocessing || !m_oldscrrender);
	screen->setUsed(false);
}

