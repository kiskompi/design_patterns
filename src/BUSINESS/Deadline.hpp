#ifndef DEADLINE_HPP
#define DEADLINE_HPP

#include <ctime>
#include "../TRANSFER/Date.hpp"

class Deadline {
    Date m_due;
public:
    Deadline () {
        std::time_t result  = std::time(nullptr);
        char mbstr[100];
        std::strftime(mbstr, sizeof(mbstr), "%F", std::localtime(&result));
        const std::string now (mbstr);
        m_due = Date (now);
    }

    Deadline (std::string date):
        m_due (date){}    

    Deadline (const Date& date):
        m_due (date){}    
    Deadline (const Deadline&)             = default;
    Deadline&  operator=(Deadline&&)       = default;
    Deadline&  operator=(const Deadline&)  = default;
    bool  operator==(const Deadline& o) const {return m_due == o.m_due;}
    bool  operator!=(const Deadline& o) const {return m_due != o.m_due;}

    bool is_expired () {
        std::time_t result  = std::time(nullptr);
        char mbstr[100];
        std::strftime(mbstr, sizeof(mbstr), "%F", std::localtime(&result));
        std::string now {mbstr};
        return now.compare (m_due.to_string ())  < 0;
    }

    std::string to_string() const {
        return m_due.to_string ();
    }
};


#endif 