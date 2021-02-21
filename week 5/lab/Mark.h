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

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds {

	class Mark {
		int m_mark;
		char m_grade;
		float m_scale;
		bool isvalid() const;
		bool isvalid(int marks) const;
		void setEmpty();
	public:
		void marktogradeandscale();
		Mark();
		Mark(int marks);
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator+=(int marks);
		Mark& operator=(int marks);
	};

	int operator +=(int& value, const Mark& mark);

}

#endif // SDDS_ACCOUNT_H_