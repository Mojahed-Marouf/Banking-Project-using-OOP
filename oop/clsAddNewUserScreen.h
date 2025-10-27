#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsAddNewUserScreen :protected clsScreen
{
 static	void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputvalidate::readstring();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputvalidate::readstring();

		cout << "\nEnter Email: ";
		User.Email = clsInputvalidate::readstring();

		cout << "\nEnter Phone: ";
		User.PhoneNumber = clsInputvalidate::readstring();

		cout << "\nEnter PinCode: ";
		User.Password = clsInputvalidate::readstring();

		cout << "\nEnter Account Permissions: ";
		User.Permissions =_ReadPermissionsToSet();
	}
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enpermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pTransactios;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pManageUsers;
        }
        cout << "\Register Login Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enpermissions::pLogRegister;
        }
        return Permissions;

    }
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
	static void ShowAddNewScreen()
	{
        _DrawScreenHeader("ADD NEW USER SCREEN");
        string username = "";
        cout << "please enter your username " << endl;
        username = clsInputvalidate::readstring();
        while (clsUser::IsUsertExists(username))
        {
            cout << "your username  is already used try again" << endl;

            username = clsInputvalidate::readstring();

        }
        clsUser newuser = clsUser::GetAddNewUserObject(username);
        _ReadUserInfo(newuser);
        clsUser::ensave saveresult;
        saveresult = newuser.save();
        switch (saveresult)
        {
        case clsUser::ensave::svSuccessed:
        {
            cout << "user added successfuly " << endl;
            _PrintUser(newuser);
            break;

        }

        case clsUser::ensave::svFalidEmptyObjesct:
        {
            cout << "error account was not saved cuz its empty " << endl;
            break;
        }
        }
	}
};

