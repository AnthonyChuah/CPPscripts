#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  clock_t begin = clock();
  
  for (int i = 2; i < 9000; i++)
    {
      int sum = 0;
      for (int j = 1; j <= i/2; j++)
	{
	  if (i % j == 0)
	    {
	      sum += j;
	    }
	}
      if (sum == i)
	{}
    }

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "Elapsed time is: " << elapsed_secs << endl;
  return 0;
}
