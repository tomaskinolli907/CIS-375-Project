#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
     string firstName;
     string lastName;
     string email;
     string password;

public:

     //Deafault Constructor
     Account();

     //display create account requirements
     void accountCreationRule();


     //check whther all the characters of the name are letters or not
     //length more than or equal to 2
     bool isNameValid(string name);

     //this methos will set the firstName of the user
     //it will call isNameValid method to 
     void setFirstName(string firstName);

     //getter method for the firstName attribute
     string getFirstName();


     //this methos will set the lastName of the user
    //it will call isNameValid method to chekc the validity of the given name
     void setLastName(string lastName);

     //getter method for the firstName attribute
     string getLastName();

     //check whether email address is in correct format
     bool isEmailValid(string email);


     //set the email
     void setEamil(string email);

     //getter for email
     string getEmail();

     //check the validity of the password
     bool isPasswordValid(string password);

     //stter for password attribute
     void setPassword(string password);

     //getter method for returning password
     string getPassword();

     //A method to display message after succesfully creating user account
     void displayAccountCreationMessage();
};


