#include "Duration.h"
/*
Duration class, represents the duration of a process
*/


Duration::Duration(unsigned int h, unsigned int m, unsigned int s){
	Duration::h = h + m / 60;
	Duration::m = m % 60 + s / 60;
	Duration::s = s % 60;
}

void Duration::SetDirty(){
	isDirty = true;
}

Duration Duration::operator+(const Duration & rhs) const {
	return Add(*this, rhs);
}

Duration Duration::Add(const Duration & arg1, const Duration & arg2){
	unsigned int hours = arg1.h + arg2.h;
	unsigned int minutes = arg1.m + arg2.m;
	unsigned int seconds = arg1.s + arg2.s;

	if (seconds >= 60){
		++minutes;
		seconds -= 60;
	}

	if (minutes >= 60)	{
		++hours;
		minutes -= 60;
	}

	return Duration{ hours, minutes, seconds };
}

std::ostream & operator<<(std::ostream & os, const Duration & arg){
	os << '[' << arg.h << '|' << arg.m << '|' << arg.s << ']';
	return os;
}
