#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Temperature
{
public:
  void input_temp(double inputval, char inputunit);
  // Take number input and a character F C or K for temperature unit.
  // Complains loudly if input is not in the right format.
  void display_row();
  // Displays temperature in F, C, and K.
  // To be fancy I should make this take any ostream including a file stream
  // but I am lazy.
private:
  double temp_f;
  double temp_c;
  double temp_k;
};

void Temperature::input_temp(double inputval, char inputunit)
{
  switch(inputunit)
    {
    case 'F':
      temp_f = inputval;
      temp_c = (inputval - 32) * (5.0/9.0);
      temp_k = temp_c + 273.15;
      break;
    case 'C':
      cout << "Programmer did not implement this case. Pay him more!\n";
      exit(1);
      break;
    case 'K':
      cout << "Programmer did not implement this case. Pay him more!\n";
      exit(1);
      break;
    default:
      cout << "You must enter ONLY 'F', 'C', or 'K'. Get out of here!\n";
      exit(1);
    }
}

void Temperature::display_row()
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.setf(ios::left);
  cout.precision(2);
  cout.width(15);
  cout << temp_f << setw(15) << temp_c
       << setw(15) << temp_k << '\n';
}

int main()
{
  cout << "Welcome to the Temperature Table.\n";
  cout << "Displaying F, C, and K temperatures in increments of 20F:\n\n";
  cout << "Fahrenheit     Celsius        Absolute Value \n\n";
  Temperature temp;
  for (int i = 0; i <= 300; i += 20)
    {
      temp.input_temp(i, 'F');
      temp.display_row();
    }
  cout << "\nFigure 1.Balls: Temperature Table\n";
  return 0;
}
