#include <string>
#include <vector>
#include <boost/date_time.hpp>

using namespace std;

const static std::string daysOfWeek[] = {
    "SUN",
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT"
};

int getDayOfWeekIndex(int day, int month, int year) {
    boost::gregorian::date d(year, month, day);
    return d.day_of_week();
}

string solution(int a, int b) {
    string answer = daysOfWeek[getDayOfWeekIndex(b,a,2016)];
    return answer;
}