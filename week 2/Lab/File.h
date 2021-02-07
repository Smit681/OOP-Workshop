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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char employeeName[]);
   bool read(int &employeeNumber);
   bool read(double &employeeSalary);
}
#endif