#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	prng = std::mt19937{ std::random_device{}() };
	first_names = {
	"Ann",       "Andrew", "John",    "Jane",  "Bob",   "Alice",  "Bertram", "Monica",
	"Laura",     "Eric",   "Richard", "Karen", "Clara", "Rupert", "Bruce",   "Martha",
	"Elizabeth", "Corey",  "Nancy",   "Joe",   "Amy",   "Mike",
	};
	last_names = {
	"Hendricks", "Smith",   "Gates",  "Stein",     "Warren",  "Booker", "Williamson", "Walters",
	"Dunn",      "Swanson", "Knope",  "Haverford", "Ludgate", "Meagle", "Favreau",    "Vietor",
	"Lovett",    "Pfeifer", "Rhodes", "Abrams",    "McFaul",  "Stone",  "Sisley",     "Hanneman",
	};
}

std::string RandomGenerator::get_random_name()
{
	std::uniform_int_distribution< std::size_t > fnd{ 0, first_names.size() - 1 };
	std::uniform_int_distribution< std::size_t > lnd{ 0, last_names.size() - 1 };
	std::stringstream                            name;
	name << first_names[fnd(prng)] << ' '
		<< last_names[lnd(prng)];
	return name.str();
}

int RandomGenerator::get_random_int(int from, int to)
{
	std::uniform_int_distribution<> distr(from, to);
	return distr(prng);
}
