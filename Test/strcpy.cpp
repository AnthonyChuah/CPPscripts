#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char song[10] = "I did it ";
  char franks_song[20];
  strcpy(franks_song, song);
  strcat(franks_song, "my way!");
  cout << franks_song << endl;
  return 0;
}
