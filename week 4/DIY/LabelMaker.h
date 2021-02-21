//==============================================
// Name:           Meet Pandya
// Student Number: 116480203
// Email:          mpandya6@myseneca.ca
// Section:        ZBB
//==============================================
// Workshop:     4
// Part:         DIY
//==============================================

#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
#include "Label.h"
namespace sdds 
{
   class LabelMaker {
      Label* c_labelno;
      int m_noOfLabels;
   public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
   };
}
#endif 
