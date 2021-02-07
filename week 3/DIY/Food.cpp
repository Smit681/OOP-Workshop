#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Food.h"
#include "cstring.h"
using namespace std;

namespace sdds {

	void Food::setname(const char* name)
	{
		strnCpy(f_name, name, 30);
	}

	void Food::setEmpty()
	{
		f_name[0] = '\0';
		f_calorie = 0;
		f_code = -1;
	}

	bool Food::isValid() const 
	{
		bool valid = true;
		if (f_name[0] == '\0' || f_calorie == 0 || f_code == -1) valid = false;
		return valid;
	}

	bool Food::isValid(const char* name) const
	{
		bool valid = true;
		if (!name) valid = false;
		return valid;
	}

	bool Food::isValid(const int calorie, const int code) const
	{
		bool valid = true;
		if (calorie <= 0 || calorie > 3000 || code < 1 || code > 4) valid = false;
		return valid;
	}

	void Food::set(const char* name, const int calorie, const int code)
	{
		bool valid = true;
		valid = isValid(name) && isValid(calorie,code);
		if (valid)
		{
			Food::setname(name);
			f_calorie = calorie;
			f_code = code;
		}
	}

	int Food::getcalorie() const
	{
		return f_calorie;
	}

	void Food::codeTostr(int code) const
	{
		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(10);
		cout.fill(' ');
		switch (code)
		{
			
		case 1:
			cout << "Breakfast";
			break;
		case 2:
			cout << "Lunch";
			break;
		case 3:
			cout << "Dinner";
			break;
		case 4:
			cout << "Snack";
			break;
			
		default:
			cout << "code is not correct" << endl;
			break;
		}
		cout.unsetf(ios::left);
		cout.unsetf(ios::fixed);
	}

	void Food::display() const
	{
		if (isValid())
		{

			cout << "| ";
			cout.setf(ios::fixed);
			cout.setf(ios::left);
			cout.width(30);
			cout.fill('.');
			cout << f_name;
			cout.unsetf(ios::left);
			cout.unsetf(ios::fixed);
			cout << " | ";
			cout.setf(ios::fixed);
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(4);	
			cout << f_calorie;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			cout << " | ";
			codeTostr(f_code);
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}