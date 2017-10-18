#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date 
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
    Day     m_day;
    Month   m_month;
    Year    m_year;

public:
    Date ();
    Date (Date  &&) = default;
    Date (const Date  &) = default;
    Date (const std::string&);
    Date  &operator=(Date  &&) = default;
    Date  &operator=(const Date  &) = default;
    ~Date ();

    std::string to_string();
private:
    
};

Date ::Date ()
{
}

Date ::~Date ()
{
}

Date::Date (const std::string& p_str){
    std::string str_year  = p_str.substr(0,4);
    std::string str_month = p_str.substr(5,6);
    std::string str_day = p_str.substr(8,9);
    m_year  = std::stoi(str_year);
    m_month = Date::Month(std::stoi(str_month));
    m_day   = std::stoi(str_day);
}


std::string Date::to_string(){
    return std::to_string(m_year) + "-" + std::to_string(m_month) + "-" + std::to_string(m_day);
}
#endif
