/*
User class
*/
#include <iostream>

class Account{
  std::string accountName; //accountName for user login
  std::string accountID; //account ID for user login
  int accountType; //Type of account (standard = 0, admin = 1)
  float money; //value in the users account
  int isActive; //0 = active, 1 = inactive
  int planType; //0 = student, 1 = regular

public:
  //default constructor
  User(){
    this->accountName = "";
    this->accountID = "";
    this->accountType = 0;
    this->money = 0.00;
    this->isActive = 0;
    this->planType = 0;
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
    this->money = this->money - money;
  }

  int getStatus(){
      return this->isActive;
  }

  void updateStatus(int newStatus){
    this->isActive = newStatus;
  }


  int getPlanType(){
    return this->planType;
  }

  void updatePlanType(int newPlanType){
    this->planType = newStatus;
  }

};
