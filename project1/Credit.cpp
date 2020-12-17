#include "Credit.h"

#include <cmath>

Credit::Credit(double amount, int time)
{
	mDuration = time;
	
	if (time < 12) mProcent = 9;
	else if (time >= 12 && time <= 24) mProcent = 15;
	else if (time > 24 && time <= 36) mProcent = 18;
	else if (time > 36 && time <= 50) mProcent = 22;
	else if (time > 50 && time <= 75) mProcent = 27;
	else if (time > 75) mProcent = 35;
	double MonIntRate = (mProcent / 100) / 12;
	double monthly_amount = amount * (MonIntRate + (MonIntRate / (pow(1 + MonIntRate, time) - 1)));
	mRemainingInstallments = monthly_amount;
}

void Credit::payInstallment()
{
	mDuration--;
}

Credit::~Credit()
{
}
