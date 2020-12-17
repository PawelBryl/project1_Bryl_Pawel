#include "Rob.h"

void Rob::print()
{
	Pracownik::print();
	std::string robInfo;
	robInfo += "Shoe size is : " + std::to_string(mShoeSize);
	std::cout << robInfo << std::endl;
	std::cout << "------------------------" << std::endl;
}

Rob::~Rob()
{
}
