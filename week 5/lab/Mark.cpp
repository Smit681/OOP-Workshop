//==============================================
//Workshop   :   5
//Part       :   DIY
//==============================================
// Name          : Smit Shah
// Student Number: 116605205
// Email         : syshah3@myseneca.ca
//
// Section       : ZBB         
//==============================================

#include <iostream>
#include "Mark.h"
using namespace std;

namespace sdds {

	//check if the instanse variable of class mark is valid and not in empty state
	bool Mark::isvalid()const
	{
		return (m_mark >= 0 && m_mark <= 100) && m_grade != 'X';
	}

	bool Mark::isvalid(int marks) const
	{
		return (marks >= 0 && marks <= 100);
	}

	void Mark::setEmpty()
	{
		m_mark = 0;
		m_grade = 'X';
		m_scale = 0.0;
	}

	void Mark::marktogradeandscale()
	{
		if (m_mark >= 0 && m_mark < 50)
		{
			m_grade = 'F';
			m_scale = 0.0;
		}
		else if(m_mark >=50 && m_mark <60)
		{
			m_grade = 'D';
			m_scale = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			m_grade = 'C';
			m_scale = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			m_grade = 'B';
			m_scale = 3.0;
		}
		else 
		{
			m_grade = 'A';
			m_scale = 4.0;
		}
	}

	Mark::Mark()
	{
		m_mark = 0;
		m_grade = 'F';
		m_scale = 0.0;
	}

	Mark::Mark(int marks)
	{
		if (isvalid(marks))
		{
			m_mark = marks;
			marktogradeandscale();
		}
		else setEmpty();
	}

	Mark::operator int() const
	{
		return m_mark;
	}

	Mark::operator double() const
	{
		return m_scale;
	}

	Mark::operator char() const
	{
		return m_grade;
	}

	Mark& Mark::operator+=(int marks)
	{
		if (this->isvalid()) {
			if (isvalid(marks))
			{
				if (m_mark + marks <= 100)
				{
					m_mark += marks;
					marktogradeandscale();
				}
				else
					setEmpty();
			}
			else
			{
				Mark();
			}
		}
		else setEmpty();
		
		return *this;
	}

	Mark& Mark::operator=(int marks)
	{
		if (isvalid(marks))
		{
			m_mark = marks;
			marktogradeandscale();
		}
		else
		{
			setEmpty();
		}
		return *this;
	}

	int operator+=(int& value, const Mark& mark)
	{
		if ((int(mark) <= 100 && int(mark) >= 0))
		{
			value += int(mark);
		}
		return value;
	}

	


}

