// Header interface file for stack class.
#ifndef STACK_H
#define STACK_H
namespace stackanton
{
  struct StackFrame
  {
    char data;
    StackFrame *link;
  };
  typedef StackFrame* StackFramePtr;

  class Stack
  {
  public:
    // Constructors.
    Stack();
    // Copy constructor.
    Stack(const Stack& astack);
    // Destructor.
    ~Stack();
    // Method for adding to stack.
    void push(char asymbol);
    // Method for removing from stack.
    // Returns the symbol on stack.
    void pop();
    // Method to check if stack is empty. Returns true if empty.
    bool empty() const;
  private:
    StackFramePtr top;
  };
};
#endif
