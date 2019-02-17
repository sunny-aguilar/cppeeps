/*********************************************************************
** Author:          Kuljot Biring, Rachel Schlick, Ryan Gross,
**                  Sandro Aguilar, Jeesoo Ryoo
** Date:            02/17/2019
*********************************************************************/
#include "utils.hpp"

/***************************************************************************
Description: Void method that prints welcome screen in menu; implemented
** here to avoid bloat in menu class.
***************************************************************************/
void printWelcomeScreen()
{
	std::cout << "\n\n\n"
			  << "###################################################################################################\n"
			  << "#                                                                                                 #\n"
			  << "#      WELCOME TO THE PREDATOR-PREY SIMULATION !!                                                 #\n"
			  << "#      By:   Sandro Aguilar, Kuljot Biring,                                                       #\n"
			  << "#            Ryan Gross, Jeesoo Ryoo, Rachel Schlick                                              #\n"
			  << "#                                                                                                 #\n"
			  << "#                                                                            ,_   _,              #\n"
			  << "#      ________               _________        _____                          '._.'               #\n"
			  << "#      ___  __ \\_____________ ______  /______ ___  /_______ ________     '-,   (_)   ,-'          #\n"
			  << "#      __  /_/ /__  ___/_  _ \\_  __  / _  __ `/_  __/_  __ \\__  ___/       '._ .:. _.'            #\n"
			  << "#      _  ____/ _  /    /  __// /_/ /  / /_/ / / /_  / /_/ /_  /            _ '|Y|' _             #\n"
			  << "#      /_/      /_/     \\___/ \\__,_/   \\__,_/  \\__/  \\____/ /_/           ,` `>\\ /<` `,           #\n"
			  << "#                                                                        ` ,-`  I  `-, `          #\n"
			  << "#      \\       /                             _   __ ____                   |   /=\\   |            #\n"
			  << "#       \\     /                             | | / // __/                 ,-'   |=|   '-,          #\n"
			  << "#        \\.-./                              | |/ /_\\ \\                         )-(                #\n"
			  << "#        (o\\^/o)  _   _   _     __          |___//___/                         \\_/                #\n"
			  << "#         ./ \\.\\ ( )-( )-( ) .-'  '-.                      ________                               #\n"
			  << "#          {-} \\(//  ||   \\\\/ (   )) '-.                   ___  __ \\_____________ _____  __       #\n"
			  << "#            //-__||__.-\\\\.      _.-'                      __  /_/ /__  ___/_  _ \\__  / / /       #\n"
			  << "#            (/    ()     \\)'-._.-'                        _  ____/ _  /    /  __/_  /_/ /        #\n"
			  << "#           ||    ||      \\\\                               /_/      /_/     \\___/ _\\__, /         #\n"
			  << "#           ('    ('       ')                                                     /____/          #\n"
			  << "#                                                                                                 #\n"
			  << "#                                                                                                 #\n"
			  << "#      [Extra Credit]                                                                             #\n"
			  << "#      * The size of the grid rows and columns                                                    #\n"
			  << "#      * The number of ants                                                                       #\n"
			  << "#      * The number of doodlebugs                                                                 #\n"
			  << "#                                                                                                 #\n"
			  << "###################################################################################################\n\n";
}

/***************************************************************************
Description: Method that generates a random number based on the input parameters
** (min/max); returns an int.
** References Used: https://en.cppreference.com/w/cpp/numeric/random/rand
**			  		https://en.cppreference.com/w/cpp/numeric/random
**			  		http://www.cplusplus.com/reference/random/
***************************************************************************/
int generateRandomNumber(int min, int max)
{
	std::random_device r;
	std::default_random_engine e1(r());

	std::uniform_int_distribution<int> uniform_dist(min, max);
	return uniform_dist(e1);
}

/***************************************************************************
Description: Takes in a max range as an int and returns a randomly generated
** int within said range.
***************************************************************************/
int generateRandomNumber(int max)
{
	return generateRandomNumber(1, max);
}