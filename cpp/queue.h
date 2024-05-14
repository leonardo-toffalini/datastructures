#include <iostream>
#include <ostream>

template <typename T>
class Queue {
 private:
  int capacity = 0;
  T *_data = new T[capacity];
  int start = 0;
  int end = 0;

  void free() { delete[] _data; }

 public:
  Queue() = default;

  ~Queue() { free(); }

  int size() { return end - start; }

  void reserve(int n);

  void resize();

  void push_front(T x);
  void push_back(T x);

  T pop_left();
  T pop_right();

  bool is_empty() { return start == end; }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Queue<T> q) {
  while (!q.is_empty()) {
    out << q.pop_left() << ' ';
  }
  return out;
}

//-----------------------------------------------------------------//
//----------------------- IMPLEMENTATIONS -------------------------//
//-----------------------------------------------------------------//

template <typename T>
void Queue<T>::resize() {
  int oldCap = capacity;
  if (size() < capacity / 2)
    capacity = capacity / 2;

  if (size() == capacity)
    capacity *= 2;

  T *temp = new T[capacity];
  int a = _data + (start % oldCap);
  int b = _data + (end % oldCap);

  if (a < b)  // [....a---->b....]
    std::copy(a, b, temp);
  else {  // [--->b....a--->] // [---->b...
    std::copy(a, _data + oldCap, temp);
    std::copy(_data, b, temp + (start % oldCap));
  }

  delete[] _data;
  _data = temp;
}

template <typename T>
void Queue<T>::reserve(int n) {
  capacity = n;
  resize();
}

template <typename T>
void Queue<T>::push_front(T x) {
  start--;
  resize();
  _data[start % capacity] = x;
}

template <typename T>
void Queue<T>::push_back(T x) {
  end++;
  resize();
  _data[end % capacity] = x;
}

template <typename T>
T Queue<T>::pop_left() {
  T result = _data[start % capacity];
  start++;
  resize();
  return result;
}

template <typename T>
T Queue<T>::pop_right() {
  T result = _data[end % capacity];
  end--;
  resize();
  return result;
}
