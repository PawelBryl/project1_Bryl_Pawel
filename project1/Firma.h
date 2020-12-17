#pragma once

#include <vector>
#include <memory>
#include <array>

#include "Inz.h"
#include "Mag.h"
#include "Mkt.h"
#include "Rob.h"
#include "Credit.h"

const int N = 12;

enum EmplEnum { inz = 0, mkt = 1, mag = 2, rob = 3  };

class Firma
{
public:
	Firma(double start_balance);
	void printEmployees() const;
	void takeLoan(double amount, int repaymentTime);
	void employ(std::unique_ptr<Pracownik> employee);
	void paySalary();
	void getPrzychod();
	void payInstallment();
	double AccountBalance() const { return mAccountBalance; };
	double firmPrice();
	double calcPrzychod() const;
	double Dochod() const { return mDochod; }
	void Update();
	~Firma();
private:
	double mAccountBalance;
	int mEmployeeNumber;
	std::vector<std::unique_ptr<Credit>> mCredits;
	std::vector<std::unique_ptr<Pracownik>> mEmployees;
	std::array<int, 4> mCountEmployees;
	
	double mStorageCapacity;
	double mProductPrice;
	double mDemand;
	double mTheoreticallyNumberProducts;
	double mActuallyNumberProducts;
	int mNumberSoldThisMonth;
	double mPrzychod;
	double mDochod;

	std::vector<double> mHistoryPrzychod;
};

