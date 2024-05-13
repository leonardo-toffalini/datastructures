#include <iostream>
#include <ostream>

struct Queue {
  int size;
  int *data;
  int start;
  int end;

  Queue(int size = 0) {
    this->size = size;
    data = new int[size];
    start = 0;
    end = -1;
  }

  ~Queue() { delete[] data; }

  void resize() { return; }

  void push_front(int x) {
    start--;
    resize();
    data[start % size] = x;
  }

  void push_back(int x) {
    end++;
    resize();
    data[end % size] = x;
  }

  int pop_left() {
    start++;
    resize();
    return data[(start - 1) % size];
  }

  int pop_right() {
    end--;
    resize();
    return data[(end + 1) % size];
  }

  bool is_empty() { return start == end; }
};

std::ostream &operator<<(std::ostream &out, Queue q) {
  while (!q.is_empty()) {
    out << q.pop_left() << ' ';
  }
  return out;
}

int main(void) {
  Queue q;
  return 0;
}
