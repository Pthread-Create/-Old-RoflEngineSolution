#pragma once
#include "Point.h"

namespace fi{
	class Segment{
	public:
		Segment(fi::Point& a, fi::Point& b);
		fi::Point* intersect(fi::Segment& b);
		friend std::ostream& operator<<(std::ostream& stream, const Segment& s);
	private:
		fi::Point* a;
		fi::Point* b;
	};
}