#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsTransferScreen :protected clsScreen
{
	static string _ReadAccountNumber(string massege)
	{
		string AccountNumber = "";
		cout << massege;
		cin >> AccountNumber;
		cout << endl;
		return AccountNumber;

	}
	static void _PrintClient(clsBankClient Client)
	{
		cout << "Client Card  : " << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "FullName   : " << Client.GetFullName() << endl;
		cout << "AccountNumber: " << Client.GetAccountNumber() << endl;
		cout << "AccountBalance: " << Client.AccountBalance << endl;
		cout << "------------------------------------" << endl << endl;

		cout << endl << endl;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader(" Transfer Screen ");

		string AccountNumberFrom = _ReadAccountNumber("Please Enter Account Number To Transfer From");
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumberFrom);
		_PrintClient(ClientFrom);

		string AccountNumberTo = _ReadAccountNumber("Please Enter Account Number To Transfer To");
		clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);
		_PrintClient(ClientTo);

		double Amount = 0;
		cout << "please enter WithDraw amount ?";
		Amount = clsInputvalidate::readdoublenumber();
		while (Amount > ClientFrom.AccountBalance)
		{
			cout << "Amount Exceeds the Account Balance ,Please Enter Another Amount >?";
			Amount = clsInputvalidate::readdoublenumber();
		}
		char ans = 'n';
		cout << "are you sure to perform this transaction";
		cin >> ans;
		if (tolower(ans) == 'y')
		{
			if (ClientTo.Transfer(Amount, ClientTo,CurrentUser.UserName))
			{
				cout << "Transfer Done Sucessfully " << endl;

			}
			else
				cout << " Transfer Cancelled" << endl;

			_PrintClient(ClientFrom);
			_PrintClient(ClientTo);
		}
		else
			cout << "Transfer Was Cancelled" << endl;
		
	}

	
};

