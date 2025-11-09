#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputvalidate.h"
#include "clsPerson.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogScreen.h"


using namespace std;
class clsTransactionScreen :protected clsScreen
{
private:
	enum enTransactionsMenuOptions{eDeposit=1,eWithdraw=2,eShowTotalBalnce=3,eTransfer=4,eTransferLog=5,eShowMainMenu=6};
	static short _ReadTransactionsOption()
	{


		cout << "\t" << " " << "chose what do you want to do [ 1 - 6 ]" << endl;
		short choice = clsInputvalidate::readintnumber(1, 6, "Enter Number Between 1 and 6");
		return choice;

	}
	static void _GoBackToTransactionsMenu()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionMenu();

	}
	static void ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithDrawScreen()
			;
	}
	static void ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}
	static void ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();

	}
	static void ShowTransferLogScreen()
	{
		clsShowTransferLogScreen::ShowTransferLogScreen();
	}
	static void _PerforTransactionsOption(enTransactionsMenuOptions choice)
	{
		switch (choice)
		{
		case enTransactionsMenuOptions::eDeposit:
		{
			system("cls");
			ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eWithdraw:
		{
			system("cls");
			ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowTotalBalnce:
		{
			system("cls");
			ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransfer:
		{
			system("cls");
			ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransferLog:
		{
			system("cls");
			ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowMainMenu:
		{
			
		}
		}
	}
public:
	static void ShowTransactionMenu()
	{
		if (!CheckAccessRights(clsUser::enpermissions::pTransactios))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Transactions Screen");
		cout << "\t"<< " " << "=============================================================" << endl;
		cout << "\t"<< " " << "\t\t  Transaction Menu" << endl;
		cout << "\t"<< " " << "=============================================================" << endl;
		cout << "\t"<< " " << "\t [1] Deposit " << endl;
		cout << "\t"<< " " << "\t [2] Withdraw " << endl;
		cout << "\t"<< " " << "\t [3] Total Balnces " << endl;
		cout << "\t"<< " " << "\t [4] Transfer  " << endl;
		cout << "\t"<< " " << "\t [5] Transfer Log  " << endl;
		cout << "\t"<< " " << "\t [6] Main Menu " << endl;
		cout << "\t"<< " " << "=============================================================" << endl;
		_PerforTransactionsOption((enTransactionsMenuOptions)_ReadTransactionsOption());
	}
};

