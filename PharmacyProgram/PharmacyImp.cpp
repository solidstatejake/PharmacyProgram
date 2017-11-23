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

}


void Pharmacy::introToUser()
{
	cout << "PharmaTech Version 1.0" << endl
}


void Pharmacy::grabUsername(string &username, string &password)
{
	cout << "Please enter your username: ";
	cin >> username;

	cout << "Please enter your password: ";
	cin >> password;

}

int Pharmacy::verifyCredentials(string username, string password)
{
	cout << "";

	return 0; //NEEDS TO BE CHANGED. THE IDEA IS THAT IT WILL RETURN -1 IF ACCESS DENIED AND 1 IF GRANTED
}

void Pharmacy::viewStock()
{
	//Provide code that opens the file containing stock and allows changes.
}