#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsFindUserScreen :protected clsScreen
{
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.GetFullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.PhoneNumber;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("User Find Screen");
		string username = "";
		cout << endl << "Please Enter UserName  ";
		username = clsInputvalidate::readstring();
		while (!clsUser::IsUsertExists(username))
		{
			cout << endl << "User IsNot Found , Choose Another One";
			username = clsInputvalidate::readstring();

		}
		clsUser User1 = clsUser::Find(username);

		if (!User1.IsEmpty())
		{
			cout << endl << "User Found " << endl;

		}
		else
		{
			cout << endl << "User Was Not Found " << endl;

		}
		_PrintUser(User1);
	}
};

