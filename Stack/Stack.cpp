// Implementation file for stack class.
#include <iostream>
#include <cstddef>
#include "stack.h"
using namespace std;

namespace stackanton
{
  Stack::Stack() : top(NULL)
  {
    // Empty.
  }

  Stack::Stack(const Stack& astack)
  {
    // TARGET is our own object, SOURCE is the stack from which we COPY.
    // In case the stack you copy FROM is empty, return an empty stack.
    if (astack.top == NULL)
      top = NULL;
    else
      {
	// Source stack is not empty.
	// temp will move through nodes from top to bottom of stack.
	// temp is now initialized to the top node of the SOURCE stack.
	StackFramePtr temp = astack.top;
	// Points to the end of the new stack.
	StackFramePtr end;
	// Now declare a dynamic variable for end.
	end = new StackFrame;
	// Data of end should be equal to data of temp.
	// So right now we've duplicated the top node into end.
	end->data = temp->data;
	// Set the top of the target stack to end.
	top = end;
	// Now move temp down along the stack to the next node.
	// By setting temp to temp's link pointer.
	temp = temp->link;
	while (temp != NULL)
	  {
	    // Create a new node and point the link pointer to that node.
	    // This reserves memory on the heap for the next node of the TARGET.
	    end->link = new StackFrame;
	    // Set end to that pointed-to node.
	    // Basically now we've moved end to the new node.
	    // Remember that TARGET's previous node has already linked to the new node.
	    end = end->link;
	    // Now populate with the data that temp copied from end.
	    end->data = temp->data;
	    // Now move temp down the stack to the next node.
	    temp = temp->link;
	    // Now if we have reached the last node, temp will be NULL and the loop breaks.
	  }
	end->link = NULL;
      }
  }

  // Destructor.
  Stack::~Stack()
  {
    char next;
    while (!empty())
      {
	// Remember that pop() deletes the top node.
	next = pop();
      }
  }

  bool Stack::empty() const
  {
    return (top == NULL);
  }

  void Stack::push(char asymbol)
  {
    StackFramePtr temp_ptr;
    temp_ptr = new StackFrame;
    temp_ptr->data = asymbol;
    temp_ptr->link = top;
    top = temp_ptr;
  }

  char Stack::pop()
  {
    if (empty())
      {
	cout << "Error: popping an empty stack.\n";
	exit(1);
      }
    // Keep the result for returning later.
    char result = top->data;
    // Declare a new node pointer.
    StackFramePtr temp_ptr;
    // Point it to the top of the stack.
    temp_ptr = top;
    // Now move the top down by one node.
    top = top->link;
    // Now delete the top.
    delete temp_ptr;
    return result;
  }
} // End of namespace stackanton.
