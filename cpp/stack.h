#include <iostream>
#include <ostream>
#include <vector>

struct Stack {
  int size;
  int *data;
  int n = 0;

  Stack(int N = 0, std::vector<int> v = {}) {
    size = N;
    data = new int[size];
    for (int i = 0; i < v.size(); ++i) {
      data[i] = v[i];
    }
    n = v.size();
  }

  ~Stack() { delete[] data; }

  void resize() {
    if (n < size / 2)
      size = size / 2;
    if (n == size)
      size = 2 * size;
    int *tmp = new int[size];
    std::copy(data, data + size, tmp);
    delete[] data;
    data = tmp;
  }

  int pop() {
    n--;
    resize();
    return data[n];
  }

  void push(int x) {
    n++;
    resize();
    data[n - 1] = x;
  }

  int get(int i) {
    if (0 <= i && i < n)
      return data[i];
    return 0;
  }
};

std::ostream &operator<<(std::ostream &out, Stack &s) {
  out << "Stack: " << '[';
  if (s.n > 0)
    out << s.get(0) << ", ";
  for (int i = 1; i < s.n - 1; ++i) {
    out << s.get(i) << ", ";
  }
  out << s.get(s.n - 1) << ']';
  return out;
}

int main(void) {
  std::vector<int> v = {1, 2, 3, 4};
  Stack s(10, v);
  std::cout << s << '\n';
  std::cout << s.pop() << '\n';
  std::cout << s << '\n';
  s.push(10);
  std::cout << s << '\n';
  return 0;
}
