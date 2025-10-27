#pragma once
#include <iostream>
#include <iomanip>
#include"clsMainScreen.h"
#include"clsUser.h"
#include "Global.h"


class clsShowLoginScreen :protected clsScreen
{
	static bool _Login()
	{
		short FailedLoginCount =0;
		bool LoginFaild = false;
		string Username, Password;
		do
		{
			if (LoginFaild)
			{
				FailedLoginCount++;

				cout << endl << "Invlaid UserName/PassWord" << endl << endl;
				cout << "Yoy Have " << (3-FailedLoginCount) << "Trial(s) To Login ." << endl;
				if (FailedLoginCount == 3)
				{
					cout << "You Are Locked After 3 Faild Trials " << endl << endl;
					return false;
			}
			}
			cout << "Enter User Name  ";
			cin >> Username;
			cout << "Enter Password  ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;

	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}
};

