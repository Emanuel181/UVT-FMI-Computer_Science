#pragma once
using namespace std;
#include <iostream>
class DataCalendaristica
{
private:
    unsigned long long m_zi;
    unsigned short m_luna;
    unsigned long long m_an;
public:
    DataCalendaristica(const unsigned short, const unsigned short, const unsigned long long);
    friend int operator <(const DataCalendaristica&, const DataCalendaristica&);
    friend int operator >(const DataCalendaristica&, const DataCalendaristica&);
    friend ostream& operator << (ostream&, const DataCalendaristica&);
    void operator += (int);
    void operator -= (int);
    unsigned short getZi()const;
    unsigned short getLuna()const;
    unsigned long long getAn()const;
    void extrageDate()const;
};

