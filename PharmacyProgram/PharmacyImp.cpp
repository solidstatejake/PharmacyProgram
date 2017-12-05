#include "stdafx.h"
#include "Pharmacy.h"
#include <iostream>

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

void Pharmacy::resetMedicationNames()
{
	ofstream namesFileOut;

	namesFileOut.open(".\\PharmacyInformation\\MedicationNames.dat");

	if (namesFileOut.fail())
	{
		cout << "Error opening names file in order to reset data inside." << endl;
	}

	for (int i = 1; i <= 200; i++)
	{
		namesFileOut << "MEDICATION" << i << endl; 
	}

	namesFileOut.close();
}

void Pharmacy::resetStock()
{
	//define the output variable stockFileOut
	ofstream stockFileOut;

	//Open the stock file
	stockFileOut.open(".\\PharmacyInformation\\MedicationStock.dat");


	if (stockFileOut.fail())
	{
		cout << "Error opening stock file in order to reset data inside." << endl;
	}

	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stockFileOut << setw(15) << left << 1000;

			if (j == 2)
			{
				stockFileOut << endl;
			}//end of if
		}//end of j for
	}//end of i for

	//Close the stock file
	stockFileOut.close();
}

void Pharmacy::resetMedicationDosages()
{
	//define the output variable stockfile
	ofstream dosageFileOut;

	//Open the stock file
	dosageFileOut.open(".\\PharmacyInformation\\MedicationDosages.dat");


	if (dosageFileOut.fail())
	{
		cout << "Error opening dosages file in order to reset data inside." << endl;
	}

	for (int i = 0; i < 200; i++)
	{
			dosageFileOut << setw(15) << left;
			
			switch (i % 10)
			{
			case 0:
				dosageFileOut << 10 << setw(15) << left << 20 << 30 << endl;
				break;
			case 1:
				dosageFileOut << 25 << setw(15) << left << 50 << 75 << endl;
				break;
			case 2:
				dosageFileOut << 12 << setw(15) << left << 25 << 40 << endl;
				break;
			case 3: 
				dosageFileOut << 2 << setw(15) << left << 4 << 6 << endl;
				break;
			case 4:
				dosageFileOut << 5 << setw(15) << left << 10 << 20 << endl;
				break;
			case 5: 
				dosageFileOut << 1 << setw(15) << left << 2 << 3 << endl;
				break;
			case 6:
				dosageFileOut << 100 << setw(15) << left << 500 << 1000 << endl;
				break;
			case 7:
				dosageFileOut << 50 << setw(15) << left << 100 << 250 << endl;
				break;
			case 8:
				dosageFileOut << 75 << setw(15) << left << 150 << 300 << endl;
				break;
			case 9:
				dosageFileOut << 500 << setw(15) << left << 1000 << 2000 << endl;
				break;
			}
		}//end of i for

	//Close the costs file
	dosageFileOut.close();
}

void Pharmacy::resetMedicationCosts()
{

	//define the output variable stockfile
	ofstream costsFileOut;

	//Open the stock file
	costsFileOut.open(".\\PharmacyInformation\\MedicationCosts.dat");


	if (costsFileOut.fail())
	{
		cout << "Error opening costs file in order to reset data inside." << endl;
	}

	for (int i = 0; i < 200; i++)
	{
		costsFileOut << setw(15) << left;

		switch (i % 10)
		{
		case 0:
			costsFileOut << 1.50 << setw(15) << left << 2.50 << 3.50 << endl;
			break;
		case 1:
			costsFileOut << 3.75 << setw(15) << left << 5.00 << 8.00 << endl;
			break;
		case 2:
			costsFileOut << 1.25 << setw(15) << left << 2.40 << 4.20 << endl;
			break;
		case 3:
			costsFileOut << .25 << setw(15) << left << .45 << .80 << endl;
			break;
		case 4:
			costsFileOut << 15 << setw(15) << left << 28.80 << 42.88<< endl;
			break;
		case 5:
			costsFileOut << 1.89 << setw(15) << left << 2.99 << 4.00 << endl;
			break;
		case 6:
			costsFileOut << 105 << setw(15) << left << 520 << 990 << endl;
			break;
		case 7:
			costsFileOut << 3.30 << setw(15) << left << 6.25 << 7.00 << endl;
			break;
		case 8:
			costsFileOut << 1.20 << setw(15) << left << 2.00 << 3.75 << endl;
			break;
		case 9:
			costsFileOut << 5.50 << setw(15) << left << 10.20 << 18.59 << endl;
			break;
		}
	}//end of i for

	 //Close the costs file
	costsFileOut.close();
}

void Pharmacy::introToUser() const
{
	cout << "PharmaTech Version 1.0" << endl;

	//write some more shit that explains to a pharmacist how to fill a prescription.
}

void Pharmacy::grabUsername()
{
	//This will reset the password back to an empty string in case the user mis-enters their credentials.
	password = "";

	//Making use of whitespace.
	cout << endl;

	//Creates carry variable to carry character input from console into the public member variable "password".
	char transferChar = ' ';

	//User is prompted for their username. That username is stored into the public member variable "username".
	cout << "Please enter your username: ";
	cin >> username;

	//User is prompted for their ID number. That ID number is stored into the public member variable "IDnumber".
	cout << "Please enter your user ID number: ";
	cin >> IDnumber;

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
	ifstream usernameFile, IDNumberFile, passwordFile;

	//String used to carry in and hold names from username/password files. Variable is compared to what the user
	//inputs as their username to check the validity of their entry. 
	string compareCreds;
	double compareIDCreds; //Overloaded instance of compareCreds varaible used to compare what the user inputs as their ID#
						 //to the ID numbers in the verified ID# file.

	bool usernameYesOrNo = 0,
		IDYesOrNo = 0,
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
	
	//The file containing verified user ID numbers is opened.
	IDNumberFile.open(".\\UserInfo\\pharmacistIDs.dat");

	//ERROR CHECK to make sure the user ID number file opens.
	if (IDNumberFile.fail())
	{
		cout << "Error opening file containing verified user ID numbers." << endl;
	}
	
	//User ID numbers are grabbed from user ID number file and placed into a comparative variable
	//That comparative variable is then comapred to what the user has entered as their user ID number. 
	//If the two match -> OK. Else -> no entry into system.
	while (!IDNumberFile.eof())
	{
		IDNumberFile >> compareIDCreds;

		if (compareIDCreds == IDnumber)
		{
			IDYesOrNo = true;
			break;
		}
		else
		{
			IDYesOrNo = false;
		}
	}

	//The file containing verified user ID numbers is closed
	IDNumberFile.close();

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
	if (usernameYesOrNo == true && IDYesOrNo == true && passwordYesOrNo == true)
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

		clearConsole();
	} while (continueOrNot);
	

}

void Pharmacy::fillPrescription()
{
	int rowCount = 0;
	int COUNT = 0;
	ifstream  namesFileIn, costsFileIn, dosagesFileIn, stockFileIn;
	fstream stockFileOut;
	string carryName;

	int whichCostEffectiveMethod = 0;

	int medicationFound = 1;

	int storePointlessInts = 0;
	double storePointlessDoubles = 0;

	//___________________________________________________________Medication name information___________________________________________________________________________//
	do
	{
		if (medicationFound == 0)
		{
			medicationRow = 0;
			rowCount = 0;
		}
		//Prompts user for medication name they are searching for.
		cout << "Please enter the name of the medication in all capitals that you would like to fill the prescription of." << endl;
		cin >> whichMedication;

		//The file containing the names of the medications is opened.
		namesFileIn.open(".\\PharmacyInformation\\MedicationNames.dat");

		//If the file containing the medication names could not be opened the program will display an error.
		if (namesFileIn.fail())
		{
			cout << "Error opening file containing medication names" << endl;
		}//end of if

		//While not at the end of the file, compare each name in the file to the string whichMedication. (Search algorithm).
		while (!namesFileIn.eof())
		{
			//Copy medication name into string "carryName".
			getline(namesFileIn, carryName);

			//When carryName is equivalent to whichMedication (the medication the user typed in earlier)
			if (carryName == whichMedication)
			{
				medicationFound = 1;
				medicationRow = rowCount;
				cout << "Medication found in list of medications. It is on row " << medicationRow << "." << endl;
				break;
			}
			else if ((rowCount == 199) && (carryName != whichMedication))
			{
				medicationFound = 0;
				cout << "Error. Medication not found in the list of medications. Rerouting." << endl;
			}
			
			//count used to keep track of which row the medication occupies in sequential data file.
			rowCount++;

		}//end of while

		//The file containing the names of medications is closed.
		namesFileIn.close();

	} while (!medicationFound); //end of do...while


	

	//______________________________________________________Pricing information________________________________________________________________________________//

	//clearConsole();

	cout << "Please enter the information about the prescription for this drug." << endl << endl
		<< "What is the date? Enter the date in the form MMDDYYYY (without any punctuation or forward-slashes).";
	cin >> prescriptionDate;
	cout << "What is the name of the patient the prescription is for? Enter the name of the patient" << endl
		<< "in the form FirstLast. Make sure not to include any punctuation." << endl;
	cin >> patientName;
	cout << endl << endl << "Enter the length of time in days the presciption is supposed to last: ";
	cin >> prescriptionLength;
	cout << endl << endl << "Please enter the dose in milligrams the patient is supposed to take: ";
	cin >> prescriptionDosage;
	cout << endl << endl << "Please enter the frequency of this dosage (how many times per day): ";
	cin >> dosageFrequency;
	
	//The file containing medication pricing information is opened.
	costsFileIn.open(".\\PharmacyInformation\\MedicationCosts.dat");

	//If file open failure -> display error message. Else if file is open, say open.
	if (costsFileIn.fail())
	{
		cout << "Error opening file containing medication pricing information." << endl;
	}
	else if (costsFileIn.is_open())
	{
		cout << "Costs file opened..." << endl;
	}

	while (COUNT < 200)
	{
	
		if (COUNT == medicationRow)
		{
			costsFileIn >> cost1 >> cost2 >> cost3;
			break;
		}
		else
		{
			costsFileIn >> storePointlessDoubles >> storePointlessDoubles >> storePointlessDoubles;
		}

		COUNT++;
	}//end of while

	costsFileIn.close();
	
	//_______________________________________________________Dosage information_______________________________________________________________________________//

	//The file containing the dosages that the pharmacy carries of each type of medication is opened.
	dosagesFileIn.open(".\\PharmacyInformation\\MedicationDosages.dat");

	//If the file containing the dosages cannot be opened, an error message is displayed.
	if (dosagesFileIn.fail()) //alternative would be to use if(!dosagesFile.is_open())
	{
		cout << "Error opening file containing medication dosages." << endl;
	}
	else if (dosagesFileIn.is_open())
	{
		cout << "Dosages file opened..." << endl;
	}

	//Sets the row-tracking count back to zero.
	COUNT = 0;

	while (COUNT < 200)
	{
		
		if (COUNT == medicationRow)
		{
			dosagesFileIn >> dosage1 >> dosage2 >> dosage3;
			break;
		}
		else
		{
			dosagesFileIn >> storePointlessInts >> storePointlessInts >> storePointlessInts;
		}

		COUNT++;
	}//end of while

	 //File containing the dosages of the medications is closed.
	dosagesFileIn.close();



	//_______________________________________________________Stock of drug information_______________________________________________________________________________//

	//The file containing the quantities of each medication in stock is presented.
	stockFileIn.open(".\\PharmacyInformation\\MedicationStock.dat");

	//If the file containing medication stock cannot be opened, an error message is displayed.
	if (stockFileIn.fail())
	{
		cout << "Error opening file containing medication in stock." << endl;
	}
	else if (stockFileIn.is_open())
	{
		cout << "Stock file opened..." << endl;
	}

	//Sets the row-tracking count back to zero.
	COUNT = 0;

	//While not at the end of the while, search for the row that contains all the information about specific medication. Once at that row, grab1 >> grab2 >> grab3.
	while (COUNT < 200)
	{

		if (COUNT == medicationRow)
		{
			stockFileIn >> stock1 >> stock2 >> stock3;
			break;
		}
		else
		{
			stockFileIn >> storePointlessInts >> storePointlessInts >> storePointlessInts;
		}

		COUNT++;
	}//end of while

	stockFileIn.close();





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
	else if ((prescriptionDosage % dosage1) == 0)
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
	else if ((stock2 > 0) && (stock2 >= pill2) && ((prescriptionDosage % dosage2) == 0))
	{
		whichCostEffectiveMethod = 2;
		costEffectiveSolution = cost2*pill2;
	}
	else if ((stock1 > 0) && (stock1 >= pill1) && ((prescriptionDosage % dosage1) == 0))
	{
		whichCostEffectiveMethod = 1;
		costEffectiveSolution = cost1*pill1;
	}
	else
	{
		cout << "Based on the information provided about the prescription, it is not possible to fill this prescription" << endl
			<< "without combining pills of different dosages, or partitioning pills. Rerouting." << endl;
		return;
	}


	cout << "These are the dosages available based on the medication you have chosen: " << endl
		<< dosage1 << "mg @ $" << cost1 << " per pill." << endl
		<< dosage2 << "mg @ $" << cost2 << " per pill." << endl
		<< dosage3 << "mg @ $" << cost3 << " per pill." << endl;

	switch (whichCostEffectiveMethod)
	{
	case 1:
		cout << "The cost-effective recommendation is as follows:" << endl
			<< "Using " << dosage1 << "mg pills, fill the prescription as follows:" << endl
			<< pill1 << "x " << whichMedication << "." << endl
			<< "The cost of this prescription will be " << costEffectiveSolution << "$." << endl;
		break;
	case 2:
		cout << "The cost-effective recommendation is as follows:" << endl
			<< "Using " << dosage2 << "mg pills, fill the prescription as follows:" << endl
			<< pill2 << "x " << whichMedication << "." << endl
			<< "The cost of this prescription will be " << costEffectiveSolution << "$." << endl;
		break;
	case 3:
		cout << "The cost-effective recommendation is as follows:" << endl
			<< "Using " << dosage3 << "mg pills, fill the prescription as follows:" << endl
			<< pill3 << "x " << whichMedication << "." << endl
			<< "The cost of this prescription will be " << costEffectiveSolution << "$." << endl;
		break;
	}


	//_______________________________________________________Print receipt______________________________________________________________________________//

	cout << endl << "The receipt for this transaction is as follows: " << endl << endl;
	//Print receipt file headers
	cout << setw(25) << left << "Patient name:" << setw(25) << left << "Prescription date:"
		<< setw(25) << left << "Medication name:" << setw(25) << left << "Prescription dosage:"
		<< setw(25) << left << "Prescription length:" << setw(25) << left << "Dosage frequency:" << endl;

	//Print specific prescription information
	cout << setw(25) << left << patientName << setw(25) << left << prescriptionDate
		<< setw(25) << left << whichMedication << setw(25) << left << prescriptionDosage
		<< setw(25) << left << prescriptionLength << setw(25) << left << dosageFrequency << endl;


	
	//_______________________________________________________Update stock_______________________________________________________________________________//
	
	//The file containing the quantities of each medication in stock is opened.>>INPUT<<
	stockFileIn.open(".\\PharmacyInformation\\MedicationStock.dat");

	//If the file containing medication stock cannot be opened, an error message is displayed.
	if (stockFileIn.fail())
	{
		cout << "Error opening file containing medication in stock." << endl;
	}

	//This for loop will pull the entire sequential data file containing the medication stock into
	//an array. This array can then be edited and then written back into the sequential data file.
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stockFileIn >> stockArray[i][j];
		}
	}

	//The file containing the quantities of each medication in stock is closed. >>INPUT<<
	stockFileIn.close();

	//This sequence of for loops and if statements will update the specific row containing the medication	
	//stock information.
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == medicationRow)
			{
				for (int k = 0; k < 3; k++)
				{
					if (k == 0)
					{
						stockArray[i][k] = (stock1 - pill1);
					}
					else if (k == 1)
					{
						stockArray[i][k] = (stock2 - pill2);
					}
					else if (k == 2)
					{
						stockArray[i][k] = (stock3 - pill3);
					}//end of if...else
				}//end of k for
			}//end of if
		}//end of j for
	}//end of i for


	//The file containing the quantities of each medication in stock is opened. <<OUTPUT>>
	stockFileOut.open(".\\PharmacyInformation\\MedicationStock.dat");

	//If the file containing medication stock cannot be opened, an error message is displayed.
	if (stockFileOut.fail())
	{
		cout << "Error opening file containing medication in stock." << endl;
	}


	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stockFileOut << setw(15) << left;
			stockFileOut << stockArray[i][j];
			if (j == 2)
			{
				stockFileOut << endl;
			}
		}
	}

	stockFileOut.close(); 

	printScriptReceipt();
}

void Pharmacy::printScriptReceipt()
{
	ofstream receiptFileOut, masterReceiptFileOut;

	//The next few lines represent the concatenation of the file name.
	string receiptFileName = ".\\PharmacyInformation\\Receipts\\";
	
	receiptFileName.append(patientName);
	receiptFileName.append(prescriptionDate);
	receiptFileName.append(".dat");

	receiptFileName.c_str();

	//Create a new file whose name is a concatenation of the patient's name and the date.
	receiptFileOut.open(receiptFileName);

	
	//Error check to make sure the output file has been opened.
	if (receiptFileOut.fail())
	{
		cout << "Error. File containing receipt could not be created." << endl;
	}

	//Print receipt file headers
	receiptFileOut << setw(25) << left << "Patient name:" << setw(25) << left << "Prescription date:"
		<< setw(25) << left << "Medication name:" << setw(25) << left << "Prescription dosage:"
		<< setw(25) << left << "Prescription length:" << setw(25) << left << "Dosage frequency:" << endl;

	//Print specific prescription information
	receiptFileOut << setw(25) << left << patientName << setw(25) << left << prescriptionDate
		<< setw(25) << left << whichMedication << setw(25) << left << prescriptionDosage
		<< setw(25) << left << prescriptionLength << setw(25) << left << dosageFrequency << endl;
	
	//Close the newly-created file containing the receipt
	receiptFileOut.close();

	masterReceiptFileOut.open(".\\PharmacyInformation\\Receipts\\MasterReceipt.dat", std::ios_base::app);

	if (masterReceiptFileOut.fail())
	{
		cout << "Error opening master receipt file." << endl;
	}

	//Print specific prescription information
	masterReceiptFileOut << setw(25) << left << patientName << setw(25) << left << prescriptionDate
		<< setw(25) << left << whichMedication << setw(25) << left << prescriptionDosage
		<< setw(25) << left << prescriptionLength << setw(25) << left << dosageFrequency << endl;

	masterReceiptFileOut.close();

}

void Pharmacy::updateStock()
{
	//Input files
	ifstream namesFileIn, dosagesFileIn, stockFileIn, costsFileIn;
	
	//Output files
	ofstream namesFileOut, dosagesFileOut, stockFileOut, costsFileOut;

	//Decision-making integer variables
	int rowToEdit = 0,
		dataToEdit = 0,
		whichDosageToEdit = 0,
	    areYouFinished = 0;
	//__________________________________________________________IMPORTING NAMES DATA_________________________________________________________________//

	namesFileIn.open(".\\PharmacyInformation\\MedicationNames.dat");

	if (namesFileIn.fail())
	{
		cout << "Error opening the file containing the names of the medications." << endl;
	}

	for (int i = 0; i < 200; i++)
	{
		namesFileIn >> medicationNamesArray[i];
	}

	namesFileIn.close();
	
	//__________________________________________________________IMPORTING DOSAGES DATA_________________________________________________________________//

	dosagesFileIn.open(".\\PharmacyInformation\\MedicationDosages.dat");

	if (dosagesFileIn.fail())
	{
		cout << "Error opening file containing medication dosages" << endl;
	}

	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dosagesFileIn >> medicationDosagesArray[i][j];
		}
	}

	dosagesFileIn.close();


	//______________________________________________________IMPORTING STOCK DATA_____________________________________________________________//

	stockFileIn.open(".\\PharmacyInformation\\MedicationStock.dat");

	if (stockFileIn.fail())
	{
		cout << "Error opening file containing medication stock." << endl;
	}

	//For loop that grabs all stock data and throws it into the stock array. Now capable of being printed to screen.
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stockFileIn >> stockArray[i][j];
		}
	}

	stockFileIn.close();

//_______________________________________________________IMPORTING COSTS DATA___________________________________________________________________//


	costsFileIn.open(".\\PharmacyInformation\\MedicationCosts.dat");

	if (costsFileIn.fail())
	{
		cout << "Error opening file containing medication stock." << endl;
	}


	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			costsFileIn >> medicationCostsArray[i][j];
		}
	}

	costsFileIn.close();


//_______________________________________________________PRINTING OUT STOCK INFO_________________________________________________________//

	int rowWidth = 10;


	do
	{
		

		cout << "Below the stock file is provided. Numbers 1 - 200 are displayed to the left of each medication information. Review the file and enter" << endl
			<< "the number of the row which you would like to edit. You will be continuously prompted to make edits until you decide otherwise." << endl
			<< "Here is the stock list:" << endl << endl;

		cout << setw(15) << left << "Row #:" << setw(15) << left << "Name:" << setw(15) << left << "Dosages:"
			<< setw(15) << left << "Prices:" << setw(15) << left << "Quantity in stock:" << endl << endl;

		for (int i = 0; i < 200; i++)
		{
			
			cout << left << "Row[" << i + 1 << setw(10) << left << "]:" << setw(15) << setfill('_') << left << medicationNamesArray[i];

			for (int j = 0; j < 3; j++)
			{
				if (j != 0)
				{
					cout << "                              ";
				}//end of if

					cout << setw(10) << setfill('_') << right << medicationDosagesArray[i][j]
						<< setw(15) << setfill('_') << right << medicationCostsArray[i][j]
						<< setw(27) << setfill('_') << right << stockArray[i][j] << endl;
				
				if (j == 2)
				{
					cout << endl;
				}
			}//end of j for
		}//end of i for


//__________________________________________________________ALLOWING USER TO EDIT DATA______________________________________________________________//
		//Prompting user to enter the row number they would like to edit.
		cout << endl << endl << "Scroll to top to see pertinent information." << endl
			<< "You may enter [0] if you would not like to make a change." << endl
			<< "Enter the row number you would like to edit : ";
		cin >> rowToEdit;

		if (!rowToEdit)
		{
			break;
		}
		//Headers of medication data
		cout << setw(15) << left << "Name:" << setw(15) << left << "Dosages:"
			<< setw(15) << left << "Prices:" << setw(15) << left << "Quantity in stock:" << endl << endl;


		cout << setw(15) << setfill('_') << left << medicationNamesArray[rowToEdit - 1];

		for (int j = 0; j < 3; j++)
		{
			if (j != 0)
			{
				cout << "               ";
			}//end of if

			cout << setw(10) << setfill('_') << right << medicationDosagesArray[rowToEdit-1][j]
				<< setw(15) << setfill('_') << right << medicationCostsArray[rowToEdit-1][j]
				<< setw(27) << setfill('_') << right << stockArray[rowToEdit-1][j] << endl;

			if (j == 2)
			{
				cout << endl;
			}
		}//end of j for

		do
		{
			//Prompts the user to choose between which edit they would like to make to the medication information
			cout << "Which would you like to edit?" << endl
				<< "Enter [1] to edit the name of the medication." << endl
				<< "Enter [2] to edit the dosages of the medication." << endl
				<< "Enter [3] to edit the prices of the medication." << endl
				<< "Enter [4] to edit the stock of the medication." << endl
				<< "Enter [0] if you would not like to make a change at this time." << endl;

			//Decision making variable that allows user to choose between which medication information they would like to edit
			cin >> dataToEdit;

			//The decision just made is "switched"
			switch (dataToEdit)
			{
			//Case 1 represents changes to medication NAMES
			case 1:
				//User is prompted to enter the change in the medication's name they would like to see.
				cout << "Enter the change to the medication's name:";

				//User inputs the changed name into the array which contains the contents of the name file.
				cin >> medicationNamesArray[rowToEdit - 1];

				//The file containing the names of the medications is opened
				namesFileOut.open(".\\PharmacyInformation\\MedicationNames.dat");

				//ERROR CHECK to make sure the file containing medication names was opened.
				if (namesFileOut.fail())
				{
					cout << "Error opening file containing medication names." << endl;
				}
				//For loop that will overwrite the file containing the medication names using the changed array representing this file.
				for (int i = 0; i < 200; i++)
				{
					namesFileOut << medicationNamesArray[i] << endl;
				}

				namesFileOut.close();
				break;//end of case 1

			//Case 2 represents changes to the medication's DOSAGES
			case 2:

				//do...while loop that runs as long as the user would like. They have to choose to opt out of the loop.
				do
				{
					//Prompts the user to choose between which dosage of medication they would like to edit 
					cout << "Enter the change to the medication's dosage(s):" << endl
						<< "Enter [1] to change the smallest dosage: " << medicationDosagesArray[rowToEdit - 1][0] << endl
						<< "Enter [2] to change the middle dosage: " << medicationDosagesArray[rowToEdit - 1][1] << endl
						<< "Enter [3] to change the largest dosage: " << medicationDosagesArray[rowToEdit - 1][2] << endl;

					//User inputs their choice of which dosage to edit
					cin >> whichDosageToEdit;

					//User inputs the change to the dosage they would like to see.
					cout << "Enter the change in dosage: ";
					cin >> medicationDosagesArray[rowToEdit - 1][whichDosageToEdit - 1];

					dosagesFileOut.open(".\\PharmacyInformation\\MedicationDosages.dat");

					if (dosagesFileOut.fail())
					{
						cout << "Error opening file containing the medication's dosage information." << endl;
					}


					//For loop that will overwrite the file containing the medication dosages using the changed array representing this file.
					for (int i = 0; i < 200; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							
							dosagesFileOut << medicationDosagesArray[i][j];

							if (j == 2)
							{
								dosagesFileOut << endl;
							}
						}
					}

					//The file containing the medication's dosages is closed.
					dosagesFileOut.close();

					//User is asked whether or not they would like to make another change (whether or not they would like to terminate the do...while).
					cout << "Would you like to make another change to the medication's dosage data?" << endl
						<< "Enter [0] to make another change." << endl
						<< "Enter [1] to finish." << endl;
					
					//User makes their decision about whether or not they would like to make another change.
					cin >> areYouFinished;

				} while (!areYouFinished); //end of do...while

				break;//end of case 2

			//Case 3 represents changes to the medication's PRICES
			case 3:

				//do...while loop that runs as long as the user would like. They have to choose to opt out of the loop.
				do
				{
					//Prompts the user to choose between which dosage's price they would like to edit
					cout << "Enter the change to the medication's prices(s):" << endl
						<< "Enter [1] to change the smallest dosage's price: " << medicationCostsArray[rowToEdit - 1][0] << endl
						<< "Enter [2] to change the middle dosage's price: " << medicationCostsArray[rowToEdit - 1][1] << endl
						<< "Enter [3] to change the largest dosage's price: " << medicationCostsArray[rowToEdit - 1][2] << endl;

					//User inputs their choice of which dosage to edit
					cin >> whichDosageToEdit;

					//User inputs the change to the dosage they would like to see.
					cout << "Enter the change in price: ";
					cin >> medicationCostsArray[rowToEdit - 1][whichDosageToEdit - 1];

					costsFileOut.open(".\\PharmacyInformation\\MedicationCosts.dat");

					if (costsFileOut.fail())
					{
						cout << "Error opening file containing the costs of the medications." << endl;
					}

					for (int i = 0; i < 200; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							costsFileOut << medicationCostsArray[i][j];
							if (j == 2)
							{
								costsFileOut << endl;
							}
						}
					}

					//User is asked whether or not they would like to make another change (whether or not they would like to terminate the do...while).
					cout << "Would you like to make another change to the medication's dosage data?" << endl
						<< "Enter [0] to make another change." << endl
						<< "Enter [1] to finish." << endl;

					//User makes their decision about whether or not they would like to make another change.
					cin >> areYouFinished;

				} while (!areYouFinished);//End of do...while.

				break;//end of case 3

			//Case 4 represents changes to the medication's STOCK
			case 4:


				do
				{
					cout << "Enter the change to the medication's stock:" << endl
						<< "Enter [1] to change the smallest dosage's price: " << stockArray[rowToEdit - 1][0] << endl
						<< "Enter [2] to change the middle dosage's price: " << stockArray[rowToEdit - 1][1] << endl
						<< "Enter [3] to change the largest dosage's price: " << stockArray[rowToEdit - 1][2] << endl;
					cin >> whichDosageToEdit;

					cout << "Enter the change in stock: ";
					cin >> stockArray[rowToEdit - 1][whichDosageToEdit - 1];

					dosagesFileOut.open(".\\PharmacyInformation\\MedicationDosages.dat");

					for (int i = 0; i < 200; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							dosagesFileOut << medicationDosagesArray[i][j];

							if (j == 0)
							{
								dosagesFileOut << endl;
							}
						}
					}

					cout << "Would you like to make another change to the medication's stock data?" << endl
						<< "Enter [0] to make another change." << endl
						<< "Enter [1] to finish." << endl;
					cin >> areYouFinished;
				} while (!areYouFinished);
				break;//end of case 4

			default:
				break;
			}

			cout << "Would you like to review the medication data again and potentially make another change?" << endl
				<< "Enter [0] to review medication data again and potentially make another change." << endl
				<< "Enter [1] if you are finished." << endl;
			cin >> areYouFinished;

		} while (!areYouFinished);

		cout << "Would you like to review the entirety of the medication data again and potentially make another change?" << endl
			<< "Enter [0] to review medication data again and potentially make another change." << endl
			<< "Enter [1] if you are finished." << endl;
		cin >> areYouFinished;
	}while (!areYouFinished);
}

void Pharmacy::viewStock()
{
	ifstream stockFileIn, costsFileIn, dosagesFileIn, namesFileIn;


	//______________________________________________________IMPORTING STOCK DATA_____________________________________________________________//
	stockFileIn.open(".\\PharmacyInformation\\MedicationStock.dat");

	if (stockFileIn.fail())
	{
		cout << "Error opening file containing medication stock." << endl;
	}

	//For loop that grabs all stock data and throws it into the stock array. Now capable of being printed to screen.
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stockFileIn >> stockArray[i][j];
		}
	}

	stockFileIn.close();

	//_______________________________________________________IMPORTING COSTS DATA___________________________________________________________________//
	
	
	costsFileIn.open(".\\PharmacyInformation\\MedicationCosts.dat");

	if (costsFileIn.fail())
	{
		cout << "Error opening file containing medication stock." << endl;
	}
	
	
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			costsFileIn >> medicationCostsArray[i][j];
		}
	}
	
	costsFileIn.close();
	
	//__________________________________________________________IMPORTING DOSAGES DATA_________________________________________________________________//
	
	dosagesFileIn.open(".\\PharmacyInformation\\MedicationDosages.dat");

	if (dosagesFileIn.fail())
	{
		cout << "Error opening file containing medication dosages" << endl;
	}

	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dosagesFileIn >> medicationDosagesArray[i][j];
		}
	}

	dosagesFileIn.close();
	
	
	//__________________________________________________________IMPORTING NAMES DATA_________________________________________________________________//

	namesFileIn.open(".\\PharmacyInformation\\MedicationNames.dat");

	if (namesFileIn.fail())
	{
		cout << "Error opening the file containing the names of the medications." << endl;
	}

	for (int i = 0; i < 200; i++)
	{
		namesFileIn >> medicationNamesArray[i];
	}
	
	namesFileIn.close();


//______________________________________________________________PRINTING OUT INFORMATION______________________________________________________________//
	cout << setw(15) << setfill('_') << left << "Name:" << setw(15) << setfill('_') << left << "Dosages:"
		<< setw(15) << setfill('_') << left << "Prices:" << setw(15) << setfill('_') << left << "Quantity in stock:" << endl << endl;

	for (int i = 0; i < 200; i++)
	{
		cout << setw(15) << setfill('.') << left << medicationNamesArray[i];

		for (int j = 0; j < 3; j++)
		{
			if (j != 0)
			{
				cout << "               ";
			}//end of if
			
			cout << setw(15) << setfill('_') << right << medicationDosagesArray[i][j]
				<< setw(15) << setfill('_') << right << medicationCostsArray[i][j]
				<< setw(15) << setfill('_') << right << stockArray[i][j] << endl;
			if (j == 2)
			{
				cout << endl;
			}
		}//end of j for
	}//end of i for
}

void Pharmacy::displayReceipts()
{

	//Variable declarations
	ifstream masterReceiptFile;
	string pointlessString;



	//counting variables
	int count = 0,
		indexRowCount = 0,
		indexColumnCount = 0;

	//Opening the master receipt file
	masterReceiptFile.open(".\\PharmacyInformation\\Receipts\\MasterReceipt.dat");
	
	//If the file containing the master receipt list fails to open, then display an error
	if (masterReceiptFile.fail())
	{
		cout << "Error opening master receipt file." << endl;
	}

	//While not at the end of the file, set our counting variable equal to the number of rows in the file.
	while (!masterReceiptFile.eof())
	{
		getline(masterReceiptFile, pointlessString);
		count++;
	}

	for (int i = (count - 50); i > count; i++)
	{
		getline(masterReceiptFile, medicationNamesArray[indexRowCount]);

		for (indexColumnCount = 0; indexColumnCount < 3; indexColumnCount++)
		{
			masterReceiptFile >> medicationCostsArray[i][indexColumnCount];
			masterReceiptFile >> medicationDosagesArray[i][indexColumnCount];
			masterReceiptFile >> stockArray[i][indexColumnCount];
		}
			indexRowCount++;
	}

	//Print specific prescription information
	cout << setw(25) << setfill('_') << left << "Patient Name:" << setw(25) << setfill('_') << left << "Prescription Date:" 
		<< setw(25) << setfill('_') << left << "Medication Name:" << setw(25) << setfill('_') << left << "Dosages:"
		<< setw(25) << setfill('_') << left << "Prices:" << setw(25) << setfill('_') << left << "Quantity in stock:" << endl << endl;

	for (int i = 0; i < 50; i++)
	{
		cout << setw(25) << setfill('.') << left << medicationNamesArray[i];

		for (int j = 0; j < 3; j++)
		{
			if (j != 0)
			{
				cout << "               ";
			}//end of if

			cout << setw(25) << setfill('_') << right << medicationDosagesArray[i][j]
				<< setw(25) << setfill('_') << right << medicationCostsArray[i][j]
				<< setw(25) << setfill('_') << right << stockArray[i][j] << endl;
			if (j == 2)
			{
				cout << endl;
			}
		}//end of j for
	}//end of i for

	masterReceiptFile.close();
}