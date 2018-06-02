#pragma once
#include <string>
#include <iostream>
#include "Process.h"

class ProcessChain {
	static const int MaxProcesses = 100;

	std::string name;
	Process* pChain[MaxProcesses];

	Duration CalcChainDuration();
public:
	//Constructor
	ProcessChain(std::string name);
	//Destructor
	virtual ~ProcessChain();
	//Copy Constructor
	ProcessChain(const ProcessChain& other);
	ProcessChain& operator= (const ProcessChain& other);
	//Insert new Process into chain
	bool Insert(const Process& arg);
	//output
	friend std::ostream& operator<<(std::ostream& os, const ProcessChain& arg);
};
