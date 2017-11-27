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
		//This function will display a list of options to the user. This function creates a junction by which the user can access
		//all other imperative functions of the program.
		//Postcondition: User is navigated to another section of the program (i.e. fillPrescription();, updateStock();...).

	void fillPrescription();
		//This function allows the user to fill a prescription. the user enters the medication name, patient name, date, length 
		//of prescription, dosage, and frequency of dosage. 
		//Post conditions:The most cost-effective way (for the user) of filling the prescription is offered to the user.
		//A receipt of the transaction is then displayed to the user containing all pertinent information.
		//All pertinent files are simultaneously edited to reflect the change in stock made by filling the prescription, and a new
		//file is created containing a receipt of the transaction that is identical to the receipt displayed to user on the console.

	void printScriptReceipt();
		//This function prints the receipt of the prescription to the user. The function is called inside of the fillPrescription();
		//function.
		//Postcondition: A receipt containing the medication's name, the patient's name, the date, the length of time the prescription
		//should last, the dosage (in mg) of the prescription, and the frequency at which the dosage should be taken is presented to 
		//the user.

	void updateStock();
		//This function allows the user to view all medication information in a spread-sheet format on the console, choose which medication	
		//they would like to edit the information of, and then edit the information. The function opens all relevant files and then rewrites 
		//the files with the edits.
		//Postcondition: All edits made by the user to the medication data (i.e. medication name, medication dosages, medication costs... etc.)	
		//are edited in the file(s) which contain the information they are editing.

	void viewStock();
		//This function will allow the user to access the file containing the information on 
		//the status of the medications in stock.
		//Postcondition: User is now able to manipulate the sequential data file "Stock.dat".

	void displayReceipts();
		//NOT FINISHED!~~~~~!!!~~~~~!!!! This function allows the user to print copies of all receipts in the file "Receipts".


	//These four functions are only for demonstrative purposes. These four functions reset each of their respective data (i.e. stock, names,
	//costs, and dosages) to preset values inside of the files where these data can be found.
	//Postcondition: Stock() changes all medications (including all three of every dosage type) stock value to 1000.
	//				 MedicationNames() changes all 200 medication names to "MEDICATIONn" where n represent a number 1-200.
	//				 MedicationCosts() changes all costs to preset, arbitrary values.
	//				 MedicationDosages() changes all medication dosages to preset, arbitrary values.
	void resetStock();
	void resetMedicationNames();
	void resetMedicationCosts();
	void resetMedicationDosages();

	//This variable is used to store the user's username that they input in the beginning of the program to log in.
	string username;

	//This variable is used to store the user's ID number that they input in the beginning of the program to log in.
	int IDnumber;

	//This variable is used to store the user's password that they input in the beginning of the program to log in.
	string password;

private:
	int pharmacistDecision; //used to allow the pharmacist to make a decision
	int continueOrNot; 
	string whichMedication; //Which medication the pharmacist has chosen

	//This variable is used when the user inputs a medication name. It holds the row the medication was found on. This row number is then used to
	//edit the medications respective data (i.e. stock value, dosages, costs) on the same row in another file.
	int medicationRow;
	
	//These three variables store the inputs of the pharmacist that are used to calculate the most cost effective way for the pharmacist to fill the prescription.
	string prescriptionDate;//Variable represents the date that the prescription was filled. This date will be used to create the file name containing the receipt for the transaction.
	string patientName;		//Variable represents the name of the patient the prescription is for. This name will also be used to create the file name containing the receipt for the transaction.
	int prescriptionLength; //Variable represents the length of time the prescription in question will last
	int prescriptionDosage; //Variable represents the dosage associated with the prescription in question.
	int dosageFrequency;	//Variable represents the frequency the prescription's dosage should be taken.
	

	int amountOfPillsToMakeUpScript; //Variable used to combine the three above variables; this will make it easier to create algorithms; working with one variable instead of three.
	double costEffectiveSolution;	 //Variable that holds the cost of the prescription.

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


