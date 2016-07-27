// Header file for Node.h.
namespace LinkedListClasses
{
  class Node
  {
  public:
    // Constructors.
    Node();
    Node(int value, Node *next);
    // Method to get the data for a given node.
    int getData() const;
    // Method to get the next node in the linked list.
    Node *getLink() const;
    // Method to modify value stored in the given node.
    void setData(int value);
    // Method to modify the node pointed to by this node's link attribute.
    void setLink(Node *next);
  private:
    int data;
    Node *link;
  };
  typedef Node* NodePtr;
}
