#include "Process.h"

Process::~Process()
{
	delete pDuration;
}

Process::Process(int id, std::string name)
{
	Process::id = id;
	Process::name = name;	
	Process::pDuration = new Duration();
}

Process::Process(const Process & other)
{
	id = other.id;
	name = other.name;
	pDuration = new Duration(*other.pDuration);
}

Process & Process::operator=(const Process & other)
{
	
	return *(new Process(other));
}

void Process::TimeSpan(Duration & arg)
{
	Process::pDuration = &arg;
}

const Duration & Process::TimeSpan()
{
	return *pDuration;
}

const unsigned int Process::getID()
{
	return id;
}

std::ostream & operator<<(std::ostream & os, const Process & arg)
{
	os << arg.id << " " << arg.name << " " << *arg.pDuration;
	return os;
}
