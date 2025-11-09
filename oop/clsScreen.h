#pragma once
#include <iostream>
#include "Global.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title,string subtitle="")
	{
		cout << "\t""----------------------------------------------------------" << endl;
		cout << "\t""                   " << Title << endl;
		if(subtitle!="")
		cout << "\t""                   " << subtitle << endl;
		cout << "\t""----------------------------------------------------------" << endl;
		cout << endl << endl;
		cout << "\t\t\t""User:" << CurrentUser.UserName << endl;
		cout << "\t\t\t""Date:" << clsDate::datetostring(clsDate())<<endl;


	}
	static bool CheckAccessRights(clsUser::enpermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermissions(Permission))
		{
			cout << "\t\t\t\t-----------------------------------------------" << endl << endl;;
			cout << "\t\t\t\t  Access Denied!!Contatact Your Admin          " << endl << endl;;
			cout << "\t\t\t\t-----------------------------------------------" << endl << endl;;
			return false;
		}
		else
		{
			return true;
		}
	}

};

