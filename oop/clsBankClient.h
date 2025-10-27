#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsInputvalidate.h"
#include "clsPerson.h"
#include "clsDate.h"
#include "clsUtil.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, Addnewmode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _markfordelete = false;



	void _AddDataLineToFile(string Line) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();

		}

	}
	void _Addnew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));

	}
	static clsBankClient _ConvertLinetoclientobject(string Line, string Seperator = "#//#")
	{


		vector<string> vClientData;

		vClientData = clsString::split(Line, Seperator);


		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2]
			, vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector <clsBankClient> _LoadClientsDatafromFile()
	{
		vector <clsBankClient> vclients;
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open())
		{
			string Line;
			while (getline(myfile, Line))
			{
				clsBankClient client = _ConvertLinetoclientobject(Line);
				vclients.push_back(client)
					;

			}
			myfile.close();
		}
		return vclients;
	}
	static string _ConverClientObjectToLine(clsBankClient& Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.PhoneNumber + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}
	vector <clsBankClient> _SaveclientsDataToFile(vector <clsBankClient> vclient)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient U : vclient)
			{
				if (U.MarkForDelete == false)
				{
					DataLine = _ConverClientObjectToLine(U);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

		return vclient;

	}
	void _Update()
	{
		vector <clsBankClient> _vclients;
		_vclients = _LoadClientsDatafromFile();
		for (clsBankClient& c : _vclients)
		{
			if (c.GetAccountNumber() == GetAccountNumber())
			{
				c = *this;
				break;
			}
		}
		_SaveclientsDataToFile(_vclients);
	}
	string _PrepareLogTransferRecord(double Amount, clsBankClient& Destenation, string UserName, string sep = "#//#")
	{
		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + sep;
		TransferRecord += GetAccountNumber() + sep;
		TransferRecord += Destenation.GetAccountNumber() + sep;
		TransferRecord += to_string(Amount) + sep;
		TransferRecord += to_string(AccountBalance) + sep;
		TransferRecord += to_string(Destenation.AccountBalance) + sep;
		TransferRecord += UserName;

		return TransferRecord;


	}
	void _TransferLog(double Amount, clsBankClient& Destenation, string UserName)
	{
		string stDateLine = _PrepareLogTransferRecord(Amount, Destenation, UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDateLine << endl;
			MyFile.close();
		}
	}

public:
	struct stTransferLog
	{
		string DateTime;
		string sAccountNumber;
		string dAccountNumber;
		float Amount;
		float sBalance;
		float dBalance;
		string UserName;

	};
	static stTransferLog _ConvertLogTransferLine(string Line, string sep = "#//#")
	{
		stTransferLog Record;
		vector <string> stLogTransfer = clsString::split(Line, sep);
		Record.DateTime = stLogTransfer[0];
		Record.sAccountNumber = stLogTransfer[1];
		Record.dAccountNumber = stLogTransfer[2];
		Record.Amount = stoi(stLogTransfer[3]);
		Record.sBalance = stoi(stLogTransfer[4]);
		Record.dBalance = stoi(stLogTransfer[5]);
		Record.UserName = stLogTransfer[6];


		return Record;




	}
	static vector <stTransferLog> GetLogTransferList()
	{
		vector <stTransferLog> vLogTransferRecords;
		fstream myfile;
		myfile.open("TransferLog.txt", ios::in);
		if (myfile.is_open())
		{
			string Line;
			stTransferLog LogTransferRecord;
			while (getline(myfile, Line))
			{
				LogTransferRecord = _ConvertLogTransferLine(Line);
				vLogTransferRecords.push_back(LogTransferRecord);
			}
			myfile.close();
		}
		return vLogTransferRecords;
	}
	static clsBankClient GetAddNewclientobject(string accountnumber)
	{

		return clsBankClient(enMode::Addnewmode, "", "", "", "", accountnumber, "", 0);
	};

	enum ensave { svFalidEmptyObjesct = 0, svSuccessed = 1, faliedaccountnumberexist = 2 };

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string PinCode)
	{

		_PinCode = PinCode;
	}
	string GetPinCode()

	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetMarkForDelete(bool markfordelete)
	{

		_markfordelete = markfordelete;
	}
	bool GetMarkfordelete()

	{
		return _markfordelete;
	}
	__declspec(property(get = GetMarkfordelete, put = SetMarkForDelete)) bool MarkForDelete;
	void SetAccountBalance(float AccountBalance)
	{

		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()

	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	ensave save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return ensave::svFalidEmptyObjesct;
		}
		case enMode::Addnewmode:
		{
			if (clsBankClient::IsClientExists(_AccountNumber))
				return ensave::faliedaccountnumberexist;
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
	void print()
	{
		cout << "Client Code  : " << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "FirstName  : " << FirstName << endl;
		cout << "LastName   : " << LastName << endl;
		cout << "FullName   : " << GetFullName() << endl;
		cout << "Email      : " << Email << endl;
		cout << "PhoneNumber: " << PhoneNumber << endl;
		cout << "AccountNumber: " << _AccountNumber << endl;
		cout << "PinCode: " << _PinCode << endl;
		cout << "AccountBalance: " << _AccountBalance << endl;
		cout << "------------------------------------" << endl << endl;

		cout << endl << endl;
	}
	void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputvalidate::readstring();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputvalidate::readstring();

		cout << "\nEnter Email: ";
		Client.Email = clsInputvalidate::readstring();

		cout << "\nEnter Phone: ";
		Client.PhoneNumber = clsInputvalidate::readstring();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputvalidate::readstring();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputvalidate::readdoublenumber();
	}
	bool Transfer(double Amount, clsBankClient& DestenationAccount, string UserName)
	{
		if (Amount > AccountBalance)
			return false;
		else
		{
			WithDraw(Amount);
			DestenationAccount.Deposit(Amount);
			_TransferLog(Amount, DestenationAccount, UserName);
			return true;
		}
	}
	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		save();
	}
	bool WithDraw(float Amount)
	{
		if (Amount > _AccountBalance)
			return false;
		else
		{
			_AccountBalance -= Amount;
			save();
			return true;

		}

	}
	static clsBankClient Find(string AccountNumber)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoclientobject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoclientobject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}
	static bool IsClientExists(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return(!Client1.IsEmpty());

	}
	void updateclient()
	{
		string AccountNumber = "";
		cout << "please enterclient account number";
		AccountNumber = clsInputvalidate::readstring();
		while (!clsBankClient::IsClientExists(AccountNumber))
		{
			cout << endl << "Account number is not found , chose another one";
			AccountNumber = clsInputvalidate::readstring();
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		client.print();
		cout << endl << "Update Client Info" << endl;
		cout << "-----------------------------------" << endl;

		ReadClientInfo(client);

		clsBankClient::ensave saveresult;
		saveresult = client.save();

		switch (saveresult)
		{
		case clsBankClient::ensave::svSuccessed:
		{
			cout << "Account Updated Successfuly" << endl;
			client.print();
			break;
		}
		case clsBankClient::ensave::svFalidEmptyObjesct:
		{
			cout << "  Error account was not saves cuz its empty" << endl;
			break;
		}

		}
	}
	void addnewclient()
	{
		string accountnumber = "";
		cout << "please enter your account number" << endl;
		accountnumber = clsInputvalidate::readstring();
		while (IsClientExists(accountnumber))
		{
			cout << "your account number is already used try again" << endl;

			accountnumber = clsInputvalidate::readstring();

		}
		clsBankClient newclient = clsBankClient::GetAddNewclientobject(accountnumber);
		ReadClientInfo(newclient);
		clsBankClient::ensave saveresult;
		saveresult = newclient.save();
		switch (saveresult)
		{
		case clsBankClient::ensave::svSuccessed:
		{
			cout << "client added successfuly " << endl;
			newclient.print();
			break;

		}

		case clsBankClient::ensave::svFalidEmptyObjesct:
		{
			cout << "error account was not saved cuz its empty " << endl;
			break;
		}
		}
	}
	bool Delete()
	{
		vector <clsBankClient> _vclients;
		_vclients = _LoadClientsDatafromFile();
		for (clsBankClient& c : _vclients)
		{
			if (c.GetAccountNumber() == _AccountNumber)
			{
				c._markfordelete = true;
				break;
			}
		}
		_SaveclientsDataToFile(_vclients);
		*this = _GetEmptyClientObject();
		return true;

	}
	void Deleteclient()
	{
		string accountnumber = "";
		cout << "please enter your account number" << endl;
		accountnumber = clsInputvalidate::readstring();
		while (!IsClientExists(accountnumber))
		{
			cout << "not found  try again" << endl;

			accountnumber = clsInputvalidate::readstring();

		}
		clsBankClient client1 = clsBankClient::Find(accountnumber);
		client1.print();
		cout << "are you sure yoy want delete it y/n ?" << endl;
		char ans = 'n';
		cin >> ans;
		if (tolower(ans) == 'y')
		{
			if (client1.Delete())
			{
				cout << "deleted successfuly" << endl;
				client1.print();
			}


			else
				cout << "error client was not deleted " << endl;
		}


	}
	static vector<clsBankClient> getclientlist()
	{
		return _LoadClientsDatafromFile();
	}
	void printclientrecordline(clsBankClient client)
	{
		cout << '|' << setw(16) << left << client.GetAccountNumber() <<
			'|' << setw(30) << left << client.GetFullName() <<
			'|' << setw(14) << left << client.PhoneNumber <<
			'|' << setw(30) << left << client.Email <<
			'|' << setw(10) << left << client.PinCode <<
			'|' << setw(10) << left << client.AccountBalance;
		cout << '\n';

	}
	void showclientlist()
	{
		vector <clsBankClient> vclient = getclientlist();
		cout << "\t\t\t\t\t\tClient list (" << vclient.size() << ") Clients(S).\t\t\t\t\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << '|' << setw(16) << left << "Account Number" <<
			'|' << setw(30) << left << "Client name" <<
			'|' << setw(14) << left << "Phone" <<
			'|' << setw(30) << left << "Email" <<
			'|' << setw(10) << left << "Pin code" <<
			'|' << setw(10) << left << "Balance";
		cout << '\n';
		cout << "------------------------------------------------------------------------------------------------------------------------\n";


		if (vclient.size() == 0)
			cout << "no available clients" << endl;
		else
		{

			for (clsBankClient& client : vclient)
			{
				printclientrecordline(client);
			}
		}

		cout << "------------------------------------------------------------------------------------------------------------------------\n";

	}
	static float GetTotalBalances()
	{
		double totalbalnces = 0;
		vector <clsBankClient> vclient = getclientlist();

		for (clsBankClient client : vclient)
		{
			totalbalnces += client.GetAccountBalance();

		}
		return totalbalnces;
	}
	void PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.GetFullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}
	void showtotalbanaces()
	{
		vector <clsBankClient> vclient = getclientlist();

		cout << "\t\t\t\t\t\tClient list (" << vclient.size() << ") Clients(S).\t\t\t\t\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";

		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		double totalbalances = GetTotalBalances();
		if (vclient.size() == 0)
			cout << "no clients available" << endl;
		else
		{
			for (clsBankClient& client : vclient)
			{
				PrintClientRecordBalanceLine(client);
				cout << endl;

			}
			cout << "\n_______________________________________________________";
			cout << "_________________________________________\n" << endl;
			cout << "\t\t\t\t\t   Total Balances = " << totalbalances << endl;
			cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(totalbalances) << ")";


		}
	}

};

