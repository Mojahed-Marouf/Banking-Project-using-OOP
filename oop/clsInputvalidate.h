#pragma once
#include <iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<cctype>
#include<fstream>
#include <iomanip>
#pragma warning (disable :4996)
#include <ctime>
#include "clsDate.h"
using namespace std;
class clsInputvalidate
{
public:
	static string readstring()
	{
		string st = "";
		getline(cin>>ws, st);
		return st;

	}
	static bool IsNumberBetween(int numbertocheck, int from, int to)
	{

		return(from <= numbertocheck && numbertocheck  <= to);

	}
	static bool IsNumberBetween(short numbertocheck, short from, short to)
	{

		return(from <= numbertocheck && numbertocheck <= to);

	}
	static bool IsNumberBetween(double numbertocheck, double from, double to)
	{

		return(from <= numbertocheck && numbertocheck <= to);

	}
	static bool IsNumberBetween(float numbertocheck, float from, float to)
	{

		return(from <= numbertocheck && numbertocheck <= to);

	}
	static bool IsDateBetween(clsDate Datetocheck, clsDate date1, clsDate date2)
	{
		if ((clsDate::IsDate1AfterDate2(Datetocheck, date1) || clsDate::isequaldates(Datetocheck, date1)) && (clsDate::IsDate1AfterDate2(date2, Datetocheck) || clsDate::isequaldates(Datetocheck, date2)))
			{ 
			return true;
		}
		
		if ((clsDate::IsDate1AfterDate2(Datetocheck, date2) || clsDate::isequaldates(Datetocheck, date2)) && (clsDate::IsDate1AfterDate2(date1, Datetocheck) || clsDate::isequaldates(Datetocheck, date1)))
		{
			return true;
		}
		else
			return false;
	}
	static int readintnumber(string massege="invalid number enter nuber again ")
	{
		int number  ;
		while (!(cin>>number))
		 {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massege;
			
		} 

		return number;
	}
	static int readintnumber(int from ,int to,string massege = "invalid number enter nuber again ")
	{
		cout << massege << endl;
		int number = readintnumber();
		while (!IsNumberBetween(number,from,to))
		{
			cout << massege;
			number = readintnumber();

		}

		return number;
	}
	static double readdoublenumber(string massege = "invalid number enter nuber again ")
	{
		double number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massege;

		}

		return number;
	}
	static int readdoublenumber(double from, double to, string massege = "invalid number enter nuber again ")
	{
		double number = readintnumber();
		while (!IsNumberBetween(number, from, to))
		{
			cout << massege;
			number = readintnumber();

		}

		return number;
	}
	static bool IsValideDate(clsDate Date)
	{
		return(clsDate::isvalidatedate(Date));
	}
};

