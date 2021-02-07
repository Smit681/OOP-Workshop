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
#include "Bill.h"

using namespace std;

namespace sdds 
{
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}
	
	bool Bill::isValid() const
	{
		bool valid = true;
		if (m_title == "\0" || m_items == nullptr)  valid = false;
		else
		{
			for (int i = 0; valid && i < m_noOfItems; i++)
			{
				valid = m_items[i].isValid();
			}
		}
		return valid;
	}

	void Bill::Title() const
	{
		cout << "+--------------------------------------+";
		cout << endl;
		if (isValid()) 
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title;
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else 
			cout << "| Invalid Bill                         |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::init(const char* title, int noOfItems)
	{
		if (title[0] == '\0' || noOfItems <= 0) 
			setEmpty();
		else 
		{
			m_itemsAdded = 0;
			m_noOfItems = noOfItems;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
			
		}
	}

	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout << "|                Total Tax: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(10);
			cout << totalTax();
			cout.unsetf(ios::right);
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(10);
			cout << totalPrice();
			cout.unsetf(ios::right);
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout.width(10);
			cout << totalTax() + totalPrice();
			cout.unsetf(ios::right);
			cout << " |" << endl;
		}
		else 
			cout << "| Invalid Bill                         |" << endl;
		cout << "+--------------------------------------+" << endl;
	}


	
	bool Bill::add(const char* item_name, double price, bool taxed){

		bool valid = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			valid = true;
		}
		return valid;
	}

	void Bill::display() const
	{
		Title();

		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		
		footer();
	}

	double Bill::totalPrice() const
	{
		double a = 0.0;

		for (int i = 0; i < m_noOfItems; i++) 
			a =a+ m_items[i].price();
		
		return a;
	}

	double Bill::totalTax() const
	{
		double a = 0.0;

		for (int i = 0; i < m_noOfItems; i++)
		{
			a = a + m_items[i].tax();
		}
		
		return a;
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}