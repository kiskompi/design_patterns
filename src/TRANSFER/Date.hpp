#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include "Object.hpp"

class Date: public TransferObject
{
public:
    typedef enum {
        January, 
        February,
        March,
        April,
        May,
        June,
        July,
        October,
        November,
        December
    } Month;
    typedef unsigned char   Day;
    typedef unsigned short  Year;

private:
    Day     m_day   = 0;
    Month   m_month = January;
    Year    m_year  = 0;

public:
    Date ();
    Date (Date&&)                  = default;
    Date (const Date&)             = default;
    Date (const std::string&);
    Date  &operator=(Date&&)       = default;
    Date  &operator=(const Date&)  = default;
    bool  operator==(const Date& o) const {
        return
        (
            m_day   == o.m_day  &&
            m_month == o.m_month&&
            m_year  == o.m_year 
        );
    }
    bool  operator!=(const Date& o) const {
        return
        (
            m_day   != o.m_day  &&
            m_month != o.m_month&&
            m_year  != o.m_year 
        );
    }
    ~Date ();

    std::string to_string() const;
private:
    
};
#endif
