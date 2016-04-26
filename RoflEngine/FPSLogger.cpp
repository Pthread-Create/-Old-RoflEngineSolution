#include "FPSLogger.h"

fi::FPSLogger::FPSLogger(int numberOfEntry, double showInterval, std::ostream* output) : m_numberOfEntry(numberOfEntry), m_showInterval(showInterval), m_iterateur(0), m_entrywritten(0), m_sum(0){
	m_output = output;
	m_FPSTab = new double[numberOfEntry];
}

fi::FPSLogger::~FPSLogger(){
	delete[] m_FPSTab;
}

void fi::FPSLogger::addFPSEntry(double fps){
	if(m_entrywritten != m_numberOfEntry){
		m_sum += fps;
		m_FPSTab[m_iterateur++] = fps;
		m_entrywritten++;
		if(m_iterateur == m_numberOfEntry)
			m_iterateur = 0;
	}else{
		m_sum -= m_FPSTab[m_iterateur];
		m_sum += fps;
		m_FPSTab[m_iterateur++] = fps;
		if(m_iterateur == m_numberOfEntry)
			m_iterateur = 0;
	}
	if(m_clock.getElapsedTime().asSeconds() >= m_showInterval){
		*m_output << "FPS :" << (int)(m_sum / m_entrywritten) << std::endl;
		m_clock.restart();
	}
}
