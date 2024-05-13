#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <ostream>
#include <vector>

template <typename T>
struct Node {
  T data;
  Node *next;
};

//-----------------------------------------------------------------//
//---------------------------- NODE -------------------------------//
//-----------------------------------------------------------------//

template <typename T>
class Iterator {
 private:
  Node<T> *ptr;

 public:
  Iterator(Node<T> *_ptr) : ptr(_ptr) {}

  // prefix++
  Iterator operator++();
  // postfix++
  Iterator operator++(int);

  bool operator==(Iterator other) { return ptr == other.ptr; }

  bool operator!=(Iterator other) { return !(*this == other); }

  T &operator*() { return ptr->data; }

  template <typename R>
  friend class ConstIterator;
};

template <typename T>
class ConstIterator {
 private:
  const Node<T> *ptr;

 public:
  ConstIterator(const Node<T> *_ptr) : ptr(_ptr) {}

  ConstIterator(Iterator<T> it) : ptr(it.ptr) {}

  // prefix++
  ConstIterator operator++();
  // postfix++
  ConstIterator operator++(int);

  bool operator==(ConstIterator other) { return ptr == other.ptr; }

  bool operator!=(ConstIterator other) { return !(*this == other); }

  const T &operator*() { return ptr->data; }
};

//-----------------------------------------------------------------//
//---------------------------- LIST -------------------------------//
//-----------------------------------------------------------------//

template <typename T>
class List {
 private:
  Node<T> *head = nullptr;

  void free();

 public:
  List() = default;
  List(const List &other);
  List(std::vector<T> &v);

  List &operator=(const List &other);

  ~List() { free(); }

  Iterator<T> begin() { return Iterator(head); }

  Iterator<T> end() { return Iterator(nullptr); }

  ConstIterator<T> begin() const { return ConstIterator(head); }

  ConstIterator<T> end() const { return ConstIterator(nullptr); }

  void push_front(int data);
  void push_back(int data);
};

template <typename T>
std::ostream &operator<<(std::ostream &out, List<T> &l) {
  Node<T> *cur = l.head;
  while (cur != nullptr) {
    out << cur->data << ' ';
    cur = cur->next;
  }
  return out;
}

//-----------------------------------------------------------------//
//----------------------- IMPLEMENTATIONS -------------------------//
//-----------------------------------------------------------------//

// prefix++
template <typename T>
Iterator<T> Iterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
  Iterator result = *this;
  ptr = ptr->next;
  return result;
}

// prefix++
template <typename T>
ConstIterator<T> ConstIterator<T>::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
  Iterator result = *this;
  ptr = ptr->next;
  return result;
}

template <typename T>
void List<T>::free() {
  while (head != nullptr) {
    Node<T> *tmp = head;
    head = head->next;
    delete tmp;
  }
}

template <class T>
List<T>::List(const List<T> &other) {
  Node<T> *ptr = other.head;
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

template <typename T>
List<T>::List(std::vector<T> &v) {
  for (T i = 0; i < v.size(); ++i) {
    push_front(v[i]);
  }
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &other) {
  if (this == &other)
    return *this;

  free();
  head = nullptr;

  Node<T> *ptr = other.head;
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

template <typename T>
void List<T>::push_front(int data) {
  if (head == nullptr) {
    head = new Node<T>{data, nullptr};
    return;
  }

  Node<T> *n = new Node<T>{data, nullptr};
  n->next = head;
  head = n;
}

template <typename T>
void List<T>::push_back(int data) {
  if (head == nullptr) {
    head = new Node<T>{data, nullptr};
    return;
  }
  Node<T> *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = new Node<T>{data, nullptr};
}

#endif  // !LINKED_LIST_H
