// Header file for IntegerArray.

#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H
using namespace std;

void input_array(int a[], int n);
// Allows user to input values for the first n elements of the array a.
void display_array(int a[], int n);
// Displays the values of the first n elements of a[] to cout.
void copy_array(int target[], int source[], int n);
// Copies first n elements of source[] to target[].
double standard_deviation(int a[], int n);
// Returns stddev of the first n elements of a.

#endif
