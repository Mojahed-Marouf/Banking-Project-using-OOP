#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsUpdateUserScreen :protected clsScreen
{
private:
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

        cout << "\nEnter Account Balance: ";
        User.Permissions = _ReadPermissionsToSet();
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
        cout << "\Show Register Login ? y/n? ";
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
    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("Update User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputvalidate::readstring();

        while (!clsUser::IsUsertExists(UserName))
        {
            cout << "\ User Name is not found, choose another one: ";
            UserName = clsInputvalidate::readstring();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::ensave SaveResult;

            SaveResult = User1.save();

            switch (SaveResult)
            {
            case  clsUser::ensave::svSuccessed:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::ensave::svFalidEmptyObjesct:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
   
};

