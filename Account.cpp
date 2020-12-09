#include "Account.h"
#include <string>
using namespace std;

//Default Constructor
Account::Account() {
          //All the attributes will be set to NULL;
          this->firstName = "";
          this->lastName = "";
          this->email = "";
          this->password = "";
}

//display create account requirements
void Account::accountCreationRule() {
     cout << "================================================================" << endl;
     cout << "                         Account Creation Rules" << endl;
     cout << "                         ----------------------" << endl;
     cout << " #First and Last name: " << endl;
     cout << "               => All the charcters must be alphabet" << endl;
     cout << "               => Length must be atleast 2" << endl;
     cout << " # User Must enter a valid formated email addres" << endl;
     cout << "               => e.g (________________@provider.com)" << endl;
     cout << "               => e.g (________________@provider.edu)" << endl;
     cout << " # Password must contain at-least: " << endl;
     cout << "               => 2 Upper case letter" << endl;
     cout << "               => 2 Lower case letter" << endl;
     cout << "               => 2 Digit" << endl;
     cout << "               => 1 Speacial charecter (@, $, %, &)" << endl;
     cout << "               => Should not contain any space" << endl;
     cout << "================================================================" << endl;
}

//check whther all the characters of the name are letters or not
 //length more than or equal to 2
bool Account:: isNameValid(string name)
{
     if (name.length() < 2) return false;//length is less than 2, so invalid name

     //check all the characters all letters or not
     for (int i = 0; i < name.length(); i++) {
          if (!isalpha(name[i])) {
               return false;//so, atleast one of the character is not letter
          }
     }

     //if program counter gets here, that means name is valid
     return true;
}

//this methos will set the firstName of the user
    //it will call isNameValid method to 
void Account:: setFirstName(string firstName) {
     //let's see whether given name is valid or not
     while (!isNameValid(firstName)) {
          cout << "First Name is not valid!" << endl;
          cout << "Enter again: ";
          getline(cin, firstName);
     }

     //now, the user enters a valid first name
     this->firstName = firstName;
}

//getter method for the firstName attribute
string Account:: getFirstName() {
     return this->firstName;
}

//this methos will set the lastName of the user
 //it will call isNameValid method to chekc the validity of the given name
void Account:: setLastName(string lastName) {
     //let's see whether given name is valid or not
     while (!isNameValid(lastName)) {
          cout << "Last Name is not valid!" << endl;
          cout << "Enter again: ";
          getline(cin, lastName);
     }

     //now, the user enters a valid last name
     this->lastName = lastName;
}

//getter method for the firstName attribute
string Account:: getLastName() {
     return this->lastName;
}

//check whether email address is in correct format
bool Account:: isEmailValid(string email) {


     //check whther '@' is present or not
     bool isEmailValid = false;//assuming initially true
     int counter = 0;//will keep track how many '@' is present in the email add
     //a valid email add should have only one '@' char
     int indexNumAt = -1;
     for (int i = 0; i < email.length(); i++) {
          if (email[i] == '@') {
               isEmailValid = true;
               counter++;
               indexNumAt = i;
          }
     }

     if (indexNumAt == 0) {
          return false;//meaning @ is the starting point, NOT VALID EMAIL
     }

     //if counter value is not 1, that means there is not exactly 1 '@' present the email add
     //in that case, email is not valid
     if (counter != 1 && !isEmailValid) {
          return false;
     }

     //now let's check whether ".com" or ".edu" present in the email address
     //let's first check ".com"
     int isComPresent = email.find(".com");
     if (isComPresent == string::npos) {
          //so .com not present
          //let's check ".edu"
          int isEduPresent = email.find(".edu");
          if (isEduPresent == string::npos) {
               //so ".edu" not present
               return false;
          }
          else {
               return true;//".edu" present
          }
     }
     else {
          //present
          //now let's check ".edu" present or not
          // if not, then we can return true
          int isEduPresent = email.find(".edu");
          if (isEduPresent == string::npos) {
               //so ".edu" not present
               return true;//so only ".com" present
          }
          else {
               return false;//".edu" and ".com" both present
          }
     }

}

//set the email
void Account:: setEamil(string email)
{
     while (!isEmailValid(email)) {
          cout << "Email is not valid!" << endl;
          cout << "Enter again: " << endl;
          getline(cin, email);
     }

     //now the email is valid
     this->email = email;
}

//getter for email
string Account:: getEmail() {
     return this->email;
}

//check the validity of the password
bool Account:: isPasswordValid(string password)
{
     //length has to be at-least 6
     if (password.length() < 6) return false;

     int numUpperCaseLetter = 0;
     int numLowerCaseLetter = 0;
     int numOfDigits = 0;
     int numSpeacialChar = 0;
     int numSpaces = 0;

     for (int i = 0; i < password.length(); i++) {
          if (isupper(password[i])) {
               numUpperCaseLetter++;
          }
          else if (islower(password[i])) {
               numLowerCaseLetter++;
          }
          else if (isdigit(password[i])) {
               numOfDigits++;
          }
          else if (password[i] == '@' || password[i] == '$' || password[i] == '%' || password[i] == '&') {
               numSpeacialChar++;
          }
          else if (password[i] == ' ') {
               numSpaces++;
          }
     }

     //if password contains atleast two upper case letters
     //if password contains atleast two lower case letters
     //if password contains atleast two digits
     //if password contains atleast one speacial char (e.g. '$', '@', '%', '&')
     //then, it is valid password. Hence, we are returing true
     //else return false
     if (numUpperCaseLetter >= 2 && numLowerCaseLetter >= 2 && numOfDigits >= 2 && numSpeacialChar >= 1 && numSpaces == 0) {
          return true;
     }
     else return false;

}

//stter for password attribute
void Account:: setPassword(string password) {
     while (!isPasswordValid(password)) {
          cout << "Password is not valid!" << endl;
          cout << "Enter Again: " << endl;
          getline(cin, password);
     }

     //now password is valid
     this->password = password;
}

//getter method for returning password
string Account:: getPassword() {
     return this->password;
}

//A method to display message after succesfully creating user account
void Account:: displayAccountCreationMessage() {
     cout << "Account has been created!" << endl;
}