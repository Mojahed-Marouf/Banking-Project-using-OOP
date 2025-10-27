#pragma once
#include <iostream>
#include "clsBankClient.h"
using namespace std;
class clsDeleteClientScreen :protected clsScreen
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
public:
	
	static void ShowDeleteClientScreen()
		{
		if (!CheckAccessRights(clsUser::enpermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("Delete Client Screen");
			string accountnumber = "";
			cout << "please enter your account number" << endl;
			accountnumber = clsInputvalidate::readstring();
			while (!clsBankClient::IsClientExists(accountnumber))
			{
				cout << "not found  try again" << endl;

				accountnumber = clsInputvalidate::readstring();

			}
			clsBankClient client1 = clsBankClient::Find(accountnumber);
			client1.print();
			cout << "are you sure yoy want delete it y/n ?" << endl;
			char ans = 'n';
			cin >> ans;
			if (tolower(ans) == 'y')
			{
				if (client1.Delete())
				{
					cout << "deleted successfuly" << endl;
					_print(client1);
				}


				else
					cout << "error client was not deleted " << endl;
			}


		}

	
};

