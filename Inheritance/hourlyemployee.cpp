// Implementation file for HourlyEmployee subclass.
#include <string>
#include <iostream>
#include "hourlyemployee.h"
using namespace std;

namespace employee_robotony
{
  // Constructor: notice how it calls the constructor from the parent class.
  HourlyEmployee::HourlyEmployee() : Employee(), wage_rate(0), hours(0)
  {
    // Empty.
  }

  // Constructor with args: again, calls parent's constructor.
  HourlyEmployee::HourlyEmployee(string the_name, string the_number,
				 double the_wage_rate, double the_hours)
    : Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
  {
    // Empty.
  }

  // Sets hourly wage.
  void HourlyEmployee::set_rate(double new_wage_rate)
  {
    wage_rate = new_wage_rate;
  }

  // Gets hourly wage.
  double HourlyEmployee::get_rate() const
  {
    return wage_rate;
  }

  // Sets hours worked.
  void HourlyEmployee::set_hours(double hours_worked)
  {
    hours = hours_worked;
  }

  // Gets hours worked.
  double HourlyEmployee::get_hours() const
  {
    return hours;
  }

  // Prints the check thing.
  void HourlyEmployee::print_check()
  {
    // See how this method comes from the parent?
    set_net_pay(hours * wage_rate);
    cout << "\n______________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " dollars\n";
    cout << "______________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Hourly Employee.\n";
    cout << "Hours worked: " << hours
	 << " Rate: " << wage_rate << " Pay: " << get_net_pay() << endl;
    cout << "______________________________________\n";
  }
} // End of employee_robotony namespace.
