#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
    enum enCurrenciesMainMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrenciesMainMenueOption()
    {
        cout <<"\t" << "" << "Choose what do you want to do? [1 to 5]? "<< endl;
        short Choice = clsInputvalidate::readintnumber(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";

        system("pause>0");
        ShowCurrenciesMenue();
    }

    static void _ShowCurrenciesListScreen()
    {
        // cout << "\n Currencies List Screen will be here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        // cout << "\nFind Currency Screen will be here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        // cout << "\nUpdate Currency Rate Screen will be here.\n";
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        // cout << "\nCurrency Calculator Screen will be here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrenciesMainMenueOption(enCurrenciesMainMenueOptions CurrenciesMainMenueOption)
    {
        switch (CurrenciesMainMenueOption)
        {
        case clsCurrencyExchangeMainScreen::eListCurrencies:
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
            break;

        case clsCurrencyExchangeMainScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;

        case clsCurrencyExchangeMainScreen::eUpdateCurrencyRate:
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
            break;

        case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;

        case clsCurrencyExchangeMainScreen::eMainMenue:
            // Do Nothing here, the Main Screen will handle it :-)
            break;
        }
    }

public:

    static void ShowCurrenciesMenue()
    {
        system("cls");
        _DrawScreenHeader("   Currency Exchange Main Screen");

        cout << "\t" << "" << "===========================================\n";
        cout << "\t" << "" << "\t\tCurrency Exchange Menue\n";
        cout << "\t" << "" << "===========================================\n";
        cout << "\t" << "" << "\t[1] List Currencies.\n";
        cout << "\t" << "" << "\t[2] Find Currency.\n";
        cout << "\t" << "" << "\t[3] Update Rate.\n";
        cout << "\t" << "" << "\t[4] Currency Calculator.\n";
        cout << "\t" << "" << "\t[5] Main Menue.\n";
        cout << "\t" << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOption(enCurrenciesMainMenueOptions(_ReadCurrenciesMainMenueOption()));
    }
};