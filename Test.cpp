#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> v;
  cout << "Enter a list of positive numbers.\n"
       << "Place a negative number at the end.\n";
  int next;
  cin >> next;
  while (next > 0)
    {
      v.push_back(next);
      cout << next << " has been added. ";
      cout << "Vector size is: " << v.size() << endl;
      cin >> next;
    }
  cout << "You entered:\n";
  for (unsigned int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
  return 0;
}
