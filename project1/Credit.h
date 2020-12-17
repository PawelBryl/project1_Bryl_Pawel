#pragma once
class Credit
{
public:
	Credit(double amount, int time);
	void payInstallment();
	int Duraction() { return mDuration; }
	int RemainingInstallments() { return mRemainingInstallments; }
	~Credit();
private:
	int mDuration;
	double mProcent;
	double mRemainingInstallments;
};

