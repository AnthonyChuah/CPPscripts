// Program simulates Conway's Game Of Life.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <algorithm>

const int WIDTH = 75;
const int HEIGHT = 25;

int count_neighbours(int inworld[HEIGHT][WIDTH], int row, int col);
void initialize_world(int world[HEIGHT][WIDTH]);
void print_world(int world[HEIGHT][WIDTH]);
void copy_array(int world[HEIGHT][WIDTH], int new_world[HEIGHT][WIDTH]);
void tick(int inworld[HEIGHT][WIDTH]);

// Generates a random initial world.
void initialize_world(int world[HEIGHT][WIDTH])
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
	      world[row][col] = 1;
	    }
	}
    }
  return;
}

void print_world(int world[HEIGHT][WIDTH])
{
  using namespace std;
  cout << endl;
  for (int row = 0; row < HEIGHT; row++)
    {
      for (int col = 0; col < WIDTH; col++)
	{
	  if (world[row][col] > 0)
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

int count_neighbours(int world[HEIGHT][WIDTH], int row, int col)
{
  using namespace std;
  // Function should check a cell, and then count number of live neighbours.
  int counter = 0;
  for (int i = max(0,row-1); i <= min(HEIGHT,row+1); i++)
    for (int j = max(0,col-1); j <= min(WIDTH,col+1); j++)
      {
	if (i == row && j == col)
	  continue;
	else
	  counter += world[i][j];
      }
  return counter;
}

void copy_array(int world[HEIGHT][WIDTH], int new_world[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
    for (int j = 0; j < WIDTH; j++)
      world[i][j] = new_world[i][j];
  return;
}

void tick(int world[HEIGHT][WIDTH])
{
  using namespace std;
  int new_world[HEIGHT][WIDTH] = {0};
  for (int row = 0; row < HEIGHT; row++)
    for (int col = 0; col < WIDTH; col++)
      {
	int neighbours = 0;
	neighbours = count_neighbours(world, row, col);
	if (neighbours <= 1)
	  new_world[row][col] = 0;
	else if (neighbours > 3)
	  new_world[row][col] = 0;
	else if (neighbours == 3)
	  new_world[row][col] = 1;
	else
	  continue;
      }
  copy_array(world, new_world);
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
  Sleep(500);
  for (int iteration = 1; iteration <= iterations; iteration++)
    {
      cout << "Doing world iteration number " << iteration << endl;
      Sleep(500);
      tick(world);
      print_world(world);
      Sleep(500);
    }
  cout << "Finished all iterations. Enter anything to exit." << endl;
  cin >> iterations;
  return 0;
}
