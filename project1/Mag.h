#pragma once
#include "Pracownik.h"

class Mag : public Pracownik
{
public:
	const static int CMag = 100;
	constexpr  static float MagSalary = 10000;
	Mag(std::string name, bool canOperateForklift) : Pracownik(name, MagSalary), mCanOperateForklift(canOperateForklift){}
	void print() override;
	~Mag();
private:
	bool mCanOperateForklift;
};

