#pragma once
#include "Pracownik.h"

class Inz : public Pracownik
{
public:
	const static int CI = 200;
	constexpr static float InzSalary = 12000;
	Inz(std::string name, std::string facultyName) : Pracownik(name, InzSalary)
	{
		if (facultyName != "") mFacultyName = facultyName;
	}
	void print() override;
	~Inz();
private:
	std::string mFacultyName;
};

