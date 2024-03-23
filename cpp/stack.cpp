#include <iostream>
#include <vector>

// NOTE: Still need to implement a way to not allow users to overindex the stack

struct Stack {
  int size;
  int *data;
  int n = 0;

  Stack(int N, std::vector<int> v = {}) {
    size = N;
    data = new int[size];
    for (int i = 0; i < v.size(); ++i) {
      data[i] = v[i];
    }
    n = v.size();
  }

  ~Stack() { delete[] data; }

  int pop() {
    n--;
    return data[n];
  }

  void push(int x) {
    n++;
    data[n - 1] = x;
  }
};

std::ostream &operator<<(std::ostream &out, Stack &s) {
  out << "Stack: " << '[';
  if (s.n > 0)
    out << s.data[0] << ", ";
  for (int i = 1; i < s.n - 1; ++i) {
    out << s.data[i] << ", ";
  }
  out << s.data[s.n - 1] << ']';
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
