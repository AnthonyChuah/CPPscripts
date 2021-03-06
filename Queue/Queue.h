// Header interface file for Queue class.
#ifndef QUEUE_H
#define QUEUE_H
namespace queueanton
{
  struct QueueNode
  {
    char data;
    QueueNode *link;
  };
  typedef QueueNode* QueueNodePtr;

  class Queue
  {
  public:
    // Constructor with no arguments.
    Queue();
    // Copy constructor.
    Queue(const Queue& aQueue);
    // Destructor.
    ~Queue();
    // Add item to the queue.
    void add(char item);
    // Remove item at front of queue and returns it.
    // Queue must not be empty.
    char remove();
    // Returns true if queue empty.
    bool empty() const;
  private:
    QueueNodePtr front;
    QueueNodePtr back;
  };
} // End of namespace queueanton
#endif // QUEUE_H
