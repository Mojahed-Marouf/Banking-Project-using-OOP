#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
class clsShowAddNewClientScreen:protected clsScreen
{
private:
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
	static void showAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enpermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("Add New CLient");
		string accountnumber = "";
		cout << "please enter the account number" << endl;
		accountnumber = clsInputvalidate::readstring();
		while (clsBankClient::IsClientExists(accountnumber))
		{
			cout << "this account number is already used try again" << endl;

			accountnumber = clsInputvalidate::readstring();

		}
		clsBankClient newclient = clsBankClient::GetAddNewclientobject(accountnumber);
		_ReadClientInfo(newclient);
		clsBankClient::ensave saveresult;
		saveresult = newclient.save();
		switch (saveresult)
		{
		case clsBankClient::ensave::svSuccessed:
		{
			cout << "client added successfuly " << endl;
			_print(newclient);
			break;

		}

		case clsBankClient::ensave::svFalidEmptyObjesct:
		{
			cout << "error account was not saved cuz its empty " << endl;
			break;
		}
		}

	}

};

