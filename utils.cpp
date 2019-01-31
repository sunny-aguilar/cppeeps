/*********************************************************************
** Program name: 		utils.cpp
** Author: 				Kuljot Biring, Rachel Schlick, Ryan Gross,
** 						Sandro Aguilar, Jeesoo Ryoo
** Date: 				02/17/2019
** Description: 		Util functions can be used in multiple places
*********************************************************************/
#include "utils.hpp"
#include <random>

/***************************************************************************
Description: generating random function in ranges

Usage: 
generateRandomNumber(100) // return random number between 1~100
generateRandomNumber(10, 20) // return random number between 10~20
***************************************************************************/

int generateRandomNumber(int min, int max) {
	// NOTE: rand() is not recommended for serious random-number generation needs. For more details:
	// https://en.cppreference.com/w/cpp/numeric/random/rand

	// Instead, it is recommanded to use <random> library. For more details:
	// https://en.cppreference.com/w/cpp/numeric/random
	// http://www.cplusplus.com/reference/random/


	// Seed with a real random value, if available
	std::random_device r;
	std::default_random_engine e1(r());

	// Choose a random mean between min and max number
	std::uniform_int_distribution<int> uniform_dist(min, max);
	return uniform_dist(e1);
}

int generateRandomNumber(int max) {
	return generateRandomNumber(1, max);
}