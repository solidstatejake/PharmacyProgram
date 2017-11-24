//Pharmacy class specification file. 
//Pharmacy class member definitions found in the implementation file "PharmacyImp.cpp".

#pragma once //DO NOT ERASE (not sure what #pragma does yet - Jake)

//Libraries
#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

//Namespace(s)
using namespace std;


//Pharmacy class definition. 
class Pharmacy
{
public:
	Pharmacy();
		//Class constructor

	~Pharmacy();
		//Class destructor

	void clearConsole() const;
		//This function will clear the console as the user navigates from the program's capability
		//to capability.
		//Postcondition: The console will be cleared.

	void introToUser() const;
		//Introduces user to the program.
		//Postcondition: A paragraph is produces explaining the program to the user.

	void grabUsername();// string&, string&);
		//Will prompt user for name (Pharmacist should/would be using program).
		//Postcondition: The strings entered into the console by the user will be stored into the
		//member variables username and password.
	
	
	int verifyCredentials() const;
		//This function will check the credentials extracted from the console in the function 
		//grabPharmacistName against the files that contain acceptable usernames and passwords.
		//If the credentials are appropriate, the function will permit access to the further depths 
		//of the program.
		//Postcondition: Administrative permissions are either granted or denied.

	void displayPharmacistOptions();

	void fillPrescription();

	void updateStock();

	void viewStock();
		//This function will allow the user to access the file containing the information on 
		//the status of the medications in stock.
		//Postcondition: User is now able to manipulate the sequential data file "Stock.dat".

	void displayReceipts();

	string username;
	string password;

private:
	int pharmacistDecision; 
	int continueOrNot;
};


