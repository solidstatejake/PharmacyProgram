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
	
	
	int verifyCredentials();
		//This function will check the credentials extracted from the console in the function 
		//grabPharmacistName against the files that contain acceptable usernames and passwords.
		//If the credentials are appropriate, the function will permit access to the further depths 
		//of the program.
		//Postcondition: Administrative permissions are either granted or denied.

	void displayPharmacistOptions();
		//This function will display the choices onto the console for the pharmacist to choose from. 
		//the options are: fill prescription, print receipt, update stock, and display reciepts

	void fillPrescription();
		//Reads prescription file and allows the user to search for a prescription.
		//Displays the name, price, dose and stock of presciption searched for. 

	void printScriptReceipt();
		//This function prints a receipt of all the necessary information, including, medication name,
		//price, dosage, and customer name.
	
	void updateStock();
		//This function updates the stock based on how much dosage and how large the prescription given prior. 

	void viewStock();
		//This function will allow the user to access the file containing the information on 
		//the status of the medications in stock.
		//Postcondition: User is now able to manipulate the sequential data file "Stock.dat".

	void displayReceipts();
		//This function either creates or opens a file containing the last 50 receipts since the
		//user has logged in.  If opening the file the function appends the exsisting file adding onto the 
		//end of it. 

	// The following four functions allow the user to reset the files back to their default values. 
	void resetStock();
	void resetMedicationNames();
	void resetMedicationCosts();
	void resetMedicationDosages();

	
	string username; //The username of the individual pharmicist to access the program
	int IDnumber; //The individual IDnumber of the individual pharmicist to access the program
	string password; //The universal password required by the pharmicist to access the program

private:
	int pharmacistDecision; //used to allow the pharmacist to make a decision
	int continueOrNot;   //used to ask the user whether or not they wish to continue 
	string whichMedication; //Which medication the pharmacist has chosen
	int medicationRow;
	double whichDosage;

	
	//These three variables store the inputs of the pharmacist that are used to calculate the most cost effective way for the pharmacist to fill the prescription.
	string prescriptionDate; //Variable represents the date the prescription was filled
	string patientName;	//Variable represents the patients name being entered
	int prescriptionLength; //Variable represents the length of time the prescription will last
	int prescriptionDosage; //Variable represents the dosage of the prescription
	int dosageFrequency; //Variable represents how often the prescription needs to be taken
	

	int amountOfPillsToMakeUpScript; //Variable used to combine the three above variables; this will make it easier to create algorithms; working with one variable instead of three.
	double costEffectiveSolution;

	//These three variables will be used to pull in the three dosages corresponding to a specific medication. The most cost effective dosage combo will then be presented to user and the user can chose.
	int dosage1;
	int dosage2;
	int dosage3;

	int pill1 = 0; //Represents the amount of the first dosage of the medication it will take to fill the prescription.
	int pill2 = 0; //Represents the amount of the second dosage of the medication it will take to fill the prescription.
	int pill3 = 0; //Represents the amount of the third dosage of the medication it will take to fill the prescription.

	//These three variables wil be used to pull in the three dosage pricesd corresponding to a specific medication designated by the user. 
	double cost1;
	double cost2;
	double cost3;

	//These three variables will be used to pull in the three dosage's stock information corresponding to a specific medication designated by the user.
	int stock1;
	int stock2;
	int stock3;

	//Arrays used to grab data from files and hold.
	string medicationNamesArray[200];
	int stockArray[200][3];
	double medicationCostsArray[200][3];
	int medicationDosagesArray[200][3];
};


