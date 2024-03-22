#include <iostream>
#include <ostream>
#include <vector>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head = nullptr;

  List(std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
      push_front(v[i]);
    }
  }

  ~List() {
    while (head != nullptr) {
      Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void push_front(int data) {
    if (head == nullptr) {
      head = new Node{data, nullptr};
      return;
    }

    Node *n = new Node{data, nullptr};
    n->next = head;
    head = n;
  }

  void push_back(int data) {
    if (head == nullptr) {
      head = new Node{data, nullptr};
      return;
    }
    Node *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = new Node{data, nullptr};
  }
};

std::ostream &operator<<(std::ostream &out, List &l) {
  Node *cur = l.head;
  while (cur != nullptr) {
    out << cur->data << ' ';
    cur = cur->next;
  }
  return out;
}

int main(void) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  List l(v);
  std::cout << l << '\n';

  return 0;
}
