#include "Mkt.h"

void Mkt::print()
{
	Pracownik::print();
	std::string mktInfo;
	mktInfo += "Number of Followers : " + std::to_string(mNumberFollowers);
	std::cout << mktInfo << std::endl;
	std::cout << "------------------------" << std::endl;
}

Mkt::~Mkt()
{
}
