#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
#include <utility>

std::pair<std::string, std::string> httpGet(std::string url);

void test();



/** Date utility class **/
class DateTools {

private:
    boost::gregorian::date base_date;

public:
    DateTools() { base_date = boost::gregorian::day_clock::local_day(); };


    DateTools(int offset_days) {
        auto dd   = boost::gregorian::date_duration(offset_days);
        base_date = boost::gregorian::day_clock::local_day() + dd;
    };


    DateTools(std::string date_str) {
        base_date = boost::gregorian::from_string(date_str);
    };


    std::string getDate() { return to_iso_extended_string(base_date); };



    std::string getQuarter() {
        auto month_number = base_date.month().as_number();
        auto t1           = (double)month_number / 3;
        auto t2           = ceil(t1);
        return std::to_string(t2);
    };
};
