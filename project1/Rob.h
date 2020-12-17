#pragma once
#include "Pracownik.h"

class Rob : public Pracownik
{
public:
	const static int CR = 200;
	constexpr static float RobSalary = 6000;
	Rob(std::string name, float shoesize): Pracownik(name, RobSalary)
	{
		mShoeSize = shoesize;
	}
	void print() override;
	~Rob();
private:
	float mShoeSize;
};

