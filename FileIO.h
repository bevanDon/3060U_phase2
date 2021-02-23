#pragma once

#include <iostream>
#include "account.cpp"

class FileIO {
  Account acc;
  std::string accountsFile;           //current user account file
  char[100] data;

public:
     // methods for banking transactions
    FileIO();
    void login(std::string accountNumber, std::string accountId);
    bool accountExists(Account acc);
    void updateMoney(Account acc, float money);
    void createAccount(std::string accountName, std::string acountID, float money);
    void deleteAccount(Account acc);
    void disableAccount(Account acc);
    void changePlan(Account acc);
};
