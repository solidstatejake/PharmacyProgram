#include "stdafx.h"
#include "Pharmacy.h"

using namespace std;

Pharmacy::Pharmacy()
{
}


Pharmacy::~Pharmacy()
{
}

void Pharmacy::clearConsole()
{
	system("CLS");
}


void Pharmacy::introToUser()
{
	cout << "PharmaTech Version 1.0" << endl;
}


void Pharmacy::grabUsername()//string &username, string &password)
{
	cout << "Please enter your username: ";
	cin >> username;

	cout << "Please enter your password: ";
	cin >> password;

}

int Pharmacy::verifyCredentials(string username, string password)
{
	//Input file variables used to access the files containing usernames and passwords
	ifstream usernameFile, passwordFile;

	//String used to carry in and hold names from username/password files. Variable is compared to what the user
	//inputs as their username to check the validity of their entry. 
	string compareCreds;

	int usernameYesOrNo = 0,
		passwordYesOrNo = 0;

	//Opens the file containing verified username information
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
			usernameYesOrNo = 1;
		}
		else
		{
			usernameYesOrNo = 0;
			return 0;
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
	}

	//While not at the end of file (eof), user-entered username will be compared to verified usernames in the
	//file "usernames.dat".
	while (!passwordFile.eof())
	{
		//Verified username is copied from username file and placed into compareCreds string.
		getline(passwordFile, compareCreds);

		//compareCreds string is compared to user-entered username. If two match, username is accepted. Else not accepted.
		if (compareCreds == password)
		{
			passwordYesOrNo = 1;
		}
		else
		{
			passwordYesOrNo = 0;
			return 0;
		}
	}


	if (usernameYesOrNo + passwordYesOrNo == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

void Pharmacy::viewStock()
{
	//Provide code that opens the file containing stock and allows changes.
}