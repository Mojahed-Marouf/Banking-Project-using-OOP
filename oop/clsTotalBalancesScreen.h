#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputvalidate.h"
#include "clsUtil.h"
#include "clsPerson.h"
using namespace std;
class clsTotalBalancesScreen :protected clsScreen
{
private:
	static void PrintClientRecordsBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.GetFullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:

	static void ShowTotalBalancesScreen()
	{
		system("cls");
		vector <clsBankClient> vclient = clsBankClient::getclientlist();
		string Title = "Balances List Client";
		string subTitle = " (" + to_string(vclient.size()) + ") clients (s)";
		_DrawScreenHeader(Title,subTitle);
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();
		if (vclient.size() == 0)
			cout << "\t\t\t NO CLIENTS AVAILABLE IN THE SYSTEM" << endl;
		for (clsBankClient Client : vclient)
		{
			PrintClientRecordsBalanceLine(Client);
			cout << endl;

		}
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";


	}
};

