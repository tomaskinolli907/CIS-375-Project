#pragma once
#include "Account.h"
#include <string>
using namespace std;

//Payment class is directly inherited from Account class publicly
//As a result Payment class object has now acces to all the public and protected membres and methods of Account class
class Payment:public Account
{
private:
     string first_name_on_card;
     string last_name_on_card;
     string card_Number;
     string securityCode;
     int  expiration_date_month;
     int expiration_date_year;

public:
     //Deafult Constructor
     Payment();

     //check whether card number or not
     bool isCardNumberValid(string cardNumber);

     //setter method for card number
     void setCardNumber ( string cardNumber);

     //getter method for card number
     string getCardNumber();

     //check the validity of the first name
     //first name of the account holder and first name on the card must be same
     bool isfirstNameOnCardValid(string name);

     //setter for first name on the card
     void setFirstNameOnCard(string name);

     //getter for first_name_on_card
     string getFirstNameOnCard();

     //check the validity of the last name
     //last name of the account holder and last name on the card must be same
     bool isLastNameOnCardValid(string name);

     //setter for last_name_on_card member
     void setLastNameOnCard(string name);

     //getter method for last name
     string getLastNameOnCard();

     //check month of the experiation date of the card
     bool isMonthValidOnCrad(string month);

     //check year of the experiation date of the card
     bool isYearValidOnCard(string year);

     //check the validity of security code
     void setExpirationDateOfCard();

     //getter for expiration month
     int getCradExpirationMonth() {
          return this->expiration_date_month;
     }

     //getter for card expiration year
     int getCardExpirationYear() {
          return this->expiration_date_year;
     }

     //check the validity of code
     bool isSecurityCodeValid(string code);

     //setter for security code
     void setSecurityCode(string code);

     //getter for security code
     string getSecurityCode() {
          return this->securityCode;
     }
     
};

