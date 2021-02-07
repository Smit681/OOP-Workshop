//==============================================
//Workshop   :   2
//Part       :   Lab
//==============================================
// Name          : Smit Shah
// Student Number: 116605205
// Email         : syshah3@myseneca.ca
//
// Section       : ZBB         
//==============================================

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#include "File.h"
#define DATAFILE "employees.csv"
namespace sdds {
   struct Employee {
      char* m_name;
      int m_empNo;
      double m_salary;
   };
  
   void sort();
   bool load(Employee &employeeRecord);
   bool load();
   void display(Employee &employees, int index);
   void display();
   void deallocateMemory();
}

#endif