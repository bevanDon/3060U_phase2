/*
Header file to handle all read/write to the files:
dailyTransactions.txt
userData.txt
availableItems.txt
This file is complete
*/
#pragma once

#include <iostream>

class FileIO {
    std::string userData;           //current user account file
    std::string transactionsFile;    //daily transaction file
    std::string availableItems;     //available items file

public:
    FileIO();     
    void login(std::string accountNumber, std::string accountID);
    void withdrawal(std::string accountHoldername,std::string accountID,  )

    /*                                                  //Default empty constructor for fileIO, defines text files
    void setIteration(std::string iteration);
    void setUserData(std::string currentUsers);
    void setAvailableItems(std::string availables);
    
    bool logUserIn(std::string username);                           //function to read user accounts file to check if user exist 
    std::string getAccountType(std::string username);                      //function to read user accounts file to check the user account types 
    float getUserCredit(std::string username);                      //function to read user accounts file to view user's credit 
    void setUserCredit(std::string username, float newCredit);      //function to read user accounts file to add credit to user 
    bool createNewUser(std::string username, std::string type);     //function to read user accounts file to add new user in create() 
    bool deleteUser(std::string username);                          //function to read user accounts file to delete current user in deleteUser() 
    void generateDailyTransaction(std::string log);                 //function to append transaction log to file
    bool itemExists(std::string username, std::string itemName);
    void refundUser(std::string buyer, std::string seller, float credit);
    */
};