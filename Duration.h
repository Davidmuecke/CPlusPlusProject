#pragma once
#include <iostream>

class Duration {
	unsigned int h = 0;
	unsigned int m = 0;
	unsigned int s = 0;

	bool isDirty = false;
public:
	//Default constructor
	Duration() = default;
	//Default destructor
	virtual ~Duration() = default;
	//Constructor with parameters for values
	Duration(unsigned int h, unsigned int m, unsigned int s);
	//Copy constructor and assignment
	Duration(const Duration& other) = default;
	Duration& operator= (const Duration& other) = default;	
	//mark object as invalid
	void SetDirty();
	//operator overloading + for a
	Duration operator+(const Duration& rhs) const;
	//c string output
	friend std::ostream& operator<<(std::ostream& os, const Duration& arg);
	//summ up two durations
	static Duration Add(const Duration& arg1, const Duration& arg2);
};
