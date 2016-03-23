#include "Window.h"

using namespace std;

Window::Window(sf::RenderWindow& window, Screen* screen){
	m_window = &window;
	m_screen = screen;
	window.setVerticalSyncEnabled(true);
	window.setActive(false);
	screen->setUsed(true);
	screen->create();
	m_renderThread = thread(&Window::renderThread, this);
	m_processingThread = thread(&Window::processingThread, this);
}

Window::~Window() {
	m_renderThread.join();
	m_processingThread.join();
}

sf::RenderWindow* Window::getWindow() {
	return m_window;
}

std::thread* Window::getRenderThread() {
	return &m_renderThread;
}

void Window::setScreen(Screen* screen){
	m_screen = screen;
}

void Window::renderThread(){
	Screen* screen = m_screen;
	Screen* oldscreen = nullptr;
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

void Window::processingThread(){
	Screen* screen = m_screen;
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

void Window::eventThread() {
	Screen* screen = m_screen;
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

