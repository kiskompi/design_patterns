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

    std::string to_string() const;
private:
    
};

Date ::Date ()
{
}

Date ::~Date ()
{
}

Date::Date (const std::string& p_str){
    size_t fst = p_str.find_first_of ('-');
    size_t scd = p_str.find_last_of  ('-');

    std::string str_year  = p_str.substr(0,fst);
    std::string str_month = p_str.substr(fst+1,2);
    std::string str_day   = p_str.substr(scd+1,2);
    
    m_year   =  std::stoi(str_year);
    m_month  =  Date::Month(std::stoi(str_month));
    m_day    =  std::stoi(str_day);
}


std::string Date::to_string () const {
    std::string month = std::to_string(m_month);
    if (m_month<10)
        month = "0" + std::to_string(m_month);
    std::string day = std::to_string(m_day);        
    if (m_day<10)
        day = "0" + std::to_string (m_day);
    
    return std::to_string(m_year) + "-" + month + "-" + day;
}
#endif
