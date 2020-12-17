#include "Inz.h"

void Inz::print()
{
	Pracownik::print();
	std::string inzInfo;
	inzInfo += "Faculty: " + mFacultyName;
	std::cout << inzInfo << std::endl;
	std::cout << "------------------------" << std::endl;
}

Inz::~Inz()
{
}

