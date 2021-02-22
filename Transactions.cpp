#include <iostream>
#include "fileIO.cpp"
#include "account.cpp"

class Transaction{

public:
  Transaction();
  FileIO fileIO;

  bool login(Account acc){
    if(acc.accountExists(acc.accountNumber, acc.accountId)){
      return true;
    }
    return false;
  }

  void withdrawl(Account acc, float withdrawAmount){
    if(fileIO.accountExists(acc)){
      if(withdrawAmount > 0.0 && withdrawAmount <= 500.0){
        if(acc.money - withdrawAmount >= 0.0){
          acc.subMoney(withdrawAmount);
          fileIO.updateMoney(acc, acc.money);
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

  void deposit(Account acc, float depositAmount){
    if(fileIO.accountExists(acc)){
      if(depositAmount > 0.0){
        acc.addMoney(depositAmount);
        fileIO.updateMoney(acc, acc.money);
      }
      else{
        std::cout<<"Deposit value is invalid" << std::endl;
      }
    }
    else{
      std::cout <<"Account does not exist" << std::endl;
    }
  }

  void transfer(Account accSend, Account accReceive, float transferAmount){
    if(fileIO.accountExists(accSend) && fileIO.accountExists(accReceive)){
      if(accSend.money > transferAmount){
        accSend.subMoney(transferAmount);
        accReceive.addMoney(transferAmount);
        fileIO.updateMoney(accSend, accSend.money);
        fileIO.updateMoney(accReceive, accReceive.money);
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
