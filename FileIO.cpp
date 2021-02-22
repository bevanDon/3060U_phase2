#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Transactions.cpp"

Account acc;
std::string accountsFile;           //current user account file
char[100] data = {0};

FileIO::FileIO(Account acc) {
  this->acc = acc;
	accountsFile = "../../userData" + this->acc.accountID + ".txt";	//userData - name of current user accounts
}

bool FileIO::userExists(){
  std::ifstream inputFile;
  inputFile.open(accountsFile);
  inputFile>>data;
  if(inputFile.is_open() && data[0] != 0){
    return true;
  }
  else{
    return false;
  }
}
