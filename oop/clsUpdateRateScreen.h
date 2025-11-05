#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"     
#include "clsInputvalidate.h"
#include <iomanip>
using namespace std;
class clsUpdateRateScreen :protected clsScreen
{private:


	static void _PrintCard(clsCurrency Currency)
	{
		cout << "Currency Card :" << endl << endl;
		cout << "-----------------------------" << endl;
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "-----------------------------" << endl;

	}
	static float _ReadRate() {
		cout << "\nEnter New Rate : ";
		float NewRate = 0;
		NewRate = clsInputvalidate::readdoublenumber();
		return NewRate;
	}


public:
	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("Update Currency Screen");
		char ans = 'n';
		string CurrencyCode;
		cout << "PLEASE ENTER CURRENCY CODE :";
		CurrencyCode = clsInputvalidate::readstring();
		cout << endl;
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << " CURRENCY IS NOT FOUND TRY AGAIN :";
			CurrencyCode = clsInputvalidate::readstring();
		}
		clsCurrency Currency=clsCurrency::FindByCode(CurrencyCode);
		_PrintCard(Currency);
		cout << "Are You Sure You Want To Update Rate Of This Currency y/n" << endl;
		cin >> ans;
		if (tolower(ans) == 'y')
		{
			cout << "Update Currency Rate :" << endl;
			cout << "------------------------------" << endl;
			cout << endl;
			cout << "Enter New Rate";
			cout << endl;

			Currency.UpdateRate(_ReadRate());
				cout << "------------------------------" << endl;
				cout << endl << " Currency Rate Update Successfully :)" << endl;
				_PrintCard(Currency);
		}
		
	}
};

