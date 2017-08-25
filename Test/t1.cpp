#include <iostream>

class Parent {
public:
  virtual void print() { std::cout << "I am a parent\n"; }
};
class Child : public Parent {
public:
  virtual void print() { std::cout << "I am a child\n"; }
};

int main() {
  int a = 10;
  int* p = new int(1000);
  int& ref = a;

  std::cout << "Values of a p and ref: " << a << " " << *p << " " << ref << "\n";

  // Modify ref, check if a changed.
  ++ref;
  std::cout << "a and ref: " << a << " " << ref << "\n";

  // Implicit subclass to parent class pointer conversion
  Parent* parentP = new Child();
  parentP->print();
  Child* childP = static_cast<Child*>(parentP);
  childP->print();
  Parent* parentP1 = new Parent();
  parentP1->print();

  Child child = Child();
  parentP = &child;
  (*parentP).print();
  parentP = parentP1;
  parentP->print();
  child.print();
  
  return 0;
}
