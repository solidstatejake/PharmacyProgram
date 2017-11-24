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

int Pharmacy::verifyCredentials() const
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
		
		cout << "Would you like to do something else?" << endl
			<< "Enter [1] if you would like to display the list of options again." << endl
			<< "Enter [0] if you are done making decisions." << endl;

		cin >> continueOrNot;
	} while (continueOrNot);
	

}


void Pharmacy::fillPrescription()
{

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