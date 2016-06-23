// Program simulates Conway's Game Of Life.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

const int WIDTH = 75;
const int HEIGHT = 25;

void initialize_world(int world[HEIGHT][WIDTH]);
void print_world(int world[HEIGHT][WIDTH]);

// Generates a random initial world.
void initialize_world(int inworld[HEIGHT][WIDTH])
{
  using namespace std;
  double randomvalue;
  for (int row = 0; row < HEIGHT; row++)
    {
      for (int col = 0; col < WIDTH; col++)
	{
	  randomvalue = ((double) rand() / RAND_MAX);
	  if (randomvalue > 0.8)
	    {
	      inworld[row][col] = 1;
	    }
	}
    }
  return;
}

void print_world(int inworld[HEIGHT][WIDTH])
{
  using namespace std;
  cout << endl;
  for (int row = 0; row < HEIGHT; row++)
    {
      for (int col = 0; col < WIDTH; col++)
	{
	  if (inworld[row][col] > 0)
	    {
	      cout << 'X';
	    }
	  else
	    {
	      cout << ' ';
	    }
	}
      cout << endl;
    }
  return;
}

int main()
{
  using namespace std;
  int iterations = 10;
  int world[HEIGHT][WIDTH] = {0};
  cout << "Welcome to Conway's Game of Life." << endl
       << "The world is a grid with 25 rows and 75 cols." << endl
       << "Each cell is alive or dead." << endl
       << "We randomly initialize the world." << endl
       << "For each cell, if it has 0, 1, or >3 alive neighbours," << endl
       << "it will die." << endl
       << "If a dead cell has 3 neighbours, it will become alive." << endl << endl
       << "This is the initialization of the world:" << endl;
  Sleep(1000);
  initialize_world(world);
  print_world(world);
  
  return 0;
}
