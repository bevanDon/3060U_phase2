
#include <iostream>

class Transaction{
  

public:
     // methods for banking transactions
    Transaction();     
    bool login(std::string accountNumber, std::string accountId){
        if(FileIO.accountExists(accountNumber,accountId)){
            return true;
        }
            return false;
        
     
    }
    void withdrawal(std::string accountHolderName,std::string accountId,float withdrawAmount,float accountBalance){
         if(FileIO.accountExists(accountHolderName,accountId)){
          
        }
           
        if(withdrawAmount > 0.0 && withdrawAmount <= 500.0){
            //update account
            //fileio update user account 
            // should save this information for the bank account transaction file
            
        }
        


    };
    void deposit(std::string accountHolderName,std::string accountId,float depositAmount){
          if(FileIO.accountExists(accountHolderName,accountId)){
              //funds transfers cannot be used in session
           
        }
          
       
    }

    void transfer(std::string accountHolderName,std::string accountId,std::string recieverId,float transferAmount){
          if(FileIO.accountExists(accountHolderName,accountId)){
              //funds transfers cannot be used in session
            if(transferAmount <1000 && transferAmount > 0){
             //modify account amounts
            }
            
        }
          
          
    }
    void paybill(std::string accountHolderName,std::string accountId,float amountToPay,float accountBalance,std::string companyName){
         if(FileIO.accountExists(accountHolderName,accountId)){
              //funds transfers cannot be used in session

            if(amountToPay < 2000 && accountBalance> 0){
             //modify account amounts
             if(companyName == "The Bright Light Electric Company(EC)"||"Credit Card Company Q(CQ)"
             ||"Fast Internet, Inc.(FI)"){
                 //update account bill payment
             }
            }
            
        }
         
          
    }

    
    void create(std::string accountHolderName,float intialBalance,bool isAdmin)
    {
         if(isAdmin == true && intialBalance < 999999.99 && accountHolderName.length() < 20 ){
             // fileIO create new bank account with initial balance


         }

         
          
    };
    void deleting(std::string accountHolderName,std::string accountId,bool isAdmin,std::string verifyDelete){
       
        if(isAdmin == true){
             
            if(FileIO.accountExists(accountHolderName,accountId)){
                   if(accountId==verifyDelete){
                       // delete in fileIO
                   }
            }
            

         }
    }

    void disable(std::string accountHolderName,std::string accountId,bool isAdmin,std::string verifyDisable)
    {
        if(isAdmin == true){
             
            if(FileIO.accountExists(accountHolderName,accountId)){
                   if(accountId==verifyDisable){
                       //fileIO
                   }
            }
            

         }

    }
    void changeplan(std::string accountHolderName,std::string accountId,bool studentPlan,bool isAdmin)
    {
        if(isAdmin == true){
             if(FileIO.accountExists(accountHolderName,accountId)){
                  if(studentPlan == true){
                      //output as studentplan
                  }
            }


        }

    }


    
};

