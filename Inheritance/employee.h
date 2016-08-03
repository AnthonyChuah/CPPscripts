// Header interface file for employee class.

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

namespace employee_robotony
{
  class Employee
  {
  public:
    // Constructor with no arguments.
    Employee();
    // Constructor with two string args.
    Employee(string the_name, string the_ssn);
    // Method to get name of employee.
    // Public and must not modify the object.
    string get_name() const;
    // Method to get social security number.
    string get_ssn() const;
    // Method to get salary of employee.
    double get_net_pay() const;
    // Method to set name of employee.
    // Public and should be able to modify the object.
    void set_name(string new_name);
    // Method to set social security number.
    void set_ssn(string new_ssn);
    // Method to set salary.
    void set_net_pay(double new_net_pay);
    // Method to print attributes.
    void print_check() const;
  private:
    string name;
    string ssn;
    double net_pay;
  };
} // namespace employee_robotony

#endif
