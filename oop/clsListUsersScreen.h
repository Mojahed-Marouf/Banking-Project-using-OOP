#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsListUsersScreen :protected clsScreen
{
	static void _PrintUserRecordLine(clsUser User)
	{

		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.GetFullName();
		cout << "| " << setw(12) << left << User.PhoneNumber;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
		cout << endl;
	}

public:
	static void ShowUsersList()
	{
		vector <clsUser> vuser = clsUser::GetUsersList();
		string Title = " User List Screen";
		string SubTitle = " (" + to_string(vuser.size()) + ") Users(S)";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << " "
			<< "| " << setw(12) << left << "User Name"
			<< "| " << setw(25) << left << "Full Name"
			<< "| " << setw(12) << left << "Phone"
			<< "| " << setw(20) << left << "Email"
			<< "| " << setw(10) << left << "Password"
			<< "| " << setw(12) << left << "Permissions"
			<< endl;
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vuser.size() == 0)
			cout << "no available clients" << endl;
		else
		{

			for (clsUser& user : vuser)
			{
				_PrintUserRecordLine(user);
			}
		}

		cout << "------------------------------------------------------------------------------------------------------------------------\n";

	}
	
	
};

