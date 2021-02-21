//==============================================
// Name:           Meet Pandya
// Student Number: 116480203
// Email:          mpandya6@myseneca.ca
// Section:        ZBB
//==============================================
// Workshop:     4
// Part:         DIY
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" 
#include "Label.h"
using namespace std;

namespace sdds 
{
    Label::Label()
    {
        str_Data = nullptr;
        str_Frame = new char[9];
        strCpy(str_Frame, "+-+|+-+|");
    }

	Label::Label(const char* frameArg)
    {
        str_Data = nullptr;
        setFrame(frameArg);
    }

    Label::Label(const char* frameArg, const char* content)
    {
        setFrame(frameArg);
        setContent(content);
    }

	void Label::setFrame(const char* strFrame)
    {
        if (strFrame != nullptr)
        {
            int len = strLen(strFrame);
            str_Frame = new char[len + 1];
            strCpy(str_Frame, strFrame);
        }
    }
	
	void Label::readLabel()
    {
        str_Data = new char[71];
        cin.getline(str_Data, 71);
    }

    void Label::setContent(const char* strFrame)
    {
        if(strFrame != nullptr)
        {
            int len = strLen(strFrame);
            str_Data = new char[len + 1];
            strCpy(str_Data, strFrame);
        }
    }

    void Label::printLine() const
    {
        int pos = 0;
        while(str_Data[pos])
        {
            cout << " ";
            pos++;
        }
        cout << "  ";
    }

    std::ostream& Label::printLabel() const
    {
        if(str_Data != nullptr && strLen(str_Data) > 0)
        {
            cout << str_Frame[0];
            for(int i = 0; i<strLen(str_Data)+2; i++)
                cout << str_Frame[1];
            cout << str_Frame[2] << endl;
            cout << str_Frame[7];
            printLine();
            cout << str_Frame[3] << endl;

            cout << str_Frame[7];
            cout << " " << str_Data << " ";
            cout << str_Frame[3] << endl;

            cout << str_Frame[7];
            printLine();
            cout << str_Frame[3] << endl;

            cout << str_Frame[6];
            for(int i = 0; i<strLen(str_Data)+2; i++)
                cout << str_Frame[5];
            cout << str_Frame[4];
        }
        return cout;
    }

    Label::~Label()
    {
        str_Frame = nullptr;
        str_Data = nullptr;
    }
}
