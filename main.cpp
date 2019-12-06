/* Example taken 22.6.2019 from https://en.cppreference.com/w/cpp/language/main_function */

// Required libraries
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Required includes
//#include "src/ClassHpp.hpp"

int RollADice(int _diceNumber, int _dice) {
	std::cout << "Rolling " << _diceNumber << "d" << _dice << std::endl;


	int value = 0;
	for(int i = 0; i < _diceNumber; i++) {
		value += rand() % _dice + 1;
	}
	std::cout << "Rolled: " << value << std::endl;
	return value;
}

int checkArgument(char* argument) {
	//Argument checker function
	std::cout << "- Arg: " << argument << std::endl;
	std::string s = (argument);

	int position = s.find("d");
	int number1 = atoi( s.substr(0, position).c_str() );
	int number2 = atoi( s.substr(position+1, (s.length()-1)).c_str() );

	if(number1 == 0) number1 = 1;
	if(number2 == 0) number2 = 1;

	std::cout << "args: " << number1 << ", " << number2 << std::endl;
	return RollADice(number1, number2);
}

int main(int argc, char *argv[]) {
	// argc = arguments count
	// argv = argument array

	// Initialize SRand seed
	srand (time(NULL) * 3.14159 * 987654321 / 1.6180339887);

	//std::cout << "Checking arguments:" << std::endl;
	//First argument is the filename which you run
	int totalResult = 0;
	for(int i = 1; i < argc; i++) {
		totalResult = checkArgument(argv[i]);
	}

	if ( argc > 2 ) {
		std::cout << "Rolled in total: " << totalResult << std::endl;
	}
	return 0;
}
