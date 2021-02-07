//==============================================
//Workshop   :   3
//Part       :   Lab
//==============================================
// Name          : Smit Shah
// Student Number: 116605205
// Email         : syshah3@myseneca.ca
//
// Section       : ZBB         
//==============================================


#include "cstring.h"
#include <iostream>

namespace sdds {
    int strLen(const char* s)
    {
        int length = 0;
        for (; s[length] != '\0'; length++)
        {
        }
        return length;
    }

    void strCpy(char* des, const char* src)
    {

        while (*src != 0)
        {
            *des++ = *src++;
        }

        *des = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        int length = strLen(src);
        for (; i < len && length; i++)
        {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

    int strCmp(const char* s1, const char* s2)
    {
        int i = 0;
        int l1 = strLen(s1);
        int l2 = strLen(s2);
        while (s1[i] != '\0' && s2[i] != '\0')
        {

            if (s1[i] > s2[i])  return 1;
            else if (s1[i] < s2[i]) return -1;
            i++;
        }
        if (l1 == l2) return 0;
        else
        {
            if (l1 > l2)
                return 1;
            else
                return -1;
        }

    }

    int strnCmp(const char* s1, const char* s2, int length)
    {
        int i = 0;

        while (i < length && s1[i] != '\0' && s2[i] != '\0')
        {

            if (s1[i] > s2[i])  return 1;
            else if (s1[i] < s2[i]) return -1;
            i++;
        }
        return 0;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        const char* ans;
        const char* a;
        ans = str2;

        if (str2 == 0)
            return str1;

        for (; *str1 != 0; str1++)
        {
            if (*str1 != *str2)  continue;
            a = str1;
            for (;;)
            {
                if (*ans == 0) return str1;
                if (*ans++ != *a++)  break;
            }
            ans = str2;
        }
        return NULL;
    }

    void strCat(char* des, const char* src)
    {
        int l1 = strLen(des);

        for (int i = 0; src[i] != '\0'; i++, l1++)
        {
            des[l1] = src[i];
        }
        des[l1] = '\0';

    }
}

