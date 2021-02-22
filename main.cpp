#include <iostream>
#include <fstream>
#include "FileIO.h"
#include "Transactions.cpp"




int main(int argc, char** argv) {
	Account accounts;
	std::string userInput;
	
	
	

	std::cout << "Welcome to WEF bank !\n";

	
	while (userInput != "exit" || userInput != "quit") {
		std::cout << "What will you be doing today?\n"; 
		std::cin >> userInput;

		
		if (userInput == "login") {
			if (accounts.login()) {
				while (true) {
					std::cout << "====Main Menu====\n";
					std::cout << "What will you be doing today?\n"; 
					std::cin >> userInput;

					if (userInput == "exit" || userInput == "quit") {
						break;
					}
					else if (userInput == "login") { 
						std::string tempuser;
						std::cin >> tempuser;
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
