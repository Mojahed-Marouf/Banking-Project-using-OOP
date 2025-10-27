#pragma once
#include <iostream>
#include "clsBankClient.h"
using namespace std;
class clsUpdateClientScreen :protected clsScreen
{private:
	static void _print(clsBankClient client)
	{
		cout << "Client Code  : " << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "FirstName  : " << client.FirstName << endl;
		cout << "LastName   : " << client.LastName << endl;
		cout << "FullName   : " << client.GetFullName() << endl;
		cout << "Email      : " << client.Email << endl;
		cout << "PhoneNumber: " << client.PhoneNumber << endl;
		cout << "AccountNumber: " << client.GetAccountNumber() << endl;
		cout << "PinCode: " << client.PinCode << endl;
		cout << "AccountBalance: " << client.AccountBalance << endl;
		cout << "------------------------------------" << endl << endl;

		cout << endl << endl;
	}
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputvalidate::readstring();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputvalidate::readstring();

		cout << "\nEnter Email: ";
		Client.Email = clsInputvalidate::readstring();

		cout << "\nEnter Phone: ";
		Client.PhoneNumber = clsInputvalidate::readstring();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputvalidate::readstring();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputvalidate::readdoublenumber();
	}


public:
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enpermissions::pUpdateClient))
		{
			return;
		}
		_DrawScreenHeader("Update Client Screen");
		string AccountNumber = "";
		cout << "please enterclient account number";
		AccountNumber = clsInputvalidate::readstring();
		while (!clsBankClient::IsClientExists(AccountNumber))
		{
			cout << endl << "Account number is not found , chose another one";
			AccountNumber = clsInputvalidate::readstring();
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		client.print();
		cout << endl << "Update Client Info" << endl;
		cout << "-----------------------------------" << endl;

		_ReadClientInfo(client);

		clsBankClient::ensave saveresult;
		saveresult = client.save();

		switch (saveresult)
		{
		case clsBankClient::ensave::svSuccessed:
		{
			cout << "Account Updated Successfuly" << endl;
			client.print();
			break;
		}
		case clsBankClient::ensave::svFalidEmptyObjesct:
		{
			cout << "  Error account was not saves cuz its empty" << endl;
			break;
		}

		}

	}
};

