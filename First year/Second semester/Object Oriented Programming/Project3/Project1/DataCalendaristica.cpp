#include <iostream>
#include "DataCalendaristica.h"

using namespace std;

DataCalendaristica::DataCalendaristica(const unsigned short zi, const unsigned short luna, const unsigned long long an)
    :m_zi{zi}, m_luna{luna}, m_an{an}
{}


unsigned short DataCalendaristica::getZi()const { return m_zi; }
unsigned short DataCalendaristica::getLuna()const { return m_luna; }
unsigned long long DataCalendaristica::getAn()const { return m_an; }


int operator <(const DataCalendaristica& obj_1, const DataCalendaristica& obj_2)
{
    if (obj_1.getAn() < obj_2.getAn())
    {
        return 1;
    }

    else if (obj_1.getAn() > obj_2.getAn())
    {
        return 0;
    }

    else
    {
        if (obj_1.getLuna() < obj_2.getLuna())
        {
            return 1;
        }

        else if (obj_1.getLuna() > obj_2.getLuna())
        {
            return 0;
        }

        else 
        {
            if (obj_1.getZi() < obj_2.getZi())
            {
                return 1;
            }

            else if (obj_1.getZi() > obj_2.getZi())
            {
                return 0;
            }

            else return 2;
        }

    }
}


int operator >(const DataCalendaristica& obj_1, const DataCalendaristica& obj_2)
{
    if (obj_1.getAn() > obj_2.getAn())
    {
        return 1;
    }

    else if (obj_1.getAn() < obj_2.getAn())
    {
        return 0;
    }

    else
    {
        if (obj_1.getLuna() > obj_2.getLuna())
        {
            return 1;
        }

        else if (obj_1.getLuna() < obj_2.getLuna())
        {
            return 0;
        }

        else
        {
            if (obj_1.getZi() > obj_2.getZi())
            {
                return 1;
            }

            else if (obj_1.getZi() < obj_2.getZi())
            {
                return 0;
            }

            else return 2;
        }

    }
}


ostream& operator << (ostream& COUT, const DataCalendaristica& obj1)
{
    COUT << obj1.getZi() << '.' << obj1.getLuna() << '.' << obj1.getAn();
    return COUT;
}

void DataCalendaristica::operator += (int increase)
{
   unsigned short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   if ((this->getAn() % 4 == 0 && this->getAn() % 100 != 0) || (this->getAn() % 400 == 0)) arr[1] = 29;

   int daysAdded = 0;
   int ani = 0;

   unsigned short k = this->m_luna - 1;

   daysAdded = arr[k] - this->m_zi;

   if (k + 1 == 12) k = 0;
   else ++k;
   while ((increase - daysAdded) > 0)
   {
       daysAdded += arr[k];
       if (k + 1 == 12)
       {
           k = 0;
           ++ani;
       }
       else ++k;
   }

   daysAdded = daysAdded - arr[k];

   this->m_zi = increase - daysAdded + 1;
   this->m_luna = k;
   this->m_an += ani;
}


void DataCalendaristica::operator -= (int decrease)
{
    unsigned short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((this->getAn() % 4 == 0 && this->getAn() % 100 != 0) || (this->getAn() % 400 == 0)) arr[1] = 29;

    int daysDecreased = 0;
    int ani = 0;

    unsigned short k = this->m_luna - 1;

    daysDecreased = this->m_zi;
    if (k - 1 == -1) k = 11;
    else --k;

    while ((decrease - daysDecreased) > 0)
    {
        daysDecreased += arr[k];
        if (k - 1 == -1)
        {
            k = 11;
            ++ani;
        }
        else if(decrease - daysDecreased > 0) --k;
    }

    this->m_zi = daysDecreased - decrease;
    this->m_luna = ++k;
    this->m_an -= ani;
}


void DataCalendaristica::extrageDate()const
{
    cout << "Zi: " << this->m_zi << endl;
    cout << "Luna: " << this->m_luna << endl;
    cout << "An: " << this->m_an << endl;
}