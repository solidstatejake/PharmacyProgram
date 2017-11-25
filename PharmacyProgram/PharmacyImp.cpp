#include "stdafx.h"
#include "Pharmacy.h"

using namespace std;

Pharmacy::Pharmacy()
{
}


Pharmacy::~Pharmacy()
{
}

void Pharmacy::clearConsole() const
{
	//Makes sure that the screen is not cleared immediately and program will wait until they press enter
	cin.ignore(1, ' \n');

	//variable that we cin to. Serves no purpose other than allowing us to cin and end the ignore statement,
	//effectively clearing the screen.
	char pointlessVar;

	//Instructs user how to continue.
	cout << "Press [enter] to continue." << endl;

	//See pointlessVar comment above
	cin.get(pointlessVar);
	
	//Clears the console
	system("CLS");
}


void Pharmacy::introToUser() const
{
	cout << "PharmaTech Version 1.0" << endl;
}


void Pharmacy::grabUsername()
{
	//Making use of whitespace.
	cout << endl;

	//Creates carry variable to carry character input from console into the public member variable "password".
	char transferChar = ' ';

	//User is prompted for their username. That username is stored into the public member variable "username".
	cout << "Please enter your username: ";
	cin >> username;

	//User is prompted for their password. That password is stored into the public member variable "password".
	cout << "Please enter your password: ";
	
	//13 in ASCII is "return carrige" colloquially known as enter/return. We say while user does not input enter
	//allow inputs. If enter, end inputs.
	while (transferChar != 13)
	{
		//The char used to transfer individual character entries from the console to the public member variable
		//password gains its char values by grabbing each individual char entered in console by user. Therefore
		//password input is processed on a char-by-char basis.
		transferChar = _getch();

		//8 in ASCII is delete. If user hits delete key, the last character input will be deleted.
		if (transferChar == 8)
		{
			//pop_back() will remove the last character input into the istream
			password.pop_back();

			cout << "\b";//STILL NEEDS TO BE REVIEWED. ASTERISKS WILL NOT GO AWAY AFTER TYPED

		}//end of if
		//If user does not press enter or delete, char grabbed by _getch() and put into transferChar is placed
		//at the end of the password string. Since password string begins empty, password string is equivalent
		//only to what is pushed onto the back of the password string right here.
		else if(transferChar != 13 && transferChar != 8)
		{
			//push_back() will put what is being held in transfer char onto the end of the string variable password.
			password.push_back(transferChar);

			//Asterisk is output to simulate a hidden password.
			cout << '*';
			
		}//end of else
	}//end of while
	
	cout << endl;
}

int Pharmacy::verifyCredentials() 
{

	//cout << endl << username << password << endl << endl;
	//Input file variables used to access the files containing usernames and passwords
	ifstream usernameFile, passwordFile;

	//String used to carry in and hold names from username/password files. Variable is compared to what the user
	//inputs as their username to check the validity of their entry. 
	string compareCreds;

	bool usernameYesOrNo = 0,
		passwordYesOrNo = 0;

	//Opens the file containing verified username information. The period at the front is known as the
	//"local path operator".
	usernameFile.open(".\\UserInfo\\usernames.dat");
	
	//ERROR CHECK to make sure file opens
	if (usernameFile.fail())
	{
		cout << "Error opening file containing verified usernames." << endl;
	}

	//While not at the end of file (eof), user-entered username will be compared to verified usernames in the
	//file "usernames.dat".
	while (!usernameFile.eof())
	{
		//Verified username is copied from username file and placed into compareCreds string.
		getline(usernameFile, compareCreds);
		
		//compareCreds string is compared to user-entered username. If two match, username is accepted. Else not accepted.
		if (compareCreds == username)
		{
			usernameYesOrNo = true;
			break;
		}
		else
		{
			usernameYesOrNo = false;
		}
	}
	
	//The file containing the verified usernames is closed.
	usernameFile.close();
	
	
	//Opens the file containing verified password information
	passwordFile.open(".\\UserInfo\\passwords.dat");

	//ERROR CHECK to make sure the file opens
	if (passwordFile.fail())
	{
		cout << "Error opening file containing verified passwords." << endl;

	}//end of if

	//While not at the end of file (eof), user-entered username will be compared to verified usernames in the
	//file "usernames.dat".
	
	while (!passwordFile.eof())
	{
	
		//Verified password is copied from password file and placed into compareCreds string.
		getline(passwordFile, compareCreds);
		
		//compareCreds string is compared to user-entered password. If two match, password is accepted. Else not accepted.
		if (compareCreds == password)
		{
			passwordYesOrNo = true;
			break;
		}//end of if
		else
		{
			passwordYesOrNo = false;
			//continue;
		}//end of else
	}//end of while

	//The file containing the verified passwords is closed
	passwordFile.close();

	//If both the username and password are verified, then the function returns 1. Else 0.
	if (usernameYesOrNo == true && passwordYesOrNo == true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Pharmacy::displayPharmacistOptions()
{

	cout << "Welcome, " << username << "." << endl << endl;

	do
	{
		cout << "What would you like to do?" << endl
			<< "Enter [1] to fill a prescription." << endl
			<< "Enter [2] to check the current stock of medications." << endl
			<< "Enter [3] to update stock." << endl
			<< "Enter [4] to display a list of receipts" << endl;

		cin >> pharmacistDecision;

		clearConsole();

		switch (pharmacistDecision)
		{
		case 1:
			fillPrescription();
			break;
		case 2:
			viewStock();
			break;
		case 3:
			updateStock();
			break;
		case 4:
			displayReceipts();
			break;
		}
		
		clearConsole();

		cout << "Would you like to do something else?" << endl
			<< "Enter [1] if you would like to display the list of options again." << endl
			<< "Enter [0] if you are done making decisions." << endl;

		cin >> continueOrNot;
	} while (continueOrNot);
	

}


void Pharmacy::fillPrescription()
{
	int count = 0;
	ifstream  namesFile, costsFile, dosagesFile, stockFile;

	string carryName;

	int whichCostEffectiveMethod = 0;

	int medicationFound = 0;
	//___________________________________________________________Medication name information___________________________________________________________________________//
	do
	{
		//Prompts user for medication name they are searching for.
		cout << "Please enter the name of the medication in all capitals that you would like to fill the prescription of." << endl;
		cin >> whichMedication;

		//The file containing the names of the medications is opened.
		namesFile.open(".\\PharmacyInformation\\MedicationNames.dat");

		//If the file containing the medication names could not be opened the program will display an error.
		if (namesFile.fail())
		{
			cout << "Error opening file containing medication names" << endl;
		}//end of if

		//While not at the end of the file, compare each name in the file to the string whichMedication. (Search algorithm).
		while (!namesFile.eof())
		{
			//Copy medication name into string "carryName".
			getline(namesFile, carryName);

			//When carryName is equivalent to whichMedication (the medication the user typed in earlier)
			if (carryName == whichMedication)
			{
				medicationFound = 1;
				medicationRow = count;
				cout << "Medication found in list of medications." << endl;
			}
			else
			{
				medicationFound = 0;
				cout << "Error. Medication not found in the list of medications. Rerouting." << endl;
			}
			
			//count used to keep track of which row the medication occupies in sequential data file.
			count++;

		}//end of while

		//The file containing the names of medications is closed.
		namesFile.close();

	} while (!medicationFound); //end of do...while
	//______________________________________________________Pricing information________________________________________________________________________________//

	clearConsole();

	cout << "Please enter the information about the prescription for this drug." << endl
		<< "Enter the length of time in days the presciption is supposed to last: ";
	cin >> prescriptionLength;
	cout << "Please enter the dose in milligrams the patient is supposed to take: ";
	cin >> prescriptionDosage;
	cout << "Please enter the frequency of this dosage (how many times per day): ";
	cin >> dosageFrequency;
	
	//The file containing medication pricing information is opened.
	costsFile.open(".\\PharmacyInformation\\MedicationCosts.dat");

	//If file open failure -> display error message. Else nothing.
	if (costsFile.fail())
	{
		cout << "Error opening file containing medication pricing information." << endl;
	}

	while (!costsFile.eof())
	{
		int count = 0;

		if (count == medicationRow)
		{
			costsFile >> cost1 >> cost2 >> cost3;
		}

		count++;
	}//end of while

	costsFile.close();
	//_______________________________________________________Dosage information_______________________________________________________________________________//

	//The file containing the dosages that the pharmacy carries of each type of medication is opened.
	dosagesFile.open(".\\PharmacyInformation\\MedicationDosages.dat");

	//If the file containing the dosages cannot be opened, an error message is displayed.
	if (dosagesFile.fail()) //alternative would be to use if(!dosagesFile.is_open())
	{
		cout << "Error opening file containing medication dosages." << endl;
	}

	while (!dosagesFile.eof())
	{
		int count = 0;

		if (count == medicationRow)
		{
			dosagesFile >> dosage1 >> dosage2 >> dosage3;
		}

		count++;
	}//end of while

	 //File containing the dosages of the medications is closed.
	dosagesFile.close();

	//_______________________________________________________Stock of drug information_______________________________________________________________________________//

	//The file containing the quantities of each medication in stock is presented.
	stockFile.open(".\\PharmacyInformation\\MedicationStock.dat");

	//If the file containing medication stock cannot be opened, an error message is displayed.
	if (stockFile.fail())
	{
		cout << "Error opening file containing medication in stock." << endl;
	}

	//While not at the end of the while, search for the row that contains all the information about specific medication. Once at that row, grab1 >> grab2 >> grab3.
	while (!stockFile.eof())
	{
		int count = 0;
		if (count == medicationRow)
		{
			stockFile >> stock1 >> stock2 >> stock3;
		}
		count++;
	}//end of while

	stockFile.close();


	//_______________________________________________________Cost display and efficacy suggestion_______________________________________________________________________________//


	//This block of if..else statements decides which dosage of the pill will be used beginning with the third dosage, which
	//will end up being the cheapest if the prescription can consist of a smaller amount of higher-dosed pills that cost a
	//little more. This block will set pill1/2/3 equal to the amount of pills it would take using the 1/2/3 dosage to fill
	//the prescription.
	if ((prescriptionDosage % dosage3) == 0)
	{
		pill3 = (prescriptionDosage * dosageFrequency * prescriptionLength) / dosage3;
	}
	else if ((prescriptionDosage % dosage2) == 0)
	{
		pill2 = (prescriptionDosage * dosageFrequency * prescriptionLength) / dosage2;
	}
	else if ((prescriptionDosage % dosage3) == 0)
	{
		pill1 = (prescriptionDosage * dosageFrequency * prescriptionLength) / dosage1;
	}



	//This block of if...else statements will determine the cost of the prescription based on the which dosage was chosen
	//in the if...else block above. It checks to make sure that: there is medication in stock; there is a greater or
	//equivalent amount of medication in stock when compared to the amount of medication needed to fill the prescription;
	//and finally, checks to make sure that the script can be filled without having to partition a pill (break the pill).
	//While this was checked in the if...else block above, it is such an imperative function that it has been incorporated
	//twice.
	//whichCostEffectiveMethod determines which case will be used in the switch statement below.
	//costEffectiveSolution is the product of the amount of pills in the prescription multiplied by pill cost.
	//If there is no way to fill the prescription without combining different doses/partitioning pills, an error message
	//is displayed, and an option is presented as to whether or not the pharmacist would like a suggestion on how to fill
	//the prescription using multiple dosages.
	if ((stock3 > 0) && (stock3 >= pill3) && ((prescriptionDosage % dosage3) == 0))
	{
		whichCostEffectiveMethod = 3;
		costEffectiveSolution = cost3*pill3;
	}
	else if (stock2 > 0 && stock2 >= pill2 && ((prescriptionDosage % dosage2) == 0))
	{
		whichCostEffectiveMethod = 2;
		costEffectiveSolution = cost2*pill2;
	}
	else if (stock1 > 0 && stock1 >= pill1 && ((prescriptionDosage % dosage1) == 0))
	{
		whichCostEffectiveMethod = 1;
		costEffectiveSolution = cost1*pill1;
	}
	else
	{
		cout << "Based on the information provided about the prescription, it is not possible to fill this prescription" << endl
			<< "without combining pills of different dosages, or partitioning pills. Based on this information, what would" << endl
			<< "you like to do?" << endl
			<< "Would you like a recommendation on how to fill the prescription piece-meal, with pills of" << endl
			<< "different dosages?" << endl;
	}


	cout << "These are the dosages available based on the medication you have chosen: " << endl
		<< dosage1 << "mg @ $" << cost1 << " per pill." << endl
		<< dosage2 << "mg @ $" << cost2 << " per pill." << endl
		<< dosage3 << "mg @ $" << cost3 << " per pill." << endl;

	switch (whichCostEffectiveMethod)
	{
	case 1:
		cout << "The cost-effective recommendation is as follows:" << endl
			<< "Using " << dosage1 << "mg pills, fill the prescription as follows:"
			<< pill1 << "x " << whichMedication << "." << endl
			<< "The cost of this prescription will be " << costEffectiveSolution << "$." << endl;
		break;
	case 2:
		cout << "The cost-effective recommendation is as follows:" << endl
			<< "Using " << dosage2 << "mg pills, fill the prescription as follows:"
			<< pill2 << "x " << whichMedication << "." << endl
			<< "The cost of this prescription will be " << costEffectiveSolution << "$." << endl;
		break;
	case 3:
		cout << "The cost-effective recommendation is as follows:" << endl
			<< "Using " << dosage3 << "mg pills, fill the prescription as follows:"
			<< pill3 << "x " << whichMedication << "." << endl
			<< "The cost of this prescription will be " << costEffectiveSolution << "$." << endl;
		break;
	}
	
	
	
}


void Pharmacy::updateStock()
{

}


void Pharmacy::viewStock()
{
	//Provide code that opens the file containing stock and allows changes.
}

void Pharmacy::displayReceipts()
{

}