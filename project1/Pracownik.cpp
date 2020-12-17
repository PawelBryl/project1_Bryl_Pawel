#include "Pracownik.h"

void Pracownik::print()
{
	std::string basicInfo;
	basicInfo += "Name: " + mName;
	basicInfo += " Salary: " + std::to_string(mSalary);
	std::cout << basicInfo << std::endl;
}

Pracownik::~Pracownik()
{
}
