// Header file hourlyemployee.h.
// Interface for subclass HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;
namespace employee_robotony
{
  class HourlyEmployee : public Employee
  {
  public:
    // Constructor.
    HourlyEmployee();
    // Constructor with 4 args.
    HourlyEmployee(string the_name, string the_ssn,
		   double the_wage_rate, double the_hours);
    // Sets hourly wage rate.
    void set_rate(double new_wage_rate);
    // Gets hourly wage rate.
    double get_rate() const;
    // Sets the number of hours worked.
    void set_hours(double hours_worked);
    // Gets the number of hours worked.
    double get_hours() const;
    // Prints something to check if we did right.
    void print_check();
  private:
    double wage_rate;
    double hours;
  };
} // End of employee_robotony namespace.

#endif
