#pragma once
#include <string>
#include <iostream>
#include "Duration.h"

class Process {
	int id;
	std::string name;
	Duration* pDuration = nullptr;

public:
	//Default Constructor
	Process() = default;
	//Default Destrcutor
	virtual ~Process();
	//Costructor with values
	Process(int id, std::string name);
	//Copy Constructor
	Process(const Process& other);
	Process& operator= (const Process& other);
	// set TimeSpan
	void TimeSpan(Duration& arg);
	//get TimeSpan
	const Duration& TimeSpan();
	// get ID
	const unsigned int getID();
	//stream operator overload
	friend std::ostream& operator<<(std::ostream& os, const Process& arg);
	
};
