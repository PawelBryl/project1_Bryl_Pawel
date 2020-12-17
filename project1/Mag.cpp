#include "Mag.h"

void Mag::print()
{
	Pracownik::print();
	std::string magInfo;
	magInfo += "Can Operate Forklift : ";
	magInfo += (mCanOperateForklift) ? "yes" : "no";
	std::cout << magInfo << std::endl;
	std::cout << "------------------------" << std::endl;
}

Mag::~Mag()
{
}
