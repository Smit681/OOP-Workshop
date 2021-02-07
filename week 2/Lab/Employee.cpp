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

#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds {

   int noOfEmployees;
   Employee* employees;

   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load(Employee &employeeRecord) {
      bool ok = false;
      char name[128];
      int number;
      double salary;
      ok = read(number) && read(salary) && read(name);
      if(ok) 
      {
         employeeRecord.m_name = new char[strLen(name)+1];
         strCpy(employeeRecord.m_name,name);
         employeeRecord.m_empNo = number;
         employeeRecord.m_salary = salary;
      }
      return ok;
   }

   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords();
         employees = new Employee[noOfEmployees];
         while(i<noOfEmployees)
         {
            ok = load(employees[i++]);
            if(!ok)
            {
               cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
               break;
            }  
         }  
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      closeFile();
      return ok;
   }

   void display(Employee &employees, int index)
   {
      cout << index <<  "- " << employees.m_empNo << ": " << employees.m_name << ", " 
         << employees.m_salary << endl;
   }

   void display()
   {
      int i=0;
      cout << "Employee Salary report, sorted by employee number" << endl;
      cout << "no- Empno, Name, Salary" << endl;
      cout << "------------------------------------------------" << endl;
      sort();
      for(i; i<noOfEmployees;i++)
      {
         display(employees[i],i+1);
      }
   }

   void deallocateMemory()
   {
      delete [] employees;
      delete [] employees->m_name;
   }
}