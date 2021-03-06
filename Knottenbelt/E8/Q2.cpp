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
void add_after(NodePtr &list, char a_word[], char after_this_word[]);
/* Function to delete a node from the linked list */
void delete_node(NodePtr &list, char word_to_delete[]);
/* Function to compare strings by alphabetical bigness i.e. lexicographical ordering */
bool compare_bigness_strings(char first[], char second[]);
/* Function to sort the nodes in the linked list according to alphabetical bigness */
void list_selection_sort(NodePtr &list);
// Recursive version of function printing list contents.
void print_fwd_recurse(NodePtr head);
// Recursive version of function printing list contents backwards.
void print_bck_recurse(NodePtr head);

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
  add_after(my_list, word_to_add, after_this);
  cout << "\nThe list is now:\n";
  print_list(my_list);
  char word_to_delete[MAX_WORD_LENGTH];
  cout << "\nWhich word would you like to delete? ";
  cin >> word_to_delete;
  delete_node(my_list, word_to_delete);
  print_list(my_list);
  cout << "\nType anything to continue:";
  cin >> word_to_delete;
  cout << "Using list_selection_sort:\n";
  list_selection_sort(my_list);
  print_list(my_list);
  cout << "\nUsing print_fwd_recurse:\n";
  print_fwd_recurse(my_list);
  cout << "\nUsing print_bck_recurse:\n";
  print_bck_recurse(my_list);
  cout << "\nUsing print_bck:\n";
  print_bck(my_list);
  return 0;
}
	
void assign_list(NodePtr &a_list)
{
  NodePtr current_node, last_node;
  // Creates new node on heap. Did nothing else.
  assign_new_node(a_list);
  cout << "Enter first word (or '.' to end list): ";
  cin >> a_list->word;
  // The inputted node pointer's Node contains the first word.
  if (!strcmp(".",a_list->word))
    {
      delete a_list;
      a_list = NULL;
    }
  // If the first word was '.', delete the new node.
  current_node = a_list;
  // Set current_node NodePtr to the inputted node pointer.
  // See how if current_node is NULL, nothing will happen:
  while (current_node != NULL)
    {
      // current_node is pointing at the inputted node pointer's contents.
      assign_new_node(last_node);
      // Assign new node simply makes new node on heap. Does nothing else.
      // Now last_node points to the new node on the heap.
      cout << "Enter next word (or '.' to end list): ";
      cin >> last_node->word;
      // Write the word into the new node on the heap.
      if (!strcmp(".",last_node->word))
	{
	  delete last_node;
	  last_node = NULL;
	}
      // If the new word is '.', simply delete the new node.
      current_node->next = last_node;
      // Current_node is pointing at inputted node pointer's contents. Its ->next attribute is
      // now set to point to the new node on the heap.
      current_node = last_node;
      // Now move the current_node (like incrementing along ->next) to the next node.
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

void add_after(NodePtr &list, char a_word[], char after_this_word[])
{
  // a_word is the word we want to add.
  // word_after is the marker after which we want to add.
  if (list == NULL)
    {
      // List is empty. Do nothing and return.
      return;
    }
  // I need a moving node that traverses the links in the node. Call it traverser_nodeptr.
  NodePtr traverser_nodeptr = list, next_node, inserted_node;
  while (traverser_nodeptr != NULL)
    {
      if (!strcmp(after_this_word,traverser_nodeptr->word))
	{
	  // Record the address of the next node. I'll need it later.
	  next_node = traverser_nodeptr->next;
	  assign_new_node(inserted_node); // inserted_node points to new node on heap.
	  inserted_node->next = next_node; // Make sure the new node points to the next node.
	  strcpy(inserted_node->word, a_word); // Copy the word.
	  traverser_nodeptr->next = inserted_node; // Make sure traverser points to new node.
	  break; // Only do one insertion in linked list for the first match.
	}
      traverser_nodeptr = traverser_nodeptr->next;
    }
}

void delete_node(NodePtr &list, char word_to_delete[])
{
  // Strategy:
  // First verify that the linked list is not empty. If empty, do nothing.
  // Then check for special case: single node linked list.
  // Else: traverse the nodes of the linked list.
  // The moment you find a match !strcmp(word_to_delete, traverser->word):
  if (list == NULL)
    return;
  // Set the traverser to the inputted node pointer address.
  NodePtr traverser = list, prev_node = NULL;
  if (!strcmp(word_to_delete, list->word))
    {
      // Record the address of the node to delete.
      prev_node = list;
      // Move the inputted node ptr to the next in the linked list.
      list = list->next;
      // Now remove the actual data from the heap corresp. to prev_node.
      delete prev_node;
      // Set prev_node to the null pointer so you don't access a lost of the heap.
      prev_node = NULL;
    }
  else
    {
      while (traverser != NULL)
	{
	  if (!strcmp(word_to_delete, traverser->word))
	    {
	      // Once we find the match, make previous node point to next node.
	      prev_node->next = traverser->next;
	      delete traverser;
	      break;
	    }
	  prev_node = traverser;
	  traverser = traverser->next;
	}
    }
}

bool compare_bigness_strings(char first[], char second[])
{
  char* j = second;
  for (char* i = first; true; i++)
    {
      if (static_cast<int>(*i) < static_cast<int>(*j))
	return true;
      else if (static_cast<int>(*i) > static_cast<int>(*j))
	return false;
      else if (*i == '\0')
	return false;
      else
	j++;
      continue;
    }
  return false;
}

void list_selection_sort(NodePtr &list)
{
  // Strategy:
  // Imagine you have two iterators, just like the i and j in for-loop method.
  // First iterator crawls over the list, like the outer loop i iteration.
  // Let's call it outer_iter.
  // Second iterator crawls over the sublist AFTER wherever the first iterator was.
  // Let's call it inner_iter.
  // Finally, a pointer which acts as a flag called inner_minfinder.
  // This pointer tells you which element is the smallest to the right of the first iterator.
  // Using compare_bigness_strings, we can do lexicographical ordering comparisons.
  NodePtr outer_iter;
  NodePtr inner_iter;
  NodePtr inner_minfinder;
  // Start traversing the list:
  for (outer_iter = list; outer_iter->next != NULL; outer_iter = outer_iter->next)
    {
      // Initialize inner iterator on the same address as outer iterator.
      inner_minfinder = outer_iter;
      for (inner_iter = outer_iter; inner_iter != NULL; inner_iter = inner_iter->next)
	{
	  if (compare_bigness_strings(inner_iter->word, inner_minfinder->word))
	    {
	      // This will find the node with the "smallest" word.
	      inner_minfinder = inner_iter;
	    }
	}
      // Now swap the words at outer_iter and inner_minfinder.
      char temp[80];
      strcpy(temp, inner_minfinder->word);
      strcpy(inner_minfinder->word, outer_iter->word);
      strcpy(outer_iter->word, temp);
    }
}

void print_fwd_recurse(NodePtr head)
{
  if (head == NULL)
    return;
  cout << head->word << " ";
  print_fwd_recurse(head->next);
}

void print_bck_recurse(NodePtr head)
{
  if (head == NULL)
    return;
  print_bck_recurse(head->next);
  cout << head->word << " ";
}
