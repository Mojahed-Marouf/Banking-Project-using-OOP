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
using namespace std;


class clsPerson
{

    string _FirstName;
    string _LastName;
    string _PhoneNumber;
    string _Email;

public:
    clsPerson(string FirstName, string LastName, string PhoneNumber, string Email)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _PhoneNumber = PhoneNumber;
        _Email = Email;

    }
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    string GetEmail()
    {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    void SetPhone(string Phone)
    {
        _PhoneNumber = Phone;
    }

    string GetPhone()
    {
        return _PhoneNumber;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string PhoneNumber;



    string GetFullName()
    {
        return _FirstName + " " + _LastName;
    }


};


