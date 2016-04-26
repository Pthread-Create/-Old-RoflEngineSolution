#pragma once
#include <SFML\System.hpp>
#include <iostream>

namespace fi{
	class FPSLogger{
	public :
		FPSLogger(int numberOfEntry, double showInterval, std::ostream* output);
		~FPSLogger();
		void addFPSEntry(double fps);
	private :
		int m_numberOfEntry;
		double m_showInterval;
		double* m_FPSTab;
		int m_iterateur;
		int m_entrywritten;
		double m_sum;
		sf::Clock m_clock;
		std::ostream* m_output;
	};
}