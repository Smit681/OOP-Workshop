#include <iostream>
#include "CalorieList.h"
using namespace std;

namespace sdds{

	void CalorieList::setEmpty()
	{
		c_addedItem = 0;
		c_noOfItem = 0;
	}

	bool CalorieList::isValid() const
	{
		bool valid = true;
		if (!fooditems) valid = false;
		else {
			for (int i = 0; valid && i < c_noOfItem; i++)
			{
				valid = fooditems[i].isValid();
			}
		}
		return valid;
	}

	int CalorieList::TotalCalorie() const
	{
		int calorie = 0;
		for (int i = 0; i < c_noOfItem; i++)
		{
			calorie += fooditems[i].getcalorie();
		}
		return calorie;
	}

	void CalorieList::Tital() const
	{
		cout << "+----------------------------------------------------+" << endl;;
		if (CalorieList::isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer() const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (CalorieList::isValid())
		{
			cout << "|    Total Calories for today:";
			cout.setf(ios::fixed);
			cout.setf(ios::right);
			cout.width(9);
			cout << CalorieList::TotalCalorie();
			cout.unsetf(ios::fixed);
			cout.unsetf(ios::right);
			cout << " |            |" << endl;
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}
		
	void CalorieList::display() const
	{
		CalorieList::Tital();
		for (int i = 0; i < c_noOfItem; i++)
		{
			fooditems[i].display();
		}
		CalorieList::footer();
	}

	void CalorieList::init(int noOfitem)
	{
		if (noOfitem <= 0)  setEmpty();
		else {
			c_addedItem = 0;
			c_noOfItem = noOfitem;
			fooditems = new Food[c_noOfItem];
			for (int i = 0; i < c_noOfItem; i++)
			{
				fooditems[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* itemName, int calories, int code)
	{
		bool added = true;
		if (c_addedItem == c_noOfItem) added = false;
		else
		{
			fooditems[c_addedItem].set(itemName, calories, code);
			c_addedItem++;
		}
		return added;
	}

	void CalorieList::deallocate()
	{
		delete[] fooditems;
		fooditems = nullptr;
	}
}