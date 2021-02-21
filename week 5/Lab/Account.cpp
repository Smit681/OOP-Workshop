#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   bool Account::isvalid()
   {
      return m_number >= 0 && m_balance >= 0.0;
   }
   Account::operator bool() const
   {
      return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }
   Account::operator int() const
   {
      return m_number;
   }
   Account::operator double() const
   {
      return m_balance;
   }
   bool Account::operator ~() const
   {
      return m_number == 0;
   }
   Account& Account::operator =(int number)
   {
      if(m_number >= 0 && m_balance >= 0.0 && m_number == 0 && m_balance == 0.0)
      {
         setEmpty();
         if(number >= 10000 && number <= 99999)
         {
            m_number = number;
         }
      }
      return *this;
   }
   Account& Account::operator =(Account& a)
   {
      if(m_number == 0 && m_balance == 0.0 &&  a.m_number >= 10000 && a.m_number <= 99999)
      {
         m_number = a.m_number;
         a.m_number = 0;
         m_balance = a.m_balance;
         a.m_balance = 0;
      }
      return *this;
   }
   Account& Account::operator +=(double balance)
   {
      if(m_number >= 0 && m_balance >= 0.0 && balance >=0)
      {
         m_balance += balance;
      }
      return *this;
   }
   Account& Account::operator -=(double balance)
   {
      if(m_number >= 0 && m_balance >= 0.0&& balance >=0 && m_balance >= balance)
      {
         m_balance -= balance;
      }
      return *this;
   }

   Account& Account::operator <<(Account& a)
   {
      if(m_number >= 0 && m_balance >= 0.0 && a.m_number >= 0 && a.m_balance >= 0.0 && m_number != a.m_number)
      {
         m_balance += a.m_balance;
         a.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator >>(Account& a)
   {
      if(m_number >= 0 && m_balance >= 0.0 && a.m_number >= 0 && a.m_balance >= 0.0 && m_number != a.m_number)
      {
         a.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   double operator +(const Account& a, const Account& b)
   {
      if(!~a && !~b)
      {
         return double(a) + double(b);
      }
      return 0;
   }
   
   double operator +=(double& balance, const Account& a)
   {
      if(!~a)
      {
         balance = (balance + double(a));
         return balance;
      }
      return balance;
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
}
