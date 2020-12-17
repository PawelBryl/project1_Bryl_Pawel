#pragma once
#include "Firma.h"

enum Commands
{
	lp = 1, zinz = 2, zmag = 3,zmkt = 4, zrob = 5, kred = 6, bl = 7, fp = 8, kt = 9,count = 10
};

class Gra
{
public:
	Gra(int win);
	bool State() { return mState; }
	void playerAction();
	int execute();
	void printCommands();
	~Gra();
private:
	int mCode;
	bool mState;
	std::unique_ptr<Firma> mFirma;
	int mValueToWin;
	int step;
};

