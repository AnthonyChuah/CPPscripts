// Program demonstrates Node class.
#include <iostream>
#include "Node.h"
using namespace std;
using namespace LinkedListClasses;

// Function inserts new node into head of the list.
void head_insert(NodePtr& head, int the_number)
{
  NodePtr temp_ptr;
  temp_ptr = new Node(the_number, head);
  head = temp_ptr;
}

int main()
{
  NodePtr head, tmp;
  // Create a list of nodes 4 -> 3 -> 2 -> 1 -> 0.
  head = new Node(0, NULL);
  for (int i = 1; i < 5; i++)
    head_insert(head,i);
  // Iterate through list and display each value.
  // tmp is the iterator.
  tmp = head;
  while (tmp != NULL)
    {
      cout << tmp->getData() << endl;
      tmp = tmp->getLink();
    }
  // Delete all nodes in the list before exiting the program.
  tmp = head;
  while (tmp != NULL)
    {
      NodePtr nodeToDelete = tmp;
      tmp = tmp->getLink();
      delete nodeToDelete;
    }
  return 0;
}
