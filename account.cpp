/*
User class
*/

#include <iostream>

class Account{
  std::string username; //Username for user login
  int userID; //User ID for user login
  int userType; //Type of user (standard = 0, admin = 1)
  float money; //amount of money in the users account

public:
  //default constructor
  User(){
    this->username = "";
    this->userID = 0;
    this->userType = 0;
    this->money = 0;
  }

  //constructor
  User(std::string username, int userID, int userType, float money){
    this->username = username;
    this->userID = userID;
    this->userType = userType;
    this->money = money;
  }

  std::string getUsername(){
    return this->username;
  }

  void setUsername(std::string username){
    this->username = username;
  }

  int getUserID(){
    return this->userID;
  }

  void setUserID(int userID){
    this->userID = userID;
  }

  int getUserType(){
    return this->userType;
  }

  void setUserID(int userID){
    this->userType = userType;
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
