#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {
	class Food {
	private:
		char f_name[31];
		int f_calorie;
		int f_code;
		void setname(const char* name);
	public:
		void setEmpty();
		bool isValid() const;
		bool isValid(const char* name) const;
		bool isValid(const int calorie, const int code) const;
		void set(const char* name, const int calorie, const int code);
		int getcalorie() const;
		void codeTostr(int code) const;
		void display() const;
	};
}

#endif