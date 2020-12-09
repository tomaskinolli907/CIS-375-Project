#include "Payment.h"
#include <string>
#include <set>
#include <sstream> 
using namespace std;

//Default Constructor
Payment::Payment() {
     //let's set all the member variables value to NULL
     this->first_name_on_card = "";
     this->last_name_on_card = "";
     this->card_Number = "";
     this->expiration_date_month = NULL;
     this->expiration_date_year= NULL;
     this->securityCode = "";
}

//check whether card number is valid or not
bool Payment::isCardNumberValid(string cardNumber) {
   //first the card number has to be 19 characters
   //16 digits and 3 spaces
   //there has to be atleast 4 different digits

   //first check the length
     if (cardNumber.length() != 19) {
          cout << "Card Number Length has to be 19!" << endl;
          return false;
     }

   //now check whether there is at least four different digits or not
   //to verify that, we will use set data structure
   set <char> mySet;
   for (int i = 0; i < cardNumber.length(); i++) {
        if (cardNumber[i] != ' ') {
             mySet.insert(cardNumber[i]);
        }
   }
   if (mySet.size() < 4) {
        cout << "Not Four Different Digits!" << endl;
        return false;
   }
   mySet.clear();//free additional allocated memory

   //now lets check whether there is space after every four digits
   //if not then card number is not valid
   for (int i = 4; i < cardNumber.size(); i = i+5) {
        if (cardNumber[i] != ' ') {
             cout << "Error with space position!" << endl;
             return false; //if this particcular char is not space then card is not valid. false
        }
   }

   //now check number of spaces
   int numSpaces = 0;
   for (int i = 0; i < cardNumber.size(); i++) {
        if (cardNumber[i] == ' ') {
             numSpaces++;
        }
   }

   if (numSpaces != 3)
   {
        cout << "Error with numer of spaces!" << endl;
        return false;
   }
   
   //now check number of total digits
   int numDogits = 0;
   for (int i = 0; i < cardNumber.size(); i++) {
        if (cardNumber[i] != ' ') {
             if (isdigit(cardNumber[i])) {
                  numDogits++;
             }
        }
   }
   if (numDogits != 16)
   {
        cout << "Error with number of digits!" << endl;
        return false;
   }

   else return true;//by now we have checked everything a valid card number should contain
  
}


//setter method for card number
void Payment::setCardNumber(string cardNumber) {
   
     while (!isCardNumberValid(cardNumber)) {
          cout << "Enter Again: " << endl;
          getline(cin, cardNumber);
     }

     //now we have got a valid card number
     this->card_Number = cardNumber;

}

//return card number (set by the user)
string Payment::getCardNumber() {
     return this->card_Number;
}


//check the validity of the first name
//first name of the account holder and first name on the card must be same
bool Payment::isfirstNameOnCardValid(string name) {
     return  (name == this->getFirstName());//will return true if account holder first name is same as card first name
}

//setter for first name on the card
void Payment::setFirstNameOnCard(string name) {
     while (!isfirstNameOnCardValid(name)) {
          cout << "First Name on card is not account holder's first name!" << endl;
          cout << "Enter Again: " << endl;
          getline(cin, name);
     }
     //Now, we got the valid user first name
     this->first_name_on_card = name;
}

//getter for first_name_on_card
string Payment::getFirstNameOnCard() {
     return this->first_name_on_card;
}


//check the validity of the last name
     //last name of the account holder and last name on the card must be same
bool Payment::isLastNameOnCardValid(string name) {
     return (this->getLastName() == name);//will return true if accountholders last name is same as given card last name
}

//setter for last_name_on_card member
void Payment::setLastNameOnCard(string name) {
     while (!isLastNameOnCardValid(name)) {
          cout << "Last Name on card is not account holder's Last name!" << endl;
          cout << "Enter Again: " << endl;
          getline(cin, name);
     }
     //now we've got the desired last name
     this->last_name_on_card = name;
}

//getter method for last name
string Payment::getLastNameOnCard() {
     return this->last_name_on_card;
}


//check month of the experiation date of the card
bool Payment::isMonthValidOnCrad(string month)
{
     if (month.length() != 2) {
          return false; // length must be 2 . (e.g. 02 or 12 or 11 or 09)
     }
     //first check all digits or not
     for (int i = 0; i < month.length(); i++) {
          if (!isdigit(month[i])) {
               return false; // that means user enetr char that is not digit
          }
     }
     //now i will transfer string value to int value to compare 
     stringstream monthFromString (month);
     int monthInInt;
     monthFromString >> monthInInt;

     return (monthInInt >= 1 && monthInInt <= 12); // month is between jan to dec, true will be returned. else false

}

//check year of the experiation date of the card
bool Payment::isYearValidOnCard(string year)
{

     if (year.length() != 4) {
          return false; // length must be 4 (e.g. 2023 or 2026)
     }

     //first check all digits or not
     for (int i = 0; i < year.length(); i++) {
          if (!isdigit(year[i])) {
               return false; // that means user enetr char that is not digit
          }
     }
     //now i will transfer string value to int value to compare 
     stringstream yearInString(year);
     int yearInInt;
     yearInString >> yearInInt;
     return (yearInInt >= 2021); // month is between jan to dec, true will be returned. else false
}

//check the validity of security code
void Payment::setExpirationDateOfCard()
{
     cout << "Enter month: ";
     string month;
     getline(cin, month);
     while (!isMonthValidOnCrad(month)) {
          //invalid entry by user
          //user must enter again 
          cout << "Invalid Month! (Must be between (01 to 12)!" << endl;
          cout << "Enter again" << endl;
          getline(cin, month);
     }
     
     //so, user entered valid month
     stringstream monthFromString(month);
     int monthInInt;
     monthFromString >> monthInInt;
     
     this->expiration_date_month = monthInInt; //assigning the member varible with int month value

     cout << "Enter Year: ";
     string year;
     getline(cin, year);
     while (!isYearValidOnCard(year)) {
          //invalid year entry
          //user must enter again
          cout << "Invalid year! (Must be greater than or equal to 2021)" << endl;
          cout << "Enter Again: ";
          getline(cin, year);
     }

     //valid year
     stringstream YearFromString(year);
     int yearInInt;
     YearFromString >> yearInInt;

     this->expiration_date_year = yearInInt; //assigning the 

}

//check the validity of code
bool Payment::isSecurityCodeValid(string code)
{
     //code should 3 different digits
     
     //first ckeck the length
     if (code.length() != 3) return false;

     //now check are all the digits re diffrent or not
     //let's use set DS for efficient code
     set <char> mySet;
     for (int i = 0; i < code.length(); i++) {
          mySet.insert(code[i]);
     }
     if (mySet.size() != 3) return false;

     //now let's free extra allocated memory
     mySet.clear();
     for (int i = 0; i < code.length(); i++) {
          if (!isdigit(code[i])) {
               return false; // returning false since al least one char is not digit
          }
     }

     //code length is 3
     //all char are digit
     //3 digits are diffrent
     //so returning true
     return true; 
}

//setter for security code
void Payment::setSecurityCode(string code)
{
     while (!isSecurityCodeValid(code)) {
          cout << "Security code is not valid !" << endl;
          cout << "Code must have 3 differnt digits" << endl;
          cout << "Enter again: " << endl;
          getline(cin, code);
     }
     //user enterd a valid security code
     this->securityCode = code;
}