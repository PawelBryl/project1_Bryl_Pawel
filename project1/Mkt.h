#pragma once
#include "Pracownik.h"


class Mkt : public Pracownik
{
public:
	const static int CMkt = 120;
	constexpr static float MktSalary = 10000;
	Mkt(std::string name, int numberfollowers) : Pracownik(name, MktSalary)
	{
		mNumberFollowers = (numberfollowers) ? numberfollowers : 0;
	}
	void print() override;
	~Mkt();
private:
	int mNumberFollowers;
};

