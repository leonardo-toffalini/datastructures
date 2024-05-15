#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
 private:
  int capacity;
  T *_data;
  int _size = 0;

 public:
  Stack(T N, std::vector<T> v);

  ~Stack() { delete[] _data; }

  int size() { return _size; }

  void resize();
  T pop();
  void push(T x);
  T operator[](int i);
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Stack<T> &s) {
  out << "Stack: " << '[';
  if (s.size() > 0)
    out << s.get(0) << ", ";

  for (int i = 1; i < s.size() - 1; ++i) {
    out << s.get(i) << ", ";
  }
  out << s.get(s.size() - 1) << ']';
  return out;
}

template <typename T>
Stack<T>::Stack(T N, std::vector<T> v) {
  capacity = N;
  _data = new int[capacity];

  for (T i = 0; i < v.size(); ++i) {
    _data[i] = v[i];
  }
  _size = v.size();
}

template <typename T>
void Stack<T>::resize() {
  if (_size < capacity / 2)
    capacity = capacity / 2;
  if (_size == capacity)
    capacity = 2 * capacity;
  T *tmp = new T[capacity];
  std::copy(_data, _data + capacity, tmp);
  delete[] _data;
  _data = tmp;
}

template <typename T>
T Stack<T>::pop() {
  _size--;
  resize();
  return _data[_size];
}

template <typename T>
void Stack<T>::push(T x) {
  _size++;
  resize();
  _data[_size - 1] = x;
}

template <typename T>
T Stack<T>::operator[](int i) {
  if (0 <= i && i < _size)
    return _data[i];
  throw std::out_of_range("Got index out of range");
}
