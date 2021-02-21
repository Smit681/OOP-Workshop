//==============================================
// Name:           Meet Pandya
// Student Number: 116480203
// Email:          mpandya6@myseneca.ca
// Section:        ZBB
//==============================================
// Workshop:     4
// Part:         DIY
//==============================================

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds 
{
   class Label {
        char* str_Frame;
        char* str_Data;
        void setFrame(const char* strFrame);
        void setContent(const char* strFrame);
        void printLine() const;
   public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;
   };
}

#endif // !SDDS_LABEL_H
