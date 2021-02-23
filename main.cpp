#include <iostream>
#include <fstream>
#include "FileIO.h"
#include "Transactions.cpp"



/*
Main is used to run the bank terminal using command prompt
User data is read in using FileIO and the data is saved using the Account class
Transactions hold the methods for banking actions
saved userdata into output files
*/
int main(int argc, char** argv) {
	Account accounts;
	std::string userInput;
	std::cout << "Welcome to WEF bank !\n";

	// Creates terminal for banking system 
    // exits on user input "exit" or quit
	while (userInput != "exit" || userInput != "quit") {
		std::cout << "What will you be doing today?\n"; 
		std::cin >> userInput;

		// user is allowed to access transaction methods if they are succesfully logged in
		if (userInput == "login") {
			if (accounts.login()) {
				while (true) {
					std::cout << "====Main Menu====\n";
					std::cout << "What will you be doing today?\n"; 
					std::cin >> userInput;

					if (userInput == "exit" || userInput == "quit") {
						break;
					}
					else if (userInput == "login") {  // login into users account and grants access to transactions methods
						std::string tempUser;
						std::cin >> tempUser;
						std::cout << "Login Error: Already logged in\n";
					}
					else if (userInput == "withdraw") {  
						accounts.logout();
						break;
					}
                    else if (userInput == "logout") { 
						accounts.addCredit();
					}
					else if (userInput == "transfer") { 
						accounts.create();
					}
					else if (userInput == "paybill") { 
						accounts.deleteUser();
					}
					else if (userInput == "deposit") { 
						accounts.advertise();
					}
					else if (userInput == "create") { 
						accounts.bid();
					}
					else if (userInput == "disable") { 
						accounts.refund();
					}
					else if (userInput == "changeplan") { 
						accounts.addCredit();
					}
					else { 
						std::cout << "Unrecognized command try again:\n";

					}
				}
			}
			if (command == "logout") {
				break;
			}

		}
		else if (command == "logout") {
			std::cout << "Logout Error: Not logged in\n";
		}
		else if (command == "quit" || command == "exit") {
			break;
		}
		else {
			std::cout << "Unrecognized command or not logged in\nTry 'login'\n";
		}
	}

	return 0;
}
