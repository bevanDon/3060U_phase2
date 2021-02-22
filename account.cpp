/*
User class
*/
#include <iostream>

class Account{
  std::string accountName; //accountName for user login
  std::string accountID; //account ID for user login
  int accountType; //Type of account (standard = 0, admin = 1)
  float money; //value in the users account

public:
  //default constructor
  User(){
    this->accountName = "";
    this->accountID = "";
    this->accountType = 0;
    this->money = 0.00;
  }

  //constructor
  User(std::string accountName, std::string accountID, int accountType, float money){
    this->accountName = accountName;
    this->accountID = accountID;
    this->accountType = accountType;
    this->money = money;
  }

  std::string getUsername(){
    return this->accountName;
  }

  void setUsername(std::string accountName){
    this->accountName = accountName;
  }

  std::string getUserID(){
    return this->accountID;
  }

  void setUserID(std::string accountID){
    this->accountID = accountID;
  }

  int getAccountType(){
    return this->accountType;
  }

  void setAccountType(int accountType){
    this->accountType = accountType;
  }

  float getMoney(){
    return this->money;
  }

  void addMoney(float money){
    this->money = this->money + money;
  }

  void subMoney(float money){
    this-> = this->money - money;
  }

};
