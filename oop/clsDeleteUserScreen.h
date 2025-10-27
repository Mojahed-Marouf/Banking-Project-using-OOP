#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsDeleteUserScreen :protected clsScreen
{
	static void _print(clsUser user)
	{
		cout << "User Card : " << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "FirstName  : " << user.FirstName << endl;
		cout << "LastName   : " << user.LastName << endl;
		cout << "FullName   : " << user.GetFullName() << endl;
		cout << "Email      : " << user.Email << endl;
		cout << "PhoneNumber: " << user.PhoneNumber << endl;
		cout << "UserName: " << user.UserName << endl;
		cout << "Password: " << user.Password << endl;
		cout << "Permissions: " << user.Permissions << endl;
		cout << "------------------------------------" << endl << endl;

		cout << endl << endl;
	}


public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		string username = "";
		cout << "please enter your  username" << endl;
		username = clsInputvalidate::readstring();
		while (!clsUser::IsUsertExists(username))
		{
			cout << "not found  try again" << endl;

			username = clsInputvalidate::readstring();

		}
		clsUser User1 = clsUser::Find(username);
		_print(User1);
		cout << "are you sure yoy want delete it y/n ?" << endl;
		char ans = 'n';
		cin >> ans;
		if (tolower(ans) == 'y')
		{
			if (User1.Delete())
			{
				cout << "deleted successfuly" << endl;
				_print(User1);
			}


			else
				cout << "error client was not deleted " << endl;
		}

	}
	
};

