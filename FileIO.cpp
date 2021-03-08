#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Account acc;
char* accountsFile;           //current user account file
char data[] = {0};

// checks to see if the account given exists
bool FileIO::accountExists(Account acc){
  accountsFile = "../../userData" + acc.getUserID() + ".txt";	//userData - name of current user accounts
  std::ifstream inFile;
  inFile.open(accountsFile);
  inFile>>data;

  // searches through all accounts
  while (file >> username >> money >> type) {
		if (username == acc.getUsername()) {
			file.close();
			return true;
		}
	}
  return false;
}

// updates the money in an account
void FileIO::updateMoney(Account acc, float money){
  accountsFile = "../../userData" + acc.getUserID() + ".txt";	//userData - name of current user accounts
  std::ofstream outFile;
  while (file >> username >> money >> type) {
		if (username == acc.getUsername()) {
      //Reads in userdata file to match username and find credit to update
      while (outFile >> username >> money >> type) {
        if (username == acc.getUsername()) {
        	outFile << acc.getUsername() << " " << acc.getUserID() << " " << acc.getAccountType() << " " << money << " " << acc.getStatus() << " " << acc.getPlanType();
        }
        else {
        	outFile << acc.getUsername() << " " << acc.getUserID() << " " << acc.getAccountType() << " " << acc.getMoney() << " " << acc.getStatus() << " " << acc.getPlanType();
        }
      }
			outFile.close();
		}
	}
}

// creates an account
void FileIO::createAccount(std::string accountName, std::string accountID, float money){
  accountsFile = "../../userData" + acc.getUserID() + ".txt";
  Account temp = new Account(accountName, accountID, accountType, money);

  std::ofstream outFile;
  outFile.open(data, std::ios::app);
  if (!accountExists(temp)) {
    outFile << acc.getUsername() << " " << acc.getUserID() << " " << 0 << " " << acc.getMoney() << " " << 0 << " " << 0;;
  }
}

// deletes an account
void FileIO::deleteAccount(Account acc){
  this->acc = acc;
  accountsFile = "../../userData" + acc.getUserID() + ".txt";	//userData - name of current user accounts
  if(remove(accountsFile) != 0 )
    std::cout <<"User deleted" <<std::endl;
  else
    std::cout <<"Delete unsuccessful" <<std::endl;
}

// disables an account
void FileIO::disableAccount(Account acc){
  this->acc = acc;
  accountsFile = "../../userData" + acc.getUserID() + ".txt";	//userData - name of current user accounts
  std::ofstream outFile;
  while (file >> username >> money >> type) {
    if (username == acc.getUsername()) {
      while (outFile >> username >> money >> type) {
        if (username == acc.getUsername()) {
        	outFile << acc.getUsername() << " " << acc.getUserID() << " " << acc.getAccountType() << " " << acc.getMoney() << " " << 1 << " " << acc.getPlanType();
        }
        else {
        	outFile << acc.getUsername() << " " << acc.getUserID() << " " << acc.getAccountType() << " " << acc.getMoney() << " " << 0 << " " << acc.getPlanType();
        }
      }
      outFile.close();
    }
  }
}

// changes the plan on an account
void FileIO::changePlan(Account acc){
  this->acc = acc;
  accountsFile = "../../userData" + acc.getUserID() + ".txt";	//userData - name of current user accounts
  std::ofstream outFile;
  while (file >> username >> money >> type) {
    if (username == acc.getUsername()) {
      while (outFile >> username >> money >> type) {
        if (username == acc.getUsername()) {
        	outFile << acc.getUsername() << " " << acc.getUserID() << " " << acc.getAccountType() << " " << acc.getMoney() << " " << acc.getStatus() << " " << 1;
        }
        else {
        	outFile << acc.getUsername() << " " << acc.getUserID() << " " << acc.getAccountType() << " " << acc.getMoney() << " " << acc.getStatus() << " " << 0;
        }
      }
      outFile.close();
    }
  }
}
