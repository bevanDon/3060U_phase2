#include <iostream>
#include "FileIO.cpp"
#include "account.cpp"

class Transaction{

public:
  Transaction();

  bool login(Account acc){
    if(acc.accountExists(acc.accountNumber, acc.accountId)){
      return true;
    }
    return false;
  }

  void withdrawl(Account acc, float withdrawAmount){
    if(FileIO.accountExists(acc)){
      if(withdrawAmount > 0.0 && withdrawAmount <= 500.0){
        if(acc.money - withdrawAmount >= 0.0){
          acc.subMoney(withdrawAmount);
          FileIO.updateMoney(acc.money);
        }
        else{
          std::cout<<"You do not have enough funds" << std::endl;
        }
      }
      else{
        std::cout<<"Withdraw value is invalid" << std::endl;
      }
    }
    else{
      std::cout <<"Account does not exist" << std::endl;
    }
  }

  void deposit(Account acc){
    if(acc.accountExists(acc.accountHolderName,acc.accountId)){
      //funds transfers cannot be used in session
    }
  }

  void transfer(Account acc){
    if(acc.accountExists(acc.accountHolderName,acc.accountId)){
      //funds transfers cannot be used in session
      if(acc.transferAmount > 0 && acc.transferAmount < 1000){
        //modify account amounts
      }
    }
  }

  void paybill(Account acc){
    if(acc.accountExists(acc.accountHolderName,(acc.accountId)){
      //funds transfers cannot be used in session
      if(acc.amountToPay > 0 && acc.accountBalance < 2000){
        //modify account amounts
        if(acc.companyName == "The Bright Light Electric Company(EC)"||"Credit Card Company Q(CQ)"
        ||"Fast Internet, Inc.(FI)"){
          //update account bill payment
        }
      }
    }
  }

  void create(Account acc){
    if(acc.isAdmin == true && acc.intialBalance < 999999.99 && acc.accountHolderName.length() < 20 ){
      // fileIO create new bank account with initial balance
    }
  }

  void deleting(Account acc){
    if(acc.isAdmin == true){
      if(acc.accountExists(acc.accountHolderName,acc.accountId)){
        if(acc.accountId==acc.verifyDelete){
          // delete in fileIO
        }
      }
    }
  }

  void disable(Account acc){
    if(acc.accountExists(acc.accountHolderName,acc.accountId){
      if(acc.isAdmin == true){
        if( acc.accountId == acc.verifyDisable ){
          //fileIO
        }
      }
    }
  }

  void changeplan(Account acc){
    if(acc.accountExists(acc.accountHolderName,acc.accountId){
      if(acc.isAdmin == true)){
        if(acc.studentPlan == true){
          //output as studentplan
        }
      }
    }
  }

};
