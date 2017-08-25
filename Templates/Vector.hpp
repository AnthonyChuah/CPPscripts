/*
Implementation of Vector like STL's vector, using template metaprogramming techniques.
*/

const int VECTOR_DEFAULT_SIZE = 16;

template <typename T>
class Vector {
  T* array;
  int size;
  int reserved;
public:
  Vector() : size(0), reserved(VECTOR_DEFAULT_SIZE) {
    array = new T[VECTOR_DEFAULT_SIZE];
  }
  Vector(int n) : size(0), reserved(n) {
    array = new T[n];
  }
  ~Vector() {
    delete [] array;
  }
  void push_back(const T &pushed) {
    if (size == reserved) {
      resize(reserved * 2);
    }
    array[size] = pushed;
    ++size; // Prefix increment in case you use user-defined types, it is more efficient.
  }
};
