#include <iostream>
#include <string>
#include <cstdlib>
#include "Header.h"

using namespace Numbers;

using namespace std;

struct strDate
{
    short Month = 10;
    int Days = 22;
    int Year = 2024;
};

int GetDayOrder(int Year, int Month, int Day)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + (12 * a) - 2;

    return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string DayName(int Year, int Month, int Day)
{
    int DayOrder = GetDayOrder(Year, Month, Day);
    string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return Days[DayOrder];
}

int GetNumberOfDaysInMonth(int Year, int Month)
{
    int NumberOfDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return ((Month == 2) ? LeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1]);
}

bool IsLastDayInWeek(strDate Date)
{
    return GetDayOrder(Date.Year, Date.Month, Date.Days) == 6;
}

bool IsWeekEnd(strDate Date)
{
    return DayName(Date.Year, Date.Month, Date.Days) == "Fri" || DayName(Date.Year, Date.Month, Date.Days) == "Thu";
}

bool IsBusinessDay(strDate Date)
{
    return !IsWeekEnd(Date);
}

int DaysUntilEndOfWeek(strDate Date)
{
    return 6 - GetDayOrder(Date.Year, Date.Month, Date.Days);
}

int DaysUntilEndOfMonth(strDate Date)
{
    return GetNumberOfDaysInMonth(Date.Year, Date.Month) - Date.Days;
}

int DaysUntilEndOfYear(strDate Date)
{
    int RemainingDays = DaysUntilEndOfMonth(Date);

    for (int i = Date.Month + 1; i <= 12; i++)
    {
        RemainingDays += GetNumberOfDaysInMonth(Date.Year, i);
    }
    return RemainingDays;

}

int main()
{
    strDate Date;
    string Result = IsLastDayInWeek(Date) ? "Last Day" : "Not Last Day";
    cout << DaysUntilEndOfYear(Date);
}
