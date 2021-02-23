#include <iostream>
#include "FileIO.cpp"
#include "account.cpp"

class Transaction{

public:
  Transaction();
  FileIO fileIO;

  bool login(Account acc){
    if(fileIO.accountExists(acc.accountNumber, acc.accountID)){
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

  void paybill(Account acc, float amountToPay, std::string companyName){
    if(fileIO.accountExists(acc)){
      //funds transfers cannot be used in session
      if(amountToPay > 0 && amountToPay < 2000 && amountToPay < acc.money){
        //modify account amounts
        if(companyName == "The Bright Light Electric Company(EC)"||"Credit Card Company Q(CQ)"
        ||"Fast Internet, Inc.(FI)"){
          acc.subMoney(amountToPay);
          fileIO.updateMoney(acc,acc.money);
        }
      }
    }
  }

  void create(Account acc, float initialBalance, std::string accountHolderName, int accountID){
    if(acc.accountType == 1 && intialBalance < 999999.99 && accountHolderName.length() < 20 ){
      fileIO.createAccount(accountHolderName, accountID, 0 , initialBalance);
    }
  }

  void deleting(Account acc, Account deleteAccount){
    if(acc.accountType == 1){
      if(fileIO.accountExists(deleteAccount)){
        if(acc.accountID == deleteAccount.deleteUserID){
          fileIO.deleteAccount(deleteAccount);
        }
      }
    }
  }

  void disable(Account acc, Account disableAccount){
    if(fileIO.accountExists(disableAccount){
      if(acc.accountType == 1){
        if(acc.accountID == disableAccount.accountID ){
          fileIO.disableAccount(disableAccount);
        }
      }
    }
  }

  void changeplan(Account acc){
    if(acc.accountExists(acc.accountHolderName,acc.accountId){
      if(acc.accountType == 1)){
        if(acc.planType == 0){
          fileIO.changePlan(acc);
        }
      }
    }
  }

};
