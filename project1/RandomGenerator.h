#pragma once

#include <array>
#include <random>
#include <sstream>
#include <string>

class RandomGenerator
{
public:
	RandomGenerator();
    std::string get_random_name();
	int get_random_int(int from, int to);
private:
	std::mt19937 prng;
	std::array<std::string, 22> first_names;
	std::array<std::string, 24> last_names;
	
};

