//==============================================
// Name:           Meet Pandya
// Student Number: 116480203
// Email:          mpandya6@myseneca.ca
// Section:        ZBB
//==============================================
// Workshop:     4
// Part:         DIY
//==============================================

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds 
{
    LabelMaker::LabelMaker(int noOfLabels)
    {
        m_noOfLabels = noOfLabels;
        c_labelno = new Label[noOfLabels];
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for(int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << i+1 << endl;
            cout << "> ";
            c_labelno[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for(int i = 0; i < m_noOfLabels; i++)
        {
            c_labelno[i].printLabel() << endl;
        }
    }

    LabelMaker::~LabelMaker()
    {
        for(int i = 0; i<m_noOfLabels; i++)
        {
            c_labelno[i] = nullptr;
        }
        delete[] c_labelno;
    }
}