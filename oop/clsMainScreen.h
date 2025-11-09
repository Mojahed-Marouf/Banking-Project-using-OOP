#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsShowClientsListScreen.h"
#include "clsShowAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsCurrency.h"
#include "clsManageUsersScreen.h"
#include "clsShowLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"


using namespace std;
class clsMainScreen:protected clsScreen
{private:
	enum enMainMenuOptions{ eListClients = 1, eAddNewClient = 2,eDeleteClient=3,
	eUpdateClient=4,eFindClient=5,eShowTransactionsMenu=6,eManageUsers=7,eLoginRegister=8,eCurrency=9,eExit= 10
	};
	static short _ReadMainMenuOption()
	{
		  
		cout << endl;
			cout << "\t" << " " << "choose what do you want to do [ 1 - 10 ]" <<endl;
			short choice = clsInputvalidate::readintnumber(1, 10,"Enter Number Between 1 and 10");
			return choice;

	}
	static void _ShowListClientScreen()
	{
		clsShowClientsListScreen::ShowAllClientsScreen();
	}
	static void _ShowAddNewClientsScreen()
	{
		clsShowAddNewClientScreen::showAddNewClientScreen();

	}
	static void _ShowDeleteClientScreen()
		{
		clsDeleteClientScreen::ShowDeleteClientScreen();
		}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsMenue()
	{
		clsTransactionScreen::ShowTransactionMenu();
	}
	static void _ShowManageUsersMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	}
	static void _ShowLoginRegisterScreen()
	{
		clsShowLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");

	}


	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowMainMenu();

	}
	static void _PerformMainMenuOption(enMainMenuOptions choice)
	{
		switch (choice)
		{
		case enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowListClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eCurrency:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}


		}
	}

	

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("MainScreen");
		
		cout << "\t"<< " " << "===========================================" << endl;
		cout << "\t"<< " " << "             Main Menu" << endl;
		cout << "\t"<< " " << "===========================================" << endl;
		cout << "\t"<< " " << "[1] Show Client List " << endl;
		cout << "\t"<< " " << "[2] ADD New Client  " << endl;
		cout << "\t"<< " " << "[3] Delete Client  " << endl;
		cout << "\t"<< " " << "[4] Update Client  " << endl;
		cout << "\t"<< " " << "[5] Find Client  " << endl;
		cout << "\t"<< " " << "[6] Transactions   " << endl;
		cout << "\t"<< " " << "[7] Manage Users   " << endl;
		cout << "\t"<< " " << "[8] Login Register   " << endl;
		cout << "\t"<< " " << "[9] Currency Exchange  " << endl;
		cout << "\t"<< " " << "[10] LogOut   " << endl;
		cout << "\t"<< " " << "===========================================" << endl;
		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
		

	}



};

