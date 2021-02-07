//==============================================
//Workshop   :   3
//Part       :   Lab
//==============================================
// Name          : Smit Shah
// Student Number: 116605205
// Email         : syshah3@myseneca.ca
//
// Section       : ZBB         
//==============================================

#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds 
{
	bool Item::isValid() const
	{
		bool valid = false;
		if ((m_price != 0.0) && (m_itemName[0] != '\0'))
			valid = true;
		return valid;
	}

	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
	}

	void Item::setEmpty()
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (price < 0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::tax() const
	{
		double t = 0.0;

		if (m_taxed) 
			t = m_price * 0.13;
		return t;
	}

	double Item::price() const
	{
		return m_price;
	}

	void Item::display() const
	{
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_itemName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(7);
			cout.fill(' ');
			cout << m_price;
			cout.unsetf(ios::right);
			cout << " | ";
			if (!m_taxed) 
			cout << "No ";
			else 
			cout << "Yes";
			cout << " |" << endl;
		}
		else 
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
	}
}