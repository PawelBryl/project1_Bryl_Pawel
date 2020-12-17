#include "Firma.h"
#include "RandomGenerator.h"

RandomGenerator r;

Firma::Firma(double start_balance)
{
	mEmployeeNumber = 0;
	mCountEmployees = { 0,0,0,0 };
	mAccountBalance = start_balance;
	for(size_t i=0; i<N; i++)
	{
		mHistoryPrzychod.emplace_back(r.get_random_int(10000,30000));	
	}
}

void Firma::paySalary()
{
	double wholeSalary = mCountEmployees[EmplEnum::rob] * Rob::RobSalary;
	wholeSalary += mCountEmployees[EmplEnum::inz] * Inz::InzSalary;
	wholeSalary += mCountEmployees[EmplEnum::mag] * Mag::MagSalary;
	wholeSalary += mCountEmployees[EmplEnum::mkt] * Mkt::MktSalary;
	mDochod -= wholeSalary;
}


void Firma::getPrzychod()
{
	int nRob = mCountEmployees[EmplEnum::rob];
	int nMkt = mCountEmployees[EmplEnum::mkt];
	int nMag = mCountEmployees[EmplEnum::mag];
	int nInz = mCountEmployees[EmplEnum::inz];

	mStorageCapacity = nMag * Mag::CMag;
	mProductPrice = nInz * Inz::CI;
	mDemand = nMkt * Mkt::CMkt;

	mTheoreticallyNumberProducts = nRob * Rob::CR;
	mActuallyNumberProducts = std::min(mStorageCapacity, mTheoreticallyNumberProducts);
	mNumberSoldThisMonth = std::min(mDemand, mActuallyNumberProducts);
	mPrzychod = mNumberSoldThisMonth * mProductPrice;
	mHistoryPrzychod.emplace_back(mPrzychod);
	mDochod = mPrzychod;
}


void Firma::Update()
{
	getPrzychod();	
	paySalary();
	payInstallment();
	mAccountBalance += mDochod;
}

Firma::~Firma()
{
}


void Firma::printEmployees() const
{
	if (mEmployeeNumber)
	{
		for (const auto& e : mEmployees)
		{
			e->print();
		}
	}
	else
	{
		std::cout << "Employee list is empty\n";
	}
}

double Firma::firmPrice()
{
	double sum = 0;
	int counter = 0;
	std::vector<double> lastN(mHistoryPrzychod.end() - N, mHistoryPrzychod.end());
	for(const auto& p : lastN)
	{
		sum += p;
		counter++;
	}
	return sum / counter;
}


void Firma::takeLoan(double amount, int repaymentTime)
{
	mAccountBalance += amount;
	mCredits.emplace_back(std::move(new Credit(amount, repaymentTime)));
}
void Firma::payInstallment()
{
	std::vector<size_t> finishedCredits;
	for(size_t i=0; i<mCredits.size();i++)
	{
		mCredits[i]->payInstallment();
		mDochod -= mCredits[i]->RemainingInstallments();
		if (!mCredits[i]->Duraction()) finishedCredits.emplace_back(i);
	}
	for(auto it=finishedCredits.begin(); it != finishedCredits.end(); ++it)
	{
		mCredits.erase(mCredits.begin() + *it);
	}
}


void Firma::employ(std::unique_ptr<Pracownik> employee)
{
	mEmployeeNumber++;

	if (dynamic_cast<Inz*>(employee.get())) mCountEmployees[EmplEnum::inz]++;
	if (dynamic_cast<Mkt*>(employee.get())) mCountEmployees[EmplEnum::mkt]++;
	if (dynamic_cast<Mag*>(employee.get())) mCountEmployees[EmplEnum::mag]++;
	if (dynamic_cast<Rob*>(employee.get())) mCountEmployees[EmplEnum::rob]++;
	
	mEmployees.emplace_back(std::move(employee));
}

double Firma::calcPrzychod() const
{
	return mNumberSoldThisMonth * mProductPrice;
}
