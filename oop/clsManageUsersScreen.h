#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputvalidate.h"
#include "clsPerson.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen :protected clsScreen
{private:
	enum enManageUsersMenuOptions { eListUseres = 1, eAddNewUser=2 , eDeleteUser=3 , eUpdateUser=4,
	eFindUser=5,eMainMenu=6
	};
	static short _ReadManageUserOption()
	{


		cout <<"\t" << " " << "chose what do you want to do [ 1 - 6 ]" << endl;
		short choice = clsInputvalidate::readintnumber(1,6, "Enter Number Between 1 and 6");
		return choice;

	}
	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();

	}
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsresMenuOption(enManageUsersMenuOptions choice)
	{
		switch (choice)
		{
		case enManageUsersMenuOptions::eListUseres:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenuOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenuOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenuOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenuOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenuOptions::eMainMenu:
		{
			
		}

		}
	}


public:
	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enpermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Manage Users Screen");
		cout << "\t"<< " " << "=============================================================" << endl;
		cout << "\t"<< " " << "\t\t  Manage Users Menu" << endl;
		cout << "\t"<< " " << "=============================================================" << endl;
		cout << "\t"<< " " << "\t [1] List Users " << endl;
		cout << "\t"<< " " << "\t [2] Add New User " << endl;
		cout << "\t"<< " " << "\t [3] Delete User " << endl;
		cout << "\t"<< " " << "\t [4] Update User " << endl;
		cout << "\t"<< " " << "\t [5] Find User " << endl;
		cout << "\t"<< " " << "\t [6] Main Menu " << endl;

		cout << "\t" << " " << "=============================================================" << endl;
		_PerformManageUsresMenuOption((enManageUsersMenuOptions)_ReadManageUserOption());

	}
};

