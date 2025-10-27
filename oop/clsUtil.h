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
class clsUtil
{
public:
	enum enchar { smallletter = 1, capitalletter = 2, special = 3, digit = 4, mix = 5 };
	static void  Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}
	static int randomnumber(int from, int to)
	{
		int number = rand() % (to - from + 1) + from;
		return number;
	}
	static char GetRandomCharacter(enchar CharType)
	{

		//updated this method to accept mixchars
		if (CharType == mix)
		{
			//Capital/Samll/Digits only
			CharType = (enchar)randomnumber(1, 3);

		}
	}
	static char charactercheck(enchar ch)
	{


		switch (ch)
		{
		case enchar::smallletter:
		{
			return char(randomnumber(97, 122));
			break;
		}
		case enchar::capitalletter:
		{
			return char(randomnumber(65, 90));
			break;
		}
		case enchar::special:
		{
			return char(randomnumber(32, 47));
			break;
		}
		case enchar::digit:
		{
			return	 char(randomnumber(48, 57));
			break;
		}
		defult:
		{
			return	 char(randomnumber(65, 90));
			break;
		}

		}
	}
	static string getword(enchar ch, short length)
	{
		string word;
		for (int i = 1;i <= length;i++)
		{
			word += charactercheck(ch);
		}
		return word;
	}
	static string getkey(enchar chartype=capitalletter)
	{
		string key;
		key = getword(chartype, 4) + "-";
		key = key + getword(chartype, 4) + "-";
		key = key + getword(chartype, 4) + "-";
		key = key + getword(chartype, 4);
		return key;
	}
	static void getkeys(short nofkey)
	{

		for (int i = 1;nofkey >= i;i++)
		{
			cout << "KEY " << "[" << i << "]" << ":";
			cout << getkey() << endl;

		}


	};
	static void fillarraywithrandomnumbers(int& length, int  arrh[100],int from ,int to)
	{
		cout << "enter length of array" << endl;
		cin >> length;

		for (int i = 0;i < length;i++)
		{



			arrh[i] = randomnumber(from, to);

		}
		cout << endl;

	}
	static void fillarraywithrandomwords(int& length, string  arrh[100], enchar chartype)
	{
		cout << "enter length of array" << endl;
		cin >> length;

		for (int i = 0;i < length;i++)
		{



			arrh[i] = getword(chartype, length);

		}
		cout << endl;

	}
	static void swapping(int& number1, int& number2)
	{
		int t;
		t = number1;
		number1 = number2;
		number2 = t;
	}
	static void swapping(double& number1, double& number2)
	{
		double t;
		t = number1;
		number1 = number2;
		number2 = t;
	}
	static void swapping(bool& number1, bool& number2)
	{
		bool t;
		t = number1;
		number1 = number2;
		number2 = t;
	}
	static void swapping(string& number1, string& number2)
	{
		string t;
		t = number1;
		number1 = number2;
		number2 = t;
	}
	static void swapping(char& number1, char& number2)
	{
		char t;
		t = number1;
		number1 = number2;
		number2 = t;
	}
	static void swappingdates(clsDate& d1, clsDate& d2)
	{
		clsDate::swapdates(d1, d2);
		
	}
	static void shuffleArray(int arrh[100], int length)
	{


		for (int i = 0;i < length; i++)
		{
			swapping(arrh[randomnumber(0, length - 1)], arrh[randomnumber(0, length - 1)]);

		}
	}
	static float myabsvalue(int num)
	{
		if (num >= 0)
			return num;
		else
			return num * -1;

	}
	static float GetFractionPart(float Number)
	{
		return Number - int(Number);
	}
	void fillarraywithrandomkeys(int& length, string  arrh[100], enchar chartype)
	{
		cout << "enter length of array" << endl;
		cin >> length;

		for (int i = 0;i < length;i++)
		{



			arrh[i] = getkey(chartype);

		}
		cout << endl;

	}
	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}
	static string  EncryptText(string Text, short EncryptionKey=2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}
	static string  DecryptText(string Text, short EncryptionKey=2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}




	static void copyreversearray(int source[100], int destenation[100], int length)
	{

		for (int i = 0;i < length; i++)
		{


			destenation[i] = source[length - 1 - i];


		}


	}
	static void copyarray(int source[100], int destenation[100], int length)
	{
		for (int i = 0;i < length; i++)
		{
			destenation[i] = source[i];

		}

	}
	static int printsumnumbersinarray(int arrh[100], int length)
	{

		int sum = 0;

		for (int i = 0;i < length; i++)
		{
			sum += arrh[i];

		}
		return sum;
	}
	static float printavg(int arrh[100], int length)
	{
		cout << "the avg of the numbers in the array is = ";

		return (float)printsumnumbersinarray(arrh, length) / length;
	}
	static int printminnumberinarray(int arrh[100], int length)
	{
		cout << "the min number in the array is = " << endl;
		int minnumber = 0;
		minnumber = arrh[0];
		for (int i = 0;i < length; i++)
		{
			if (arrh[i] < minnumber)
				minnumber = arrh[i];

		}
		return minnumber;
	}
	static int printmaxnumberinarray(int arrh[100], int length)
	{
		cout << "the max number of the array is = " << endl;
		int maxnumber = 0;
		for (int i = 0;i < length; i++)
		{
			if (arrh[i] > maxnumber)
				maxnumber = arrh[i];

		}
		return maxnumber;
	}
	static void checkifreapeted(int num, int arr[100], int length)
	{
		int c = 0;
		for (int i = 0;i < length; i++)
		{
			if (arr[i] == num)
				c++;
		}
		cout << num << "is repeted" << c << "time(s)" << endl;
	}
	enum enprimenotprime { prime = 1, notprime = 2 };
	static enprimenotprime checkifprimeornot(int number)
	{


		for (int i = 2;number > i;i++)
		{
			if (number % i == 0)
				return enprimenotprime::notprime;


		}
		return enprimenotprime::prime;

	}
	static void copyprimearray(int source[100], int destenation[100], int length1, int& length2)
	{
		int c = 0;
		for (int i = 0;i < length1; i++)
		{
			if (checkifprimeornot(source[i]) == enprimenotprime::prime)
			{
				destenation[c] = source[i];
				c++;
			}


		}
		length2 = c;
	}
	static void sumarraies(int arr1[100], int arr2[100], int length, int destenation[100])
	{
		cout << "the sum of arr1 & arr2 is = " << endl;
		for (int i = 0;i < length; i++)
		{
			destenation[i] = arr1[i] + arr2[i];

		}

	}
	static void addarrayelement(int arr[100], int& length, int   number)
	{
		length = length + 1;
		arr[length - 1] = number;

	}
	static int findnumberpositioninarray(int arr[100], int length, int num)
	{


		for (int i = 0;i < length; i++)
		{
			if (arr[i] == num)
				return i;


		}
		return -1;
	}
	static bool checkifnumberinarray(int arr[100], int length, int num)
	{


		return  findnumberpositioninarray(arr, length, num);
	}
	static void fillarraywithrandomelements(int& length, int  arrh[100])
	{
		cout << "enter length of array" << endl;
		cin >> length;

		for (int i = 0;i < length;i++)
		{



			arrh[i] = randomnumber(1, 100);

		}
		cout << endl;

	}
	static void printarray(int arrh[100], int length)
	{

		for (int i = 0;i < length; i++)
		{
			cout << arrh[i] << "  ";
		}
		cout << endl;

	}   
	static void copyprimenumbersarraybyaddingelements(int source[100], int destenation[100], int& length, int length1)
	{
		for (int i = 0;i < length1; i++)
		{
			if (checkifprimeornot(source[i]) == prime)
				addarrayelement(destenation, length, source[i]);


		}

	}
	static void copydistinctnumbertoarray(int source[100], int destenation[100], int& length, int length1)
	{

		for (int i = 0;i < length1; i++)
		{
			if (!checkifnumberinarray(destenation, length1, source[i]))
				addarrayelement(destenation, length, source[i]);

		}

	}
	static bool ispolindromarray(int length, int  arrh[100])
	{
		for (int i = 0;i < length;i++)
		{
			if (arrh[i] != arrh[length - 1 - i])
				return 0;
		}
		return 1;
	}
	static int oddcountinarray(int arrh[100], int length)
	{
		int oddcounter = 0;
		for (int i = 0;i < length; i++)
		{
			if (arrh[i] % 2 != 0)
				oddcounter++;
		}
		return oddcounter;
	}
	static int Evencountinarray(int arrh[100], int length)
	{
		int evencounter = 0;
		for (int i = 0;i < length; i++)
		{
			if (arrh[i] % 2 == 0)
				evencounter++;
		}
		return evencounter;
	}
	static int positivecountinarray(int arrh[100], int length)
	{
		int positivecounter = 0;
		for (int i = 0;i < length; i++)
		{
			if (arrh[i] >= 0)
				positivecounter++;
		}
		return positivecounter;
	}
	static int negativecountinarray(int arrh[100], int length)
	{
		int negativecounter = 0;
		for (int i = 0;i < length; i++)
		{
			if (arrh[i] < 0)
				negativecounter++;
		}
		return negativecounter;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}




};
