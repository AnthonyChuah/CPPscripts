// Implementation file dtime.cpp for the dtime.h class headers.
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "dtime.h"
using namespace std;

void read_hour(istream& ins, int& the_hour);
// Next input in the stream ins is in HH:MM notation.
// the_hour will be set to HH, the colon will be discarded, and
// the MM part will then be read.

void read_minute(istream& ins, int& the_minute);
// Reads the minutes in MM format from the stream after read_hour
// is done with the stream.

int digit_to_int(char c);
// c is '0' to '9' character.
// Returns integer for that digit.

bool operator ==(const DigitalTime& time1, const DigitalTime& time2)
{
  return (time1.hour == time2.hour && time1.minute == time2.minute);
}

DigitalTime::DigitalTime(int the_hour, int the_minute)
{
  if (the_hour < 0 || the_hour > 23 || the_minute < 0 || the_minute > 59)
    {
      cout << "Illegal arguments for DigitalTime constructor.";
      exit(1);
    }
  else
    {
      hour = the_hour;
      minute = the_minute;
    }
}

DigitalTime::DigitalTime() : hour(0), minute(0)
{
}

void DigitalTime::advance(int minutes_added)
{
  int gross_minutes = minute + minutes_added;
  minute = gross_minutes % 60;
  // Remember that dividing an int is a floor division.
  int hour_adjustment = gross_minutes / 60;
  hour = (hour + hour_adjustment) % 24;
}

void DigitalTime::advance(int hours_added, int minutes_added)
{
  hour = (hour + hours_added) % 24;
  // Piggyback on the advance-by-minutes overloading.
  advance(minutes_added);
}

// Whenever overloading << operator always return the out stream.
ostream& operator <<(ostream& outs, const DigitalTime& the_object)
{
  outs << the_object.hour << ':';
  if (the_object.minute < 10)
    outs << '0';
  outs << the_object.minute;
  return outs;
}

// Whenever overloading >> operator always return the in stream.
istream& operator >>(istream& ins, DigitalTime& the_object)
{
  read_hour(ins, the_object.hour);
  read_minute(ins, the_object.minute);
  return ins;
}

int digit_to_int(char c)
{
  return (static_cast<int>(c) - static_cast<int>('0'));
}

void read_minute(istream& ins, int& the_minute)
{
  char c1, c2;
  ins >> c1 >> c2;
  if (!(isdigit(c1) && isdigit(c2)))
    {
      cout << "Error illegal input to read_minute\n";
      exit(1);
    }
  the_minute = (digit_to_int(c1) * 10) + digit_to_int(c2);
  if (the_minute < 0 || the_minute > 59)
    {
      cout << "Error 2nd illegal input to read_minute\n";
      exit(1);
    }
}

void read_hour(istream& ins, int& the_hour)
{
  char c1, c2;
  ins >> c1 >> c2;
  if(!(isdigit(c1) && (isdigit(c2) || c2 == ':')))
    {
      cout << "Error illegal input to read_hour\n";
      exit(1);
    }
  if (isdigit(c1) && c2 == ':')
    {
      // Then there is a single-digit hour.
      the_hour = digit_to_int(c1);
    }
  else
    {
      // Then hour is double-digit. Assign the_hour accordingly.
      the_hour = (digit_to_int(c1) * 10) + digit_to_int(c2);
      // Discard the ':' after the HH.
      ins >> c2;
      if (c2 != ':')
	{
	  cout << "Error 2nd illegal input to read_hour\n";
	  exit(1);
	}
    }
      if (the_hour < 0 || the_hour > 23)
	{
	  cout << "Error 3rd illegal input to read_hour\n";
	  exit(1);
	}
}
