#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  clock_t begin = clock();
  int a[1000000];
  
  for (int i = 1; i <= 1000000; i++)
    {
      a[i] = i;
    }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "Elapsed time is: " << elapsed_secs << endl;
  return 0;
}
