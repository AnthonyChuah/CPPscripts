// Binary search using iterative instead of recursive function.
void search(const int a[], int low_end, int high_end,
	    int key, bool& found, int& location);

void search(const int a[], int low_end, int high_end,
	    int key, bool& found, int& location)
{
  int first = low_end;
  int last = high_end;
  int mid;
  found = false;
  while ((first <= last) && !(found))
    {
      mid = (first + last)/2;
      if (key == a[mid])
	{
	  found = true;
	  location = mid;
	}
      else if (key < a[mid])
	last = mid - 1;
      else if (key > a[mid])
	first = mid + 1;
    }
}
