#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H

#include "Food.h"

namespace sdds {
	class CalorieList {
	private:
		Food* fooditems;
		int c_noOfItem;
		int c_addedItem;
		void setEmpty();
		bool isValid() const;
		int TotalCalorie() const;
		void Tital() const;
		void footer() const;
	public:
		void init(int noOfitem);
		bool add(const char* itemName, int calories, int code);
		void display() const;
		void deallocate();
	};
}


#endif