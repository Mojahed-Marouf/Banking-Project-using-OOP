#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputvalidate.h"
#include "clsPerson.h"
using namespace std;
class clsDepositScreen :protected clsScreen
{private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "please enter the account Number";
		cin >> AccountNumber;
		cout << endl;
		return AccountNumber;

	}
	static void _PrintClient(clsBankClient Client)
	{
		cout << "Client Code  : " << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "FirstName  : " << Client.FirstName << endl;
		cout << "LastName   : " << Client.LastName << endl;
		cout << "FullName   : " << Client.GetFullName() << endl;
		cout << "Email      : " << Client.Email << endl;
		cout << "PhoneNumber: " << Client.PhoneNumber << endl;
		cout << "AccountNumber: " << Client.GetAccountNumber() << endl;
		cout << "PinCode: " << Client.PinCode << endl;
		cout << "AccountBalance: " << Client.AccountBalance << endl;
		cout << "------------------------------------" << endl << endl;

		cout << endl << endl;
	}

public:
	static void ShowDepositScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Deposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExists(AccountNumber))
		{
			cout << "the account Number [" << AccountNumber << "] Not Found Try Again >>" << endl;
			AccountNumber = _ReadAccountNumber();

		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "please enter deposite amount ?";
		Amount = clsInputvalidate::readdoublenumber();
		char ans = 'n';
		cout << "are you sure to perform this transaction";

		cin >> ans;
		if (tolower(ans) == 'y')
		{
			Client.Deposit(Amount);
				cout << "Amout Deposited Sucessfully " << endl;
			cout << "  Your Balance Now  =" <<Client.AccountBalance<< endl;
			

		}
		else
			cout << "Operation Was Cancelled" << endl;
	}
};

