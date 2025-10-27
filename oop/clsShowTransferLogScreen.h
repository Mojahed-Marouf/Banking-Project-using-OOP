#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsShowTransferLogScreen: protected clsScreen
{
	static void PrintLogTransferRecord(clsBankClient::stTransferLog Record)
	{
		cout << setw(8) << left << " " << "| " << setw(23) << left << Record.DateTime <<
			"| " << setw(8) << left << Record.sAccountNumber<<
			"| " << setw(8) << left << Record.dAccountNumber <<
			"| " << setw(8) << left << Record.Amount <<
			"| " << setw(10) << left << Record.sBalance <<
			"| " << setw(10) << left << Record.dBalance <<
			"| " << setw(8) << left << Record.UserName;
	}

public:
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLog> vTransferRecord = clsBankClient::GetLogTransferList();
		string Title = " Log Transfer List Screen";
		string SubTitle = " (" + to_string(vTransferRecord.size()) + ") Record(S)";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


		cout << setw(8) << left << " "
			<< "| " << setw(23) << left << "Date/Time"
			<< "| " << setw(8) << left << "s.Account"
			<< "| " << setw(8) << left << "a.Account"
			<< "| " << setw(8) << left << "Amount"
			<< "| " << setw(10) << left << "s.Balance"
			<< "| " << setw(10) << left << "d.Balance"
			<< "| " << setw(8) << left << "User Name";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vTransferRecord.size() == 0)
			cout << "no Transfer logs available in the system" << endl;
		else
		{

			for (clsBankClient::stTransferLog Record : vTransferRecord)
			{
				PrintLogTransferRecord(Record);
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

	}
	
};

