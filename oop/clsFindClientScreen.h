#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputvalidate.h"
#include "clsPerson.h"



using namespace std;
class clsFindClientScreen :protected clsScreen
{
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
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enpermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("Find Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputvalidate::readstring();
        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputvalidate::readstring();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _print(Client1);

    }

};

