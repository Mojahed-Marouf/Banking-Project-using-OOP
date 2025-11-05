#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"     
#include "clsInputvalidate.h"
#include <iomanip>
using namespace std;
class clsFindCurrencyScreen :protected clsScreen
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
static void _ShowResults(clsCurrency Currency)
{
	if (Currency.IsEmpty())
	{
		cout << " Currencu Not Available" << endl;
	}
	else
	{
		cout << "Currency Found :)" << endl;
		_PrintCard(Currency);

	}
}

public:
	static void ShowFindCurrencyScreen()
	{
		short Choice = 1;
		_DrawScreenHeader("Find Currency Screen");
		Choice=clsInputvalidate::readintnumber(1, 2, "Find By : [1] Code or [2] Country ??  ");
		if (Choice == 1)
		{
			string CurrencyCode = "";
			cout << "PLEASE ENTER CURRENCY CODE  ";
			CurrencyCode = clsInputvalidate::readstring();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);

		}
		else
		{
			string CurrencyCountry = "";
			cout << "PLEASE ENTER  Country Name";
			CurrencyCountry = clsInputvalidate::readstring();
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);
			_ShowResults(Currency);

		}
	}


};

