// Implementation file for Node class.
#include <iostream>
#include "Node.h"

namespace LinkedListClasses
{
  // Constructor with no arguments.
  Node::Node() : data(0), link(NULL)
  {
    // Empty.
  }

  Node::Node(int value, Node *next) : data(value), link(next)
  {
    // Empty.
  }

  int Node::getData() const
  {
    return data;
  }

  Node* Node::getLink() const
  {
    return link;
  }

  void Node::setData(int value)
  {
    data = value;
  }

  void Node::setLink(Node *next)
  {
    link = next;
  }
}
