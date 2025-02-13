#include "auth.h"

void authenticateUser() {
	std::string username;
	std::string password;

	do {
		std::cout << "Enter username:" << std::endl;  //Keeps prompting user to enter a username until "user5" is entered
		std::cin >> username;

		if (username != "user5") {
			std::cout << "Username does not exist" << std::endl;
		}

	} while (username != "user5");

	do {
		std::cout << "Enter password:" << std::endl; //Keeps prompting user to enter a password until "Pass321" is entered
		std::cin >> password;

		if (password != "Pass321") {
			std::cout << "Incorrect password" << std::endl;
		}

	} while (password != "Pass321");

	std::cout << "User authenticated" << std::endl;
	
}