#include "Gra.h"
#include "RandomGenerator.h"

RandomGenerator r1;
const int M = 3;

Gra::Gra(int win)
{
	mState = true;
	mFirma = std::make_unique<Firma>(20000);
	mFirma->employ(std::make_unique<Inz>(r1.get_random_name(),"RadioTechnical"));
	mFirma->employ(std::make_unique<Mag>(r1.get_random_name(),true));
	mFirma->employ(std::make_unique<Mkt>(r1.get_random_name(),5000));
	mFirma->employ(std::make_unique<Rob>(r1.get_random_name(),43));

	mValueToWin = win;
	step = 1;
}


int Gra::execute()
{
	printCommands();
	
	while (mState)
	{
		if(mFirma->AccountBalance() < 0)
		{
			std::cout << "You lose\n";
			break;
		}
		double price = mFirma->firmPrice();
		if(price > mValueToWin)
		{
			std::cout << "You Win\n";
			break;
		}
		playerAction();
	}
	return 0;
}

void Gra::playerAction()
{
	std::cout << "Input a command code (1-9)\n";
	std::cin >> mCode;
	switch (mCode)
	{
	case Commands::lp:
	{
		mFirma->printEmployees();
		break;
	}
	case Commands::zinz:
	{
		std::string faculty;
		std::cout << "Input Faculty and press Enter\n";
		std::cin >> faculty;
		mFirma->employ(std::make_unique<Inz>(r1.get_random_name(), faculty));
		std::cout << "New engineer is successfully hired\n";
		break;
	}
	case Commands::zmag:
	{
		bool canOperate;
		std::cout << "Can operate forklift if yes press 'y' else 'n'\n";
		while (true)
		{
			int kodASCII = getchar();
			if (kodASCII == 'y')
			{
				canOperate = true;
				break;
			}
			else if (kodASCII == 'n')
			{
				canOperate = false;
				break;
			}
			else
			{
				std::cout << "Please input y or n\n";
			}
		}
		mFirma->employ(std::make_unique<Mag>(r1.get_random_name(), canOperate));
		std::cout << "New warehouseman is successfully hired\n";
		break;
	}
	case Commands::zmkt:
	{
		int followers;
		std::cout << "Input Followers number and press Enter\n";
		while (true)
		{
			std::cin >> followers;
			if (std::cin)
			{
				mFirma->employ(std::make_unique<Mkt>(r1.get_random_name(), followers));
				std::cout << "New marketer is successfully hired\n";
				break;
			}
			else
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "It is not number\n";
			}
		}
		break;
	}
	case Commands::zrob:
	{
		double size;
		std::cout << "Input Shoe size in range 35-46 and press Enter\n";
		while (true)
		{
			std::cin >> size;
			if (std::cin)
			{
				if (size >= 35 && size <= 46)
				{
					mFirma->employ(std::make_unique<Rob>(r1.get_random_name(), size));
					std::cout << "New worker is successfully hired\n";
					break;
				}
				else std::cout << "Please input correct size\n";
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "It is not number\n";
			}
		}
		break;
	}
	case Commands::kred:
	{
		double amount;
		int time;
		std::cout << "Please input loan amount and time\n";
		while (true)
		{
			std::cin >> amount >> time;
			if (std::cin)
			{
				if (time <= 0) std::cout << "Sorry, min time is 1 month, try more\n";
				else if (time > 100) std::cout << "Sorry, max time is 100 months, try less\n";
				else if (amount < 1000) std::cout << "Sorry, min amount is 1000, try more\n";
				else if (amount > M * mFirma->firmPrice()) std::cout << "Sorry, we cant give you so high credit\n";
				else break;
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please input correct data\n";
			}
		}
		mFirma->takeLoan(amount, time);
		std::cout << "Loan is successfully taken\n";
		break;
	}
	case Commands::kt:
	{
		mFirma->Update();
		std::cout << "-------------------------\n";
		std::cout << "Month " << step << ":\n";
		std::cout << "Dochod in next month: " << mFirma->Dochod() << ":\n";
		std::cout << "-------------------------\n";
		step++;
		break;
	}
	case Commands::bl:
	{
		std::cout << "Account Balance=" << mFirma->AccountBalance() <<std::endl;
		break;
	}
	case Commands::fp:
	{
		std::cout << "Firm price=" << mFirma->firmPrice() << std::endl;
		break;
	}
	default:break;
	}
}

void Gra::printCommands()
{
	std::cout << "List commands:\n";
	for (size_t i = 1; i < Commands::count; i++)
	{
		switch (i)
		{
		case Commands::lp:
			{
				std::cout << "1. Print list of Employees\n";
				break;
			}
		case Commands::zinz:
			{
				std::cout << "2. Employ engineer\n";
				break;
			}
		case Commands::zmag:
			{
				std::cout << "3. Employ warehouseman\n";
				break;
			}
		case Commands::zmkt:
			{
				std::cout << "4. Employ marketer\n";
				break;
			}
		case Commands::zrob:
			{
				std::cout << "5. Employ worker\n";
				break;
			}
		case Commands::kred:
			{
				std::cout << "6. Take a loan\n";
				break;
			}
		case Commands::bl:
		{
			std::cout << "7. Account Balance\n";
			break;
		}
		case Commands::fp:
		{
			std::cout << "8. Firm price\n";
			break;
		}
		case Commands::kt:
		{
			std::cout << "9. End the turn\n";
			break;
		}
		default:break;
		}
	}
}

Gra::~Gra()
{
}
