// APPLICATION file timedemo.cpp.
#include <iostream>
#include "dtime.h"
using namespace std;

int main()
{
  DigitalTime clock, old_clock;
  cout << "Enter time in HH:MM format: ";
  cin >> clock;
  old_clock = clock;
  clock.advance(15);
  if (clock == old_clock)
    cout << "Digitaltime.advance() method failed to advance time.\n";
  cout << "You entered " << old_clock << endl;
  cout << "15 minutes later the time will be "
       << clock << endl;
  clock.advance(2,15);
  cout << "On top of that, 2 hours and 15 minutes later \n"
       << "the time will be " << clock << endl;
  return 0;
}
