#include <iostream>
#include "FileIO.cpp"
#include "account.cpp"

class Transaction{

public:
  Transaction();
  FileIO fileIO;

  bool login(Account acc){
    if(fileIO.accountExists(acc)){
      return true;
    }
    return false;
  }

  // executes a withdrawal of funds from an account
  void withdrawl(Account acc, float withdrawAmount){
    // make sure that the account exists
    if(fileIO.accountExists(acc)){
      // make the the withdrawal amount is valid
      if(withdrawAmount > 0.0 && withdrawAmount <= 500.0){
        // make sure the account has enough money to complete the withdrawal
        if(acc.getMoney() - withdrawAmount >= 0.0){
          acc.subMoney(withdrawAmount);
          fileIO.updateMoney(acc, acc.getMoney());
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

  // deposits money into an account
  void deposit(Account acc, float depositAmount){
    // make sure that the account exists
    if(fileIO.accountExists(acc)){
      // check that there is money to deposit
      if(depositAmount > 0.0){
        acc.addMoney(depositAmount);
        fileIO.updateMoney(acc, acc.getMoney());
      }
      else{
        std::cout<<"Deposit value is invalid" << std::endl;
      }
    }
    else{
      std::cout <<"Account does not exist" << std::endl;
    }
  }

  // transfers money between two accounts
  void transfer(Account accSend, Account accReceive, float transferAmount){
    // make sure that the accounts exists
    if(fileIO.accountExists(accSend) && fileIO.accountExists(accReceive)){
      // make sure there is enough money to transfer
      if(accSend.getMoney() > transferAmount){
        accSend.subMoney(transferAmount);
        accReceive.addMoney(transferAmount);
        fileIO.updateMoney(accSend, accSend.getMoney());
        fileIO.updateMoney(accReceive, accReceive.getMoney());
      }
    }
  }

  // pays a bill to the specified company
  void paybill(Account acc, float amountToPay, std::string companyName){
    // make sure that the account exists
    if(fileIO.accountExists(acc)){
      //funds transfers cannot be used in session
      if(amountToPay > 0 && amountToPay < 2000 && amountToPay < acc.getMoney()){
        //modify account amounts
        if(companyName == "The Bright Light Electric Company(EC)"||"Credit Card Company Q(CQ)"
        ||"Fast Internet, Inc.(FI)"){
          acc.subMoney(amountToPay);
          fileIO.updateMoney(acc,acc.getMoney());
        }
      }
    }
  }

  // creates a new account
  void create(Account acc, float initialBalance, std::string accountHolderName, std::string accountID){
    // make sure the account would be valid upon creation
    if(acc.getAccountType() == 1 && initialBalance < 999999.99 && accountHolderName.length() < 20 ){
      fileIO.createAccount(accountHolderName, accountID, initialBalance);
    }
  }

  // deletes an account
  void deleting(Account acc, Account deleteAccount){
    // make sure the account is admin
    if(acc.getAccountType() == 1){
      // make sure that the account exists
      if(fileIO.accountExists(deleteAccount)){
        if(acc.getUserID() == deleteAccount.getUserID()){
          fileIO.deleteAccount(deleteAccount);
        }
      }
    }
  }

  // disables an account
  void disable(Account acc, Account disableAccount){
    // make sure that the account exists
    if(fileIO.accountExists(disableAccount)){
      // make sure the account is admin
      if(acc.getAccountType() == 1){
        if(acc.getUserID() == disableAccount.getUserID() ){
          fileIO.disableAccount(disableAccount);
        }
      }
    }
  }

  // changes the plan on an account
  void changeplan(Account acc){
    // make sure that the account exists
    if(fileIO.accountExists(acc)){
      // make sure the account is admin
      if(acc.getAccountType() == 1){
        if(acc.getPlanType() == 0){
          fileIO.changePlan(acc);
        }
      }
    }
  }

};
