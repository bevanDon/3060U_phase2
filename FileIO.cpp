#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Transactions.cpp"

Account acc;
std::string accountsFile;           //current user account file
char[100] data = {0};

bool FileIO::accountExists(Account acc){
  this->acc = acc;
  accountsFile = "../../userData" + this->acc.accountID + ".txt";	//userData - name of current user accounts
  std::ifstream inFile;
  inFile.open(accountsFile);
  inFile>>data;
  while (file >> username >> money >> type) {
		if (username == name) {
			file.close();
			return true;
		}
	}
  return false;
}

void FileIO::updateMoney(Account acc, float money){
  this->acc = acc;
  accountsFile = "../../userData" + this->acc.accountID + ".txt";	//userData - name of current user accounts
  std::ofstream outFile;
  int lineNum = 0;
  while (file >> username >> money >> type) {
		if (username == acc.accountName) {
      //Reads in userdata file to match username and find credit to update
      while (outFile >> username >> money >> type) {
        if (username == acc.accountName) {
          outFile << username << " " << money << " " << type << "\n";
        }
        else {
          outFile << username << " " << money << " " << type << "\n";
        }
      }
			outFile.close();
		}
	}
}

void FileIO::createAccount(std::string accountName, std::string acountID, float money){
  accountsFile = "../../userData" + this->acc.accountID + ".txt";
  Account temp = new Account(accountName, accountId, accountType, money);

  std::ofstream outFile;
  outFile.open(data, std::ios::app);
  if !(accountExists(temp)) {
  	outFile << accountName << " " << acountID << " " << "0" << " " << money;
  }
}

void FileIO::deleteAccount(Account acc){
  this->acc = acc;
  accountsFile = "../../userData" + this->acc.accountID + ".txt";	//userData - name of current user accounts
  if(remove(accountsFile) != 0 )
    std::cout <<"User deleted" <<std::endl;
  else
    std::cout <<"Delete unsuccessful" <<std::endl;
}
