#pragma once
#include <iostream>
#include <iomanip>
#include"clsMainScreen.h"
#include"clsUser.h"
#include "Global.h"
class clsShowLoginRegisterScreen :protected clsScreen
{
	
	static void PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord Record)
	{
		cout << setw(8) << left << " " << "| " << setw(35) << left << Record.DateTime <<
			"| " << setw(20) << left << Record.UserName <<
			"| " << setw(20) << left << Record.Password <<
			"| " << setw(10) << left << Record.Permissions;
		cout << endl << endl;
	}


public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enpermissions::pLogRegister))
		{
			return;
		}
		vector <clsUser::stLoginRegisterRecord> vloginRegisterRecord = clsUser::GetLoginRegisterList();
		string Title = " Login Register List Screen";
		string SubTitle = " (" + to_string(vloginRegisterRecord.size()) + ") Record(S)";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << " " << "| " << setw(35)<<left << "Date/Time" <<
			"| " <<  setw(20)<<left  << "User Name  " <<
			"| " << setw(20) << left << "Password" <<
			"| " << setw(10) << left << "Permissions";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vloginRegisterRecord.size() == 0)
			cout << "no logins available in the system" << endl;
		else
		{

			for (clsUser::stLoginRegisterRecord Record : vloginRegisterRecord)
			{
				PrintLoginRegisterRecord(Record);
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

	}
};

