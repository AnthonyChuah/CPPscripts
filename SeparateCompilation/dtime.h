// Header file dtime.h: this is the INTERFACE for class DigitalTime.
// Time of day in HH:MM output.
#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using namespace std;

class DigitalTime
{
public:
  friend bool operator==(const DigitalTime& time1, const DigitalTime& time2);
  // Returns true if time1 and time2 are the same.
  DigitalTime(int the_hour, int the_minute);
  // Constructor with two arguments.
  DigitalTime();
  // Constructor with no arguments.
  void advance(int minutes_added);
  // Increments object by minutes_added minutes.
  void advance(int hours_added, int minutes_added);
  // Increments object by hours_added and minutes_added.
  friend istream& operator >>(istream& ins, DigitalTime& the_object);
  // Overloads >> operator for values of type DigitalTime.
  friend ostream& operator <<(ostream& outs, const DigitalTime& the_object);
  // Overloads << operator to output DigitalTime to a stream.
private:
  int hour;
  int minute;
};

#endif
