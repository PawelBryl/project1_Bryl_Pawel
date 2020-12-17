#pragma once
#include <string>
#include <iostream>

class Pracownik
{
public:
	Pracownik(std::string name, float salary) : mName(name), mSalary(salary) {}
	float Salary() { return  mSalary; }
	virtual void print() = 0;
	virtual ~Pracownik();
private:
	std::string mName;
	float mSalary;
};

