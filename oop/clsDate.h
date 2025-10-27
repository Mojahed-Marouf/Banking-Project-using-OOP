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
#include "clsString.h"
using namespace std;
class clsDate
{
private:
	int Year=1900;
	int Month=1;
	int Day=1;
	

public:


clsDate dateofdays(int numberofdays, short year)
	{
	clsDate D;
		int monthdays = 0;
		int rem = numberofdays;
		D.Year = year;
		D.Month = 1;
		while (true)
		{
			monthdays = nofdays(D.Month, D.Year);


			if (rem > monthdays)
			{
				rem -= monthdays;
				D.Month++;
			}
			else
			{
				D.Day = rem;
				break;
			}

		}
		return D;
	};
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
	}
	clsDate(string st)
	{
		vector <string> v_date;
		v_date = clsString::split(st, "/");
		Day = stoi(v_date[0]);
		Month = stoi(v_date[1]);
		Year = stoi(v_date[2]);
	}
	clsDate(int day,int month ,int year )
	{
		Day = day;
		Month = month;
		Year = year;
	
	}
	clsDate(int numberofdaysuntillnow, int year)
	{
		clsDate Date1=dateofdays(numberofdaysuntillnow, year);
		Day = Date1.Day;
		Month = Date1.Month;
		Year = Date1.Year;
	}
	static clsDate getsystemdate()
	{
		

		time_t t = time(0);
		tm* now = localtime(&t);
		int day, month, year;
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day,month,year);

	}
	void Setday(int day)
	{
		Day = day;
	}
	int Getday()
	{
		return Day;
	}
	void Setmonth(int month)
	{
		Month = month;
	}
	int Getmonth()
	{
		return Month;
	}
	void Setyear(int year)
	{
		Year = year;
	}
	int Getyear()
	{
		return Year;
	}
	__declspec(property(get = Getyear, put = Setyear)) string Year;
	__declspec(property(get = Getmonth, put = Setmonth)) string Month;
	__declspec(property(get = Getday, put = Setday)) string Day;
static string datetostring(clsDate date)
	{
		return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);


	}
static string GetSystemDateTimeString()
{
	//system datetime string
	time_t t = time(0);
	tm* now = localtime(&t);

	short Day, Month, Year, Hour, Minute, Second;

	Year = now->tm_year + 1900;
	Month = now->tm_mon + 1;
	Day = now->tm_mday;
	Hour = now->tm_hour;
	Minute = now->tm_min;
	Second = now->tm_sec;

	return (to_string(Day) + "/" + to_string(Month) + "/"
		+ to_string(Year) + " - "
		+ to_string(Hour) + ":" + to_string(Minute)
		+ ":" + to_string(Second));

}

string datetostring()
	{
		return  datetostring(*this);
	}
static bool isaleapyear(int number)
	{
		return ((number % 400 == 0) || (number % 4 == 0 && number % 100 != 0));

	}
bool isaleapyear()
	{
		return  isaleapyear(Year);
	}
static int numberofdays(int year)
	{
		return isaleapyear(year) ? 366 : 365;
	}
int numberofdays()
	{
		return  numberofdays(Year);
	}
static int numberofhours(int year)
	{
		return  numberofdays(year) * 24;

	}
int numberofhours()
	{
		return numberofhours(Year);
	}
static int numberofminuties(int year)
	{
		return  numberofhours(year) * 60;

	}
int numberofminuties()
	{
		return   numberofminuties(Year);
	}
static int numberofseconds(int year)
	{
		return  numberofminuties(year) * 60;

	}
int numberofseconds()
	{
		return numberofseconds(Year);
	}
static int nofdays(int month, int year)
	{
		if (month > 12 || month < 1)
			return 0;

		if (month == 2)
			return isaleapyear(year) ? 29 : 28;

		short arr31days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 1;i <= 12;i++)
		{
			if (arr31days[i - 1] == month)
				return 31;
		}
		return 30;
	}
int nofdays()
	{
		return  nofdays(Month, Year);
	}
static int nofhours(int month, int year)
	{
		return  nofdays(month, year) * 24;

	}
int nofhours()
	{
		return  nofhours(Month, Year);
	}
static int nofminuties(int month, int year)
	{
		return  nofhours(month, year) * 60;

	}
int nofminuties()
	{
		return   nofminuties(Month, Year);
	}
static int nofseconds(int month, int year)
	{
		return  nofminuties(month, year) * 60;

	}
int nofseconds()
	{
		return nofseconds(Month, Year);
	}
static bool isvalidatedate(clsDate date)
	{
		if ((date.Month > 12) || (date.Month < 1) || (date.Day < 1) || (date.Day > 31))
			return false;

		if (date.Day > nofdays(date.Month, date.Year))
			return false;
		else
			return true;

	}
bool isvalidatedate()
	{
		return  isvalidatedate(*this);
	}
static void printdate(clsDate D)
	{
		cout << datetostring(D) << endl;;

	}
void printdate()
	{
		cout << datetostring() << endl;
	}
static short dayorder(short year, short month, short day)
	{
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
short dayorder()
	{
		return dayorder(Year, Month, Day);
	}
static string dayname(short dayorder)
	{
		string daysnames[7] = { "sun","mon","tue","wed","thu","fri","sut" };
		return daysnames[dayorder];
	}
static string monthname(short month)
	{
		string arrmonths[12] = { "jan","feb","mar","apr","may","june","july","aug","sep","oct","nov","dec" };
		return arrmonths[month - 1];
	}
string monthname()
	{
		return monthname(Month);
	}
static void printmonthcelender(short year, short  month)
	{
		int current = dayorder(year, month, 1);
		int numberofdays;
		numberofdays = nofdays(month, year);

		printf("--------------------------%s------------------------ \n\n",
			monthname(month).c_str());

		cout << "  sun  mon  tue  wed  thu  fri  sut  " << endl;
		int i;
		for (i = 0;i < current;i++)
			printf("     ");
		for (int j = 1;j <= numberofdays;j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				cout << endl;
			}

		}
		cout << endl;
		printf("------------------------------------------------------\n\n");

	}
void printmonthcelender()
	{
		printmonthcelender(Year, Month);
	}
static void printyearcelender(short year)
	{
		cout << "---------------------------------------------------" << endl;
		cout << "      Celender -  " << year << endl;
		cout << "---------------------------------------------------" << endl;
		for (int i = 1;i <= 12;i++)
		{
			printmonthcelender(year, i);

		}

	}
void printyearcelender()
	{
		return printyearcelender(Year);
	}
static int numberofdaysfrombeginingofyear(short day, short month, short year)
	{
		int totaldays = 0;
		for (int i = 1;i < month;i++)
		{
			totaldays += nofdays(i, year);


		}
		totaldays += day;

		return totaldays;
	}
int numberofdaysfrombeginingofyear()
	{
		return  numberofdaysfrombeginingofyear(Day, Month, Year);
	}
static void dateafteradd(clsDate D, int daystoadd)
	{
		
		short remainingdays = daystoadd + numberofdaysfrombeginingofyear(D.Day, D.Month,D.Year);
		short monthdays = 0;
		D.Month = 1;
		while (true)
		{
			monthdays = nofdays(D.Month,D.Year);
			if (remainingdays > monthdays)
			{
				remainingdays -= monthdays;
				D.Month++;
				if (D.Month > 12)
				{
					D.Month = 1;
					D.Year++;
				}


			}
			else
			{
				D.Day= remainingdays;
				break;
			}


		}

		
	}
void dateafteradd(int daystoadd)
	{
		return dateafteradd(*this, daystoadd);
	}
static bool islesscomparedates(clsDate date1, clsDate date2)
	{
		if (date1.Year < date2.Year)
		{
			return true;


		}
		else if (date1.Year == date2.Year)
		{
			if (date1.Month < date2.Month)
			{
				return true;

			}
			else if (date1.Month == date2.Month)
			{
				if (date1.Day < date2.Day)
				{
					return true;
				}
				else if (date1.Day > date2.Day)
				{
					return false;
				}
				return false;
			}
			else
				return false;
		}
		else
			return false;


	}
bool islesscomparedates(clsDate date2)
	{
		return  islesscomparedates(*this, date2);
	}
static bool isequaldates(clsDate date1, clsDate date2)
	{
		return (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? true : false) : false) : false;
	}
bool isequaldates(clsDate date2)
	{
		return  isequaldates(*this, date2);
	}
static bool islastdayinthemonth(clsDate D)
	{
		return(nofdays(D.Month, D.Year) == D.Day);

	}
bool islastdayinthemonth()
	{
		return   islastdayinthemonth(*this);
	}
static bool islastmonthintheyear(clsDate D )
	{
		return(12 == D.Month);

	}
bool islastmonthintheyear()
	{
		return  islastmonthintheyear(*this);
	}
static clsDate increasedatebyonedy(clsDate date)
	{
		if (islastdayinthemonth(date))
		{
			date.Day = 1;
			if (islastmonthintheyear(date))
			{
				date.Month = 1;
				date.Year++;

			}
			else
			{
				date.Month++;
			}
		}
		else
			date.Day++;


		return date;
	}
clsDate increasedatebyonedy()
	{

		return  increasedatebyonedy(*this);
	}
static void swapdates(clsDate& date1, clsDate& date2)
	{
		clsDate tem;

		tem = date1;
		date1 = date2;
		date2 = tem;


	}
static int calcyourageindays(clsDate dateofbirth)
{
	return defferencedtes(dateofbirth, getsystemdate());

}
static clsDate increasedatebyxdays(clsDate & date, short c)
{
	for (int i = 1;i <= c;i++)
	{

		date = increasedatebyonedy(date);
	}
	return date;

}
clsDate increasedatebyxdays(short c)
{
	return  increasedatebyxdays(*this, c);
}
static clsDate increasedatebyoneweek(clsDate &date)
{
	for (int i = 1;i <= 7;i++)
	{

		date = increasedatebyonedy(date);
	}
	return date;

}
void increasedatebyoneweek()
{

	increasedatebyoneweek(*this);
}
static clsDate increasedatebyxweeks(clsDate& date, short c)
{

	for (int i = 1;i <= c;i++)
	{

		date = increasedatebyoneweek(date);
	}
	return date;

}
 clsDate increasedatebyxweeks(short c)
{
	return  increasedatebyxdays(*this, c);
}
static clsDate increasedatebyonemonth(clsDate& date)
{
	if (islastmonthintheyear(date))
	{
		date.Month = 1;
		date.Year++;

	}
	else
	{
		date.Month++;
	}
	short numberofdaysincurrentmonth = nofdays(date.Month, date.Year);
	if (date.Day > numberofdaysincurrentmonth)
	{
		date.Day = numberofdaysincurrentmonth;
	}

	return date;

}
void increasedatebyonemonth()
{
	increasedatebyonemonth(*this);
}
static clsDate increasedatebyxmonths(clsDate& date, short c)
{
	for (int i = 1;i <= c;i++)
	{

		date = increasedatebyonemonth(date);
	}
	return date;

}
void increasedatebyxmonths( short c)
 {
	 increasedatebyxmonths(*this, c);
 }
static clsDate increasedatebyoneyear(clsDate& date)
{
	date.Year++;
	return date;


}
void increasedatebyoneyear()
{
	  increasedatebyoneyear(*this);
}
static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
{
	return (!islesscomparedates(Date1, Date2) && !isequaldates(Date1, Date2));

}
bool IsDateAfterDate2(clsDate Date2)
{
	return IsDate1AfterDate2(*this, Date2);
}
static clsDate increasedatebyxyears(clsDate date, int c)
{
	for (int i = 1;i <= c;i++)
	{

		date = increasedatebyoneyear(date);
	}
	return date;

}
void increasedatebyxyears(int c)
{

	 increasedatebyxyears(*this, c);
}
static clsDate increasedatebyxyearsfaster(clsDate& date, int c)
{
	date.Year += c;
	return date;


}
void increasedatebyxyearsfaster(int c)
{

	  increasedatebyxyearsfaster(*this, c);
}
static clsDate increasedatebyonedeacade(clsDate& date)
{
	date.Year += 10;
	return date;

}
void increasedatebyonedeacade()
{

	   increasedatebyonedeacade(*this);
}
static clsDate increasedatebyxdeacades(clsDate& date, int c)
{
	for (int i = 1;i <= c;i++)
	{
		date = increasedatebyonedeacade(date);
	}
	return date;

}
void increasedatebyxdeacades(int c)
{

	 increasedatebyxdeacades(*this, c);
}
static  clsDate increasedatebyxdeacadesfaster(clsDate& date, int c)
{

	date.Year += 10 * c;
	return date;

}
static clsDate increasedatebyonecentury(clsDate& date)
{

	date.Year += 100;
	return date;

}
void increasedatebyonecentury()
{

	increasedatebyonecentury(*this);
}
static clsDate increasedatebyonemillinuim(clsDate& date)
{
	date.Year += 1000;
	return date;

}
void increasedatebyonemillinuim()
{
	increasedatebyonemillinuim(*this);

}
static clsDate decdatebyoneday(clsDate& date)
{
	if (date.Day == 1)
	{
		if (date.Month = 1)
		{
			date.Day = 31;
			date.Month = 12;
			date.Year--;
		}
		else
		{
			date.Month--;
			date.Day = nofdays(date.Month, date.Year);
		}


	}
	else
	{
		date.Day--;
	}

	return date;

}
void decdatebyoneday()
{

	decdatebyoneday(*this);
}
static clsDate decdatebyxdays(clsDate& date, int c)
{
	for (int i = 1;i <= c;i++)
	{
		date = decdatebyoneday(date);
	}

	return date;

}
void decdatebyxdays(int c)
{
	decdatebyxdays(*this, c);

}
static clsDate  decdatebyoneweek(clsDate& date)
{
	for (int i = 1;i <= 7;i++)
	{
		date = decdatebyoneday(date);
	}

	return date;

}
void  decdatebyoneweek( )
{
	decdatebyoneweek(*this);
}
static clsDate decdatebyxweeks(clsDate& date, int c)
{
	for (int i = 1;i <= c;i++)
	{
		date = decdatebyoneweek(date);
	}

	return date;

}
void decdatebyxweeks(int c)
{
	decdatebyxweeks(*this, c);

 }
static clsDate decdatebyonemonth(clsDate &date)
{

	if (date.Month == 1)
	{
		date.Month = 12;
		date.Year--;
	}
	else
	{
		date.Month -= 1;
	}
	short numberofdaysincurrentmonth = nofdays(date.Month, date.Year);
	if (date.Day > numberofdaysincurrentmonth)
	{
		date.Day = numberofdaysincurrentmonth;
	}


	return date;

}
void decdatebyonemonth( )
{
	decdatebyonemonth(*this);
}
static clsDate decdatebyxmonths(clsDate& date, int c)
{
	for (int i = 1;i <= c;i++)
	{
		date = decdatebyonemonth(date);
	}

	return date;

}
void  decdatebyxmonths(int c)
{
	decdatebyxmonths(*this, c);
}
static clsDate decdatebyoneyear(clsDate& date)
{
	date.Year -= 1;

	return date;

}
void  decdatebyoneyear( )
{
	decdatebyoneyear(*this);
}
static clsDate decdatebyxyears(clsDate& date, int c)
{
	for (int i = 1;i <= c;i++)
	{
		date = decdatebyoneyear(date);
	}

	return date;

}
void decdatebyxyears(int c)
{
	decdatebyxyears(*this, c);
}
static clsDate decdatebyxyearsfaster(clsDate& date, int c)
{
	date.Year -= c;


	return date;

}
void decdatebyxyearsfaster(int c)
{
	decdatebyxyearsfaster(*this, c);
}
static clsDate decdatebyonedecade(clsDate& date)
{

	date.Year -= 10;

	return date;
}
void decdatebyonedecade()
{
	decdatebyonedecade(*this);
}
static clsDate decdatebyxdecades(clsDate& date, int c)
{
	for (int i = 1;i <= c;i++)
	{
		date = decdatebyonedecade(date);
	}

	return date;

}
void decdatebyxdecades(int c)
{
	decdatebyxdecades(*this, c);
}
static clsDate decdatebyxdecadesfaster(clsDate& date, int c)
{

	date.Year -= 10 * c;


	return date;

}
void  decdatebyxdecadesfaster(int c) {
	decdatebyxdecadesfaster(*this, c);
}
static clsDate decdatebyonecentury(clsDate& date)
{

	date.Year -= 100;

	return date;
}
void decdatebyonecentury()
{
	decdatebyonecentury(*this);
}
static clsDate decdatebyonemillinuim(clsDate & date)
{

	date.Year -= 1000;

	return date;
}
void   decdatebyonemillinuim()
{
	decdatebyonemillinuim(*this);
}
static short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder()
{
	return DayOfWeekOrder(Day, Month, Year);
}
static bool IsWeekEnd(clsDate Date)
{
	
	short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	return  (DayIndex == 5 || DayIndex == 6);
}
bool IsWeekEnd()
{
	return  IsWeekEnd(*this);
}
static bool isbussday(clsDate date)
{
	return !IsWeekEnd(date);

}
bool isbussday()
{
	return isbussday(*this);
}
static short DaysUntilTheEndOfWeek(clsDate Date)
{
	return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
short DaysUntilTheEndOfWeek()
{
	return  DaysUntilTheEndOfWeek(*this);
}
static int defferencedtes(clsDate date1, clsDate date2, bool included = false)
{
	clsDate tem;
	int flagmin = 1;
	int numberofdefferencedays = 0;
	if (!islesscomparedates(date1, date2))
	{
		swapdates(date1, date2);
		flagmin = -1;
	}
	while (islesscomparedates(date1, date2))
	{
		numberofdefferencedays++;
		date1 = increasedatebyonedy(date1);

	}

	return (included) ? ++numberofdefferencedays * flagmin : numberofdefferencedays * flagmin;



	return numberofdefferencedays;

}
int defferencedtes(clsDate date2, bool included = false)
{
	return  defferencedtes(*this, date2);
}
static short daysuntillendofmonth(clsDate date)
{
	clsDate endofmonthdate;
	endofmonthdate.Day = nofdays(date.Month, date.Year);
	endofmonthdate.Month = date.Month;
	endofmonthdate.Year = date.Year;

	return (defferencedtes(date, endofmonthdate, true));

}
short daysuntillendofmonth()
{
	return  daysuntillendofmonth(*this);
}
static short numberofdaysinyear(clsDate date)
{
	short n = 0;
	for (int i = 1;i <= 12;i++)
	{
		n += nofdays(i, date.Year);
	}
	return n;
}
short numberofdaysinyear()
{
	return  numberofdaysinyear(*this);
}
static short daysuntillendofyear(clsDate date)
{

	clsDate endofyeardate;
	endofyeardate.Day = 31;
	endofyeardate.Month = 12;
	endofyeardate.Year = date.Year;

	return (defferencedtes(date, endofyeardate, true));
}
short daysuntillendofyear()
{
	return   daysuntillendofyear(*this);
}

};

