/* Program 7.5.1 from C++ Programming Lecture notes  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 28th September 2013    */

/* Modifications: Anthony Chuah October 2016 */

/* This program creates and prints out a linked list of strings. */ 

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;

/* definition of a node */
struct Node;
// typedef Node *Node_ptr;
typedef Node* NodePtr;

struct Node
{
  char word[MAX_WORD_LENGTH];
  NodePtr next;
  // Node_ptr ptr_to_next_node;
};

/* Function to assign a linked list to "a_node" */
void assign_list(NodePtr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(NodePtr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(NodePtr a_node);

/* Function to add a new node after a node with a string match */
void add_after(NodePtr &list, char a_word[], char word_after[]);

/* Function to delete a node from the linked list */
void delete_node(NodePtr &list, char a_word[]);

/* Function to sort the nodes in the linked list according to alphabetical bigness */
void list_selection_sort(NodePtr &list);

int main()
{
  NodePtr my_list = NULL;
  assign_list(my_list);
  cout << "\nTHE LIST IS NOW:\n";
  print_list(my_list);
  char after_this[MAX_WORD_LENGTH], word_to_add[MAX_WORD_LENGTH];
  cout << "\nAfter which word would you like to add an extra word? ";
  cin >> after_this;
  cout << "Which word would you like to add? ";
  cin >> word_to_add;
  cout << "\nThe list is now:\n";
  print_list(my_list);
  char word_to_delete[MAX_WORD_LENGTH];
  cout << "Which word would you like to delete? ";
  cin >> word_to_delete;
  delete_node(my_list, word_to_delete);
  print_list(my_list);
  list_selection_sort(my_list);
  print_list(my_list);
  return 0;
}
	
void assign_list(NodePtr &a_list)
{
  NodePtr current_node, last_node;

  assign_new_node(a_list);
  cout << "Enter first word (or '.' to end list): ";
  cin >> a_list->word;
  if (!strcmp(".",a_list->word))
    {
      delete a_list;
      a_list = NULL;
    }
  current_node = a_list;

  while (current_node != NULL)
    {
      assign_new_node(last_node);
      cout << "Enter next word (or '.' to end list): ";
      cin >> last_node->word;
      if (!strcmp(".",last_node->word))
	{
	  delete last_node;
	  last_node = NULL;
	}
      current_node->next = last_node;
      current_node = last_node;
    }
}

void assign_new_node(NodePtr &a_node)
{
  a_node = new (nothrow) Node;
  if (a_node == NULL) 
    {
      cout << "Sorry - no more memory\n"; 
      exit(1);
    }
}

void print_list(NodePtr a_node)
{
  while (a_node != NULL)
    {
      cout << a_node->word << " ";
      a_node = a_node->next;
    }
}
