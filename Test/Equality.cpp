// Friend function for class DayOfYear.
#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
  friend bool equal(DayOfYear date1, DayOfYear date2);
  DayOfYear(int the_month, int the_day);
  // Pre: month and day form a possible date.
  // Initializes date according to args.
  DayOfYear();
  // Initializes date to 1 Jan.
  void input();
  void output();
  int get_month();
  int get_day();
private:
  void check_date();
  int month;
  int day;
};

bool equal(DayOfYear date1, DayOfYear date2)
{
  return (date1.month == date2.month &&
	  date1.day == date2.day);
}

void DayOfYear::check_date()
{
  if ((month < 1) || (month > 12)
      || (day < 1) || (day > 31))
    {
      cout << "Illegal date. Aborting program.\n";
      exit(1);
    }
}

DayOfYear::DayOfYear(int the_month, int the_day)
  : month(the_month), day(the_day)
{
  check_date();
}

DayOfYear::DayOfYear()
{
}

int DayOfYear::get_month()
{
  return month;
}

int DayOfYear::get_day()
{
  return day;
}

void DayOfYear::input()
{
  cout << "Enter the month as a number: ";
  cin >> month;
  cout << "Enter the day of month: ";
  cin >> day;
}

void DayOfYear::output()
{
  cout << "month = " << month
       << ", day = " << day << endl;
}

int main()
{
  DayOfYear today, bach_birthday(3, 21);
  cout << "Enter today's date:\n";
  today.input();
  cout << "Today's date is ";
  today.output();
  cout << "J. S. Bach's birthday is ";
  bach_birthday.output();
  if (equal(today, bach_birthday))
    cout << "Happy Birthday JS Bach!\n";
  else
    cout << "Happy Unbirthday JS Bach!\n";
  return 0;
}
