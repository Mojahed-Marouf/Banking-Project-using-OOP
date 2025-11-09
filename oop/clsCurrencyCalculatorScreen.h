#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"     
#include "clsInputvalidate.h"
using namespace std;
class clsCurrencyCalculatorScreen :protected clsScreen
{
	static void _PrintCard(clsCurrency Currency,string Massege)
	{
		cout <<Massege << endl << endl;
		cout << "-----------------------------" << endl;
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "-----------------------------" << endl<<endl;

	}
	static float _ReadAmount() {
		cout << "\nEnter Amount To Exchange : ";
		float NewRate = 0;
		NewRate = clsInputvalidate::readdoublenumber();
		return NewRate;
	}
	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCard(CurrencyFrom,"Currency From :");
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << Amount << CurrencyFrom.CurrencyCode() << " = " 
			<< AmountInUSD << " USD" << endl;
		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}
		cout << "Converting From USD " << endl;
		_PrintCard(CurrencyTo, "TO :");
			float AmountInC2 = CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);
		cout << Amount <<" " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInC2 << " " << CurrencyTo.CurrencyCode() << endl;
	}
	static clsCurrency _GetCurrency(string Massege)
	{
		string CurrencyCode;
		cout << Massege << endl;
		CurrencyCode = clsInputvalidate::readstring();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Is Not Found , Try Again  ";
			CurrencyCode = clsInputvalidate::readstring();

		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
	
		char ans = 'y';
		
		while (tolower(ans) == 'y')
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");
			
			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency1 Code  ");

			clsCurrency CurrencyTo= _GetCurrency("Please Enter Currency2 Code  ");
		
			float Amount = _ReadAmount();
			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);
			
			cout << endl<<endl<<"DO YOU WANT TO PERFORM ANOTHER CALCULATION y/n ?? ";
			cin >> ans;



		}

	}
};

