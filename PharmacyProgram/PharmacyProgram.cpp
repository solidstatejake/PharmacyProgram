//Libraries
#include "stdafx.h"
#include "Pharmacy.h" //The reason we do not need to include any other libraries in this file is because they
					  //are included in the "Pharmacy.h" file. It would be redundant to incorporate them again.

//Namespace(s)
using namespace std;


//Function prototypes

//The main function
int main()
{


	//Declare the object Pharm of class Pharmacy specified in "Pharmacy.h" and implemented in "PharmacyImp.cpp".
	Pharmacy Pharm;

	int continueWithProgram = 0;
	//WELCOME USER / DISPLAY BANNER
	Pharm.introToUser();

	Pharm.resetStock();
	Pharm.resetMedicationNames();
	Pharm.resetMedicationDosages();
	Pharm.resetMedicationCosts();

	do
	{
		//Grabs username and password from user; stores in username and password member variables.
		Pharm.grabUsername();

		//If creds accepted, "username x accepted". Else "username x not accepted"
		if ((Pharm.verifyCredentials()) == 1)
		{
			cout << "Username \"" << Pharm.username << "\" and password accepted." << endl;
			continueWithProgram = 1;
		}
		else
		{
			cout << "Username \"" << Pharm.username << "\" or password not accepted. Rerouting." << endl;
			continueWithProgram = 0;
		}
	} while (!continueWithProgram);

	//The console is cleared
	Pharm.clearConsole();

	Pharm.displayPharmacistOptions();

	
	//USER LOGIN	<------------------
	//								   ^
	//VERIFY USER LOGIN				   ^
	//								   ^
	//CLS --------------> IF BAD CREDS ^
	//					  ELSE	IF GOOD CREDS v
	//v----------------------------------------						              
	//DETERMINE CAPABILITIES BASED ON LOGIN CREDENTIALS--v
	//											         IF SUDO--------> ALLOW SUPER-ADMIN CAPABILITES (remove users, display file names containing info... etc.)
	//DISPLAY THESE CAPABILITIES AS OPTIONS	<----------- ELSE         v---------------v													
	//v----------------------------------------------------------------																  -
	//ALLOW USER TO CHOOSE OPTION SUCH AS: ADD/REMOVE MEDS, UPDATE STOCK, CHECK STOCK, FILL SCRIPT, DISPLAY RECEIPTS...
	// v
	//CLS
	
	
    return 0;
}


/*
FILES that we need:
	An inventory file
		Medication name
		doses avail
		quantity in stock
		price per pill
		dosage 
		(up to 200 meds with 3 doses of each)

	An employee file:
		list of employees
			name
			unique employee id number
			count of prescriptions filled

FUNCTIONS that we need:
	IntroToUser();

	grabPharmacistName();

	displayMenuOptions();

	*/