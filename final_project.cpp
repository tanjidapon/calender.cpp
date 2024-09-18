#include <iostream>
using namespace std;
// Base class to handle year, month, and days calculation
class Calendar {
protected:
    int year;
    int month;
    int daysInMonth;
    int startDay;

public:
    Calendar(int y, int m) : year(y), month(m) {
        calculateDaysInMonth();
        calculateStartDay();
    }
    // Calculate the number of days in the specified month
    void calculateDaysInMonth() {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysInMonth = 31;
                break;
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
                break;
            default:
                daysInMonth = 0; // Invalid month
                }}
    // Calculate the starting day of the week for the first day of the month
    //Zeller's Congruence
    void calculateStartDay() {
        startDay = (year + (year / 4) - (year / 100) + (year / 400) + ((13 * month + 8) / 5) + 1) % 7;
    }
};
// Derived class to handle the monthly calendar display
class MonthlyCalendar : public Calendar {
public:
    MonthlyCalendar(int y, int m) : Calendar(y, m) {}

    void displayCalendar() {
        if (month < 1 || month > 12) {
            cout << "Invalid month entered. Please enter a number between 1 and 12." << endl;
            return;
        }
        cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
        for (int i = 0; i < startDay; i++) {
            cout << "    ";
        }
        for (int day = 1; day <= daysInMonth; day++) {
            cout << " ";
            if (day < 10)
                cout << " ";
            cout << day << " ";

            if ((startDay + day) % 7 == 0)
                cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int year, month;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter month (1-12): ";
    cin >> month;

    MonthlyCalendar calendar(year, month);
    calendar.displayCalendar();

    return 0;
}
