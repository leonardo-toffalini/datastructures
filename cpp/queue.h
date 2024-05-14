#include <iostream>
#include <ostream>

template <typename T>
class Queue {
 private:
  int _size = 0;
  T *data = new T[_size];
  int start = 0;
  int end = 0;

  void free() { delete[] data; }

 public:
  Queue() = default;

  ~Queue() { free(); }

  int size() { return _size; }

  void reserve(int n);

  void resize() { return; }

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
void Queue<T>::reserve(int n) {
  _size = n;
  resize();
}

template <typename T>
void Queue<T>::push_front(T x) {
  start--;
  resize();
  data[start % _size] = x;
}

template <typename T>
void Queue<T>::push_back(T x) {
  end++;
  resize();
  data[end % _size] = x;
}

template <typename T>
T Queue<T>::pop_left() {
  T result = data[start % _size];
  start++;
  resize();
  return result;
}

template <typename T>
T Queue<T>::pop_right() {
  T result = data[end % _size];
  end--;
  resize();
  return result;
}
