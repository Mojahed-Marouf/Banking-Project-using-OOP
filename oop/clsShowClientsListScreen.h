#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
using namespace std;
class clsShowClientsListScreen:protected clsScreen
{
   static void printclientrecordline(clsBankClient client)
    {
   
        cout << setw(8) << left << "" << "| " << left << setw(15) << client.GetAccountNumber();
        cout << "| " << left << setw(20) << client.GetFullName();
        cout << "| " << left << setw(12) << client.Email;
        cout << "| " << left << setw(20) << client.PhoneNumber;
        cout << "| " << left << setw(10) << client.PinCode;
        cout << "| " << left << setw(12) << client.AccountBalance;
        cout << '\n';

    }



public:

   static void ShowAllClientsScreen()
        
    {
       if (!CheckAccessRights(clsUser::enpermissions::pListClients))
       {
           return;
       }

        vector <clsBankClient> vClients = clsBankClient::getclientlist();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Email";
        cout << "| " << left << setw(20) << "Phone";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                printclientrecordline(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

