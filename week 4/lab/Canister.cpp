//==============================================
//Workshop   :   4
//Part       :   LAB
//==============================================
// Name          : Smit Shah
// Student Number: 116605205
// Email         : syshah3@myseneca.ca
//
// Section       : ZBB         
//==============================================


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265
using namespace std;
namespace sdds {

	
	void Canister::setToDefault() 
	{
		m_contentName = nullptr;
		m_hieght = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	
	bool Canister::isEmpty()const
	{
		bool empty = false;
		if (m_contentVolume < 0.00001) empty = true;
		return empty;
	}

	
	bool Canister::hasSameContent(const Canister& C)const
	{
		bool issame = false;
		if (*this->m_contentName && m_contentName && strCmp(this->m_contentName, m_contentName) == 0)
			issame = true;
		return issame;
	}

	
	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable == true)
		{
			delete[] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	
	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	
	Canister::Canister(double hieght, double diameter, const char* contentName)
	{
		setToDefault();
		if (hieght <= 40 && hieght >= 10.0 && diameter >= 10.0 && diameter <= 30)
		{
			m_hieght = hieght;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
	}

	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0;
		m_usable = true;
	}

	double Canister::capacity()const
	{
		return PI * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	double Canister::volume()const
	{
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr)	
			m_usable = false;
		else if (isEmpty())  
			setName(contentName);
		else if (strCmp(contentName,m_contentName) != 0)    
			m_usable = false;
		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable == true && quantity > 0 && ((quantity + volume()) <= capacity()))
		{
			m_contentVolume += quantity;
		}
		else m_usable = false;
		return *this;
	}
   
	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);

		if (C.volume() > (capacity() - volume()))
		{
			C.m_contentVolume -= (capacity() - volume());

			m_contentVolume = capacity();
		}
		else
		{
			pour(C.m_contentVolume);

			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	std::ostream& Canister::display()const
	{
		cout.setf(ios::fixed);
		cout.width(7);
		cout.precision(1);
		cout << capacity() << "cc (";
		cout.unsetf(ios::fixed);

		cout.setf(ios::fixed);
		cout.precision(1);
		cout << m_hieght << "x" << m_diameter << ") Canister";
		cout.unsetf(ios::fixed);

		if (!m_usable)
			cout << " of Unusable content, discard!";
		else
		{
			if (m_contentName)
			{
				cout << " of ";
				cout.setf(ios::fixed); 
				cout.width(7);
				cout.precision(1);
				cout << volume() << "cc   ";
				cout.unsetf(ios::fixed);
				cout << m_contentName;
			}
		}
		return cout;
	}
}


