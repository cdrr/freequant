#ifndef FQ_UTILS_DATETIME_H
#define FQ_UTILS_DATETIME_H

#include <ctime>
#include <boost/date_time.hpp>

namespace FreeQuant { namespace Utils {

class DateTime {
public:
    DateTime();
    ~DateTime() {}
    DateTime(const DateTime&);

    DateTime fromString(const std::string& string);
    DateTime fromString(const std::string& string, const std::string& format);
    DateTime fromTimeT(const std::time_t t);
    std::string toString();

    DateTime addYears(int nyears) const;
    DateTime addMonths(int nmonths) const;
    DateTime addDays(int ndays) const;
    DateTime addHours(int nhours) const;
    DateTime addMinutes(int nminutes) const;
    DateTime addSeconds(int nseconds) const;
    DateTime addMilliSeconds(long milliseconds) const;

    DateTime toLocalTime() const;
    DateTime toUTC() const;

    bool operator!=(const DateTime&) const;
    bool operator<(const DateTime&) const;
    bool operator<=(const DateTime&) const;
    DateTime& operator=(const DateTime&);
    bool operator>=(const DateTime&) const;
    bool operator==(const DateTime&) const;
    bool operator>(const DateTime&) const;

private:
    boost::posix_time::ptime datetime;
};

std::ostream& operator<<(std::ostream& out, const DateTime& dateTime);
std::istream& operator>>(std::istream& in, DateTime& dateTime);

}}

#endif // FQ_UTILS_DATETIME_H
