// Create a class by name date with the member data day, month and year. Perform the following: 
// • Overload all relational operators <, <=, >, >=, ==, != 
// • Overload ++ operator to increment a date by one day 
// • Overload + to add given number of days to find the next date 
// • Provide the necessary function to use the statement like days=dt; where days is an int 
// variable and dt is an object of date class. The statement is intended to assign the number of days 
// elapsed in the current year of the date to the variable days. Note that this is a case of conversion 
// from derived type to basic type.
// #include <iostream>
// #include <ctime>
// #include <stdexcept>

class date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        switch (m) {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(y) ? 29 : 28;
            default:
                return 31;
        }
    }

    int daysInYear() const {
        return isLeapYear(year) ? 366 : 365;
    }

public:
    date() : day(1), month(1), year(1970) {}

    date(int d, int m, int y) : day(d), month(m), year(y) {
        if (d > daysInMonth(m, y) || d < 1 || m > 12 || m < 1 || y < 1) {
            throw std::invalid_argument("Invalid date");
        }
    }

    bool operator<(const date& d) const {
        if (year < d.year) return true;
        if (year == d.year && month < d.month) return true;
        if (year == d.year && month == d.month && day < d.day) return true;
        return false;
    }

    bool operator<=(const date& d) const {
        return *this < d || *this == d;
    }

    bool operator>(const date& d) const {
        return !(*this <= d);
    }

    bool operator>=(const date& d) const {
        return !(*this < d);
    }

    bool operator==(const date& d) const {
        return day == d.day && month == d.month && year == d.year;
    }

    bool operator!=(const date& d) const {
        return !(*this == d);
    }

    date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    date operator+(int days) const {
        date temp = *this;
        while (days--) {
            ++temp;
        }
        return temp;
    }

    operator int() const {
        int days = 0;
        for (int y = 1970; y < year; ++y) {
            days += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            days += daysInMonth(m, year);
        }
        days += day;
        return days;
    }

    friend std::ostream& operator<<(std::ostream& os, const date& d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
};

int main() {
    date dt1(1, 1, 2023);
    date dt2(31, 12, 2023);

    std::cout << "dt1: " << dt1 << "\n";
    std::cout << "dt2: " << dt2 << "\n";

    std::cout << "dt1 < dt2: " << (dt1 < dt2) << "\n";
    std::cout << "dt1 <= dt2: " << (dt1 <= dt2) << "\n";
    std::cout << "dt1 > dt2: " << (dt1 > dt2) << "\n";
    std::cout << "dt1 >= dt2: " << (dt1 >= dt2) << "\n";
    std::cout << "dt1 == dt2: " << (dt1 == dt2) << "\n";
    std::cout << "dt1 != dt2: " << (dt1 != dt2) << "\n";

    ++dt1;
    std::cout << "After incrementing dt1: " << dt1 << "\n";

    date dt3 = dt1 + 365;
    std::cout << "dt3 (365 days after dt1): " << dt3 << "\n";

    int daysElapsed = dt3;
    std::cout << "Days elapsed in dt3's year: " << daysElapsed << "\n";

    return 0;
}

