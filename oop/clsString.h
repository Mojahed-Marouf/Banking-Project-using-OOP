#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class clsString
{
private:

	string _Value;
	

public:

	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;
	
	
	
	
	static short length(string st)
	{
		
		return st.length();
	}
	short length()
	{
		return  length(_Value);
	}
	static char invertchar(char c)
	{
		if (isupper(c))
			return tolower(c);
		else
			return toupper(c);

	}
	char invertchar()
	{
		return invertchar(readcharacter());
	}
	static char readcharacter()
	{
		char c;
		cout << "please enter acharacter ? " << endl;
		cin >> c;
		return c;

	}
	static bool isvowel(char c)
	{

		char varr[5] = { 'a','e','i','o','u' };
		if (isupper(c))
			c = tolower(c);
		for (int i = 0;i < 5;i++)
		{
			if (c == varr[i])
				return 1;
		}
		return 0;
	}
	static string toupperst(string st)
	{


		cout << "upper conversion :" << endl;
		for (int i = 0;i < st.length();i++)
		{

			st[i] = toupper(st[i]);





		}
		return st;
	}
	void toupperst()
	{
		_Value= toupperst(_Value);
	}
	static string tolowerst(string st)
	{


		cout << "lower conversion :" << endl;
		for (int i = 0;i < st.length();i++)
		{

			st[i] = tolower(st[i]);

		}

		return st;
	}
	void tolowerst()
	{
		_Value= tolowerst(_Value);
	}
	static string invertstring(string st)

	{
		for (int i = 0;i < st.length();i++)
		{
			st[i] = invertchar(st[i]);
		}
		return st;
	}
	void invertstring()
	{
		_Value= invertstring(_Value);
	}
	static int countcaptial(string st)
	{
		int capitalcounter = 0;
		for (int i = 0;i < st.length();i++)
		{
			if (isupper(st[i]))
				capitalcounter++;

		}
		return capitalcounter;
	}
	static short countspecificleteer(string st, char letter,bool matchcase=true)
	{
		short counter = 0;
		if (matchcase)
		{
			for (int i = 0;i < st.length();i++)
			{
				if (st[i] == letter)
					counter++;
			}

		}
		else
		{
			for (int i = 0;i < st.length();i++)
			{
				if (tolower(st[i]) == tolower(letter))
					counter++;
			}
		}


		return counter;
	}
	short countspecificleteer(bool matchcase = true)
	{
		return   countspecificleteer(_Value, readcharacter(),matchcase);
	}
	int countcaptial()
	{
		return countcaptial(_Value);
	}
	static int countsmall(string st)
	{
		int smallcounter = 0;
		for (int i = 0;i < st.length();i++)
		{
			if (islower(st[i]))
				smallcounter++;

		}
		return smallcounter;
	}
	int countsmall()
	{
		return  countsmall(_Value);
	}
	static  short howmanyrepeated(string st, bool match = true)
	{
		char c = readcharacter();
		short rep = 0;
		for (int i = 0;i < st.length();i++)
		{
			if (match)
			{
				if ((st[i]) == c)
					rep++;
			}
			else
			{
				if (tolower(st[i]) == tolower(c))
					rep++;

			}
		}
		return rep;
	}
	short howmanyrepeated()
	{
		return   howmanyrepeated(_Value);
	}
	static int countvowels(string st)
	{
		short countvowels = 0;
		for (int i = 0;i < st.size();i++)
		{
			if (isvowel(st[i]))
				countvowels++;


		}
		return countvowels;
	}
	int countvowels()
	{
		return  countvowels(_Value);
	}
	 static void printvowels(string st)
	{
		short countvowels = 0;
		for (int i = 0;i < st.size();i++)
		{
			if (isvowel(st[i]))
				cout << st[i] << " ";


		}
		cout << endl;
	}
	 void printvowels()
	 {
		 printvowels(_Value);
	 }
	static void saperatedwords(string st)
	{
		string del = " ";
		short pos = 0;
		string newst;
		while ((pos = st.find(del)) != st.npos)
		{
			newst = st.substr(0, pos);
			if (newst != "")
				cout << newst << endl;
			st.erase(0, pos + del.length());


		}
		if (st != "")
			cout << st << endl;


	}
	void saperatedwords()
	{
		 saperatedwords(_Value);
	}
	static int countwords(string st)
	{
		short count = 0;
		string del = " ";
		short pos = 0;
		string newst;
		while ((pos = st.find(del)) != st.npos)
		{
			newst = st.substr(0, pos);
			if (newst != "")
				count++;
			st.erase(0, pos + del.length());


		}
		if (st != "")
			count++;


		return count;
	}
	int countwords()
	{
		return   countwords(_Value);
	}
	static  string readdelem()
	{
		string del = "";
		cout << "please enter del " << endl;
		cin >> del;
		return del;
	}
	static  vector<string> split(string st, string del)
	{
		
		vector <string> v_string;
		short pos = 0;
		string newst;
		while ((pos = st.find(del)) != st.npos)
		{
			newst = st.substr(0, pos);
				v_string.push_back(newst);


			st.erase(0, pos + del.length());


		}
		if (st != "")
			v_string.push_back(st);


		return v_string;
	}
	vector<string> split(string del)
	{
		return split(_Value,del);
	}
	static string trimleft(string st)
	{
		for (int i = 0;i < st.length();i++)
		{
			if (st[i] != ' ')
				return (st.substr(i, st.length() - 1));
		}
		return "";

	}
	string trimleft()
	{
		return  trimleft(_Value);
	}
	static string trimright(string st)
	{
		for (int i = st.length() - 1;i >= 0;i--)
		{
			if (st[i] != ' ')
				return (st.substr(0, i + 1));
		}
		return "";

	}
	string trimright()
	{
		return  trimright(_Value);
	}
	static string trim(string st)
	{
		return (trimleft(trimright(st)));
	}
	string trim()
	{
		return  trim(_Value);
	}
	static string joinstring(vector <string>& v_strings, string del)
	{
		string st = "";
		for (string& s : v_strings)
		{
			st = st + s + del;


		}
		return (st.substr(0, st.length() - del.length()));

	}
	static string joinstring(string array[], int size, string del)
	{
		string st = "";
		for (int i = 0;i < size;i++)
		{
			st = st + array[i] + del;
		}
		return (st.substr(0, st.length() - del.length()));
	}
static 	string replacewordwithsplit(string st, string repword, string oriword, bool matchcase = true)
	{
		vector <string> vst = split(st, " ");
		for (string& s : vst)
		{
			if (matchcase)
			{
				if (s == oriword)
					s = repword;
			}
			else
			{
				if (tolowerst(s) == tolowerst(oriword))
					s = repword;

			}
		}
		return joinstring(vst, "");
	}
string replacewordwithsplit(string repword, string oriword)
{
	return  replacewordwithsplit(_Value, repword, oriword);
}
static string removeallpunc(string st)
	{
		string newst = "";
		for (int i = 0;i < st.size();i++)
		{
			if (!iswpunct(st[i]))
				newst += st[i];

		}
		return newst;
	}
	string removeallpunc()
	{
		return removeallpunc(_Value);
	}



	









};

