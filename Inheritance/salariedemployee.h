// Header interface file for salaried employee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;

namespace employee_robotony
{
  class SalariedEmployee : public Employee
  {
  public:
    // Constructor with no args.
    SalariedEmployee();
    // Constructor with 3 args.
    SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary);
    // Gets salary.
    double get_salary() const;
    // Sets salary.
    void set_salary(double new_salary);
    // Prints the thing that checks if we did right.
    void print_check();
  private:
    double salary;
  };
} // End of employee_robotony namespace.

#endif
