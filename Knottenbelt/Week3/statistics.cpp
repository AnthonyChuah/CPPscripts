// Implementation file.
#include "statistics.h"

get_input(double& input_array)
{
  
}
get_average(double input_array[], int size)
{
  double cumsum;
  for (int i = 0; i <= size; i++)
    cumsum += input_array[i];
  return (cumsum/size);
}

get_stdev(double input_array[], int size)
{
  double average_value;
  average_value = get_average(input_array, size);
  // Then write formula for calculating stdev.
  double result;
  return result;
}
