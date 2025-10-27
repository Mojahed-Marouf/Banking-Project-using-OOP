#pragma once
#include <iostream>
#include "clsString.h"
#include "Global.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
using namespace std;
class clsUser :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _Markedfordelete = false;
	 string _PrepareLogRecord(string sep="#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + sep;
		LoginRecord += UserName+ sep;
		LoginRecord += clsUtil::EncryptText(Password) + sep;
		LoginRecord += to_string(Permissions);
		return LoginRecord;


	}
	static clsUser _ConvertLinetouserobject(string Line, string Seperator = "#//#")
	{


		vector<string> vuser;

		vuser = clsString::split(Line, Seperator);


		return clsUser(enMode::UpdateMode, vuser[0], vuser[1], vuser[2]
			, vuser[3], vuser[4], clsUtil::DecryptText(vuser[5]), stoi(vuser[6]));

	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector <clsUser> _LoadUsersDatafromFile()
	{
		vector <clsUser> vusers;
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string Line;
			while (getline(myfile, Line))
			{
				clsUser User = _ConvertLinetouserobject(Line);
				vusers.push_back(User)
					;

			}
			myfile.close();
		}
		return vusers;
	}
	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.PhoneNumber + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtil::EncryptText(User.Password )+ Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;

	}
	void _AddDataLineToFile(string Line) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();

		}

	}
	void _Update()
	{
		vector <clsUser> _vusers;
		_vusers = _LoadUsersDatafromFile();
		for (clsUser& c : _vusers)
		{
			if (c.GetUserName() == GetUserName())
			{
				c = *this;
				break;
			}
		}
		_SaveusersDataToFile(_vusers);
	}
	
	vector <clsUser> _SaveusersDataToFile(vector <clsUser> vuser)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser U : vuser)
			{
				if (U.MarkForDeleted() == false)
				{
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

		return vuser;

	}
	void _Addnew()
	{
		_AddDataLineToFile(_ConverUserObjectToLine(*this));

	}


public:
	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};
	enum enpermissions{eAll=-1,pListClients=1,pAddNewClient=2,pDeleteClient=4,pUpdateClient=8,
		pFindClient=16,pTransactios=32,pManageUsers=64,pLogRegister=128};
	clsUser (enMode Mode,string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	bool MarkForDeleted()
	{
		return _Markedfordelete ;
	}
	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName( string UserName)
	{

		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{

		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	int GetPermissions()
	{
		return _Permissions;
	}
	void SetPermissions(int Permissions)
	{

		_Permissions = Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLinetouserobject(Line);
				if (Client.GetUserName() == UserName)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Password)
	{


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetouserobject(Line);
				if (User.GetUserName() == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}
	bool Delete()
	{
		vector <clsUser> _vusers;
		_vusers = _LoadUsersDatafromFile();
		for (clsUser& c : _vusers)
		{
			if (c.GetUserName() == _UserName)
			{
				c._Markedfordelete = true;
				break;
			}
		}
		_SaveusersDataToFile(_vusers);
		*this = _GetEmptyUserObject();
		return true;

	}
	enum ensave { svFalidEmptyObjesct = 0, svSuccessed = 1, faliedaccountnumberexist = 2 };
	static bool IsUsertExists(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return(!User.IsEmpty());

	}
	ensave save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return ensave::svFalidEmptyObjesct;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUsertExists(_UserName))
				return ensave::svFalidEmptyObjesct;
			else
			{
				_Addnew();
				_Mode = enMode::UpdateMode;
				return ensave::svSuccessed;
			}
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return ensave::svSuccessed;
			break;
		}
		}
	}
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDatafromFile();
	}	
	 bool CheckAccessPermissions(enpermissions Permission)
	{
		if (this->Permissions == enpermissions::eAll)
			return true;
		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}
	 void RegisterLogIn()
	 {
		 string stDateLine=_PrepareLogRecord();
		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << stDateLine << endl;
			 MyFile.close();
		 }
	}
	 static stLoginRegisterRecord _ConvertLoginRegisterLine(string Line,string sep="#//#")
	 {
		 stLoginRegisterRecord LoginRegisterRecord;
		 vector <string> LoginRegisterDataLine = clsString::split(Line, sep);
		 LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		 LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		 LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		 LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);


		 return LoginRegisterRecord;

	 }
	 static vector <stLoginRegisterRecord> GetLoginRegisterList()
	 {
		 vector <stLoginRegisterRecord> vLoginRegisterRecords;
		 fstream myfile;
		 myfile.open("LoginRegister.txt", ios::in);
		 if (myfile.is_open())
		 {
			 string Line;
			 stLoginRegisterRecord LoginRegisterRecord;
			 while (getline(myfile, Line))
			 {
				LoginRegisterRecord = _ConvertLoginRegisterLine(Line);
				 vLoginRegisterRecords.push_back(LoginRegisterRecord);
			 }
			 myfile.close();
		 }
		 return vLoginRegisterRecords;
	 }
	 
};

