struct Node
{
  int data;
  Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_data);
// head should be the top node of the linked list.
// the_data is the data you want to insert into the
// head of the linked list.
// Post-insertion: you should have a new head, with
// your new data, and the new head should point to the
// previous head. Everything else unchanged.
NodePtr search(NodePtr head, int target);
// search() should find the first instance of a node
// whose data attribute equals the target.
// It searches from the head and then keeps going down
// the links.
// Returns pointer to the relevant node.
void insert(NodePtr after_this_node, int the_data);
// Specify the node after which you wish to insert a new node.
// Specify the data the new node should contain.
// Post-insertion: after_this_node will point to the inserted node.
// Inserted node will point to the node that after_this_node used to point to.

void head_insert(NodePtr& head, int the_data)
{
  NodePtr temp_ptr;
  temp_ptr = new Node;
  // Remember struct Node has attributes:
  // int data, and Node *link.
  temp_ptr->data = the_data;
  temp_ptr->link = head;
  head = temp_ptr;
}

NodePtr search(NodePtr head, int target)
{
  NodePtr temp_ptr;
  temp_ptr = head;
  // Edge case: if the linked list is empty, return NULL.
  if (head == NULL)
    return NULL;
  else
    {
      while (temp_ptr->link != NULL && temp_ptr->data != target)
	temp_ptr = temp_ptr->link;
      if (temp_ptr->data == target)
	return temp_ptr;
      else
	return NULL;
    }
}

void insert(NodePtr after_this_node, int the_data)
{
  NodePtr temp_ptr;
  temp_ptr = new Node;
  // Assign the data first.
  temp_ptr->data = the_data;
  // First I must make the new temp_ptr point to the node
  // pointed to by after_this_node's link attribute.
  temp_ptr->link = after_this_node->link;
  // Then I must make the after_this_node point to this new node.
  after_this_node->link = temp_ptr;
}
