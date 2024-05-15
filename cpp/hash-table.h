#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cmath>
#include "linked-list.h"

// template <typename T>
class HashTable {
 private:
  int capacity = 0;
  List<int> *buckets = new List<int>[capacity];
  void resize();

 public:
  HashTable() = default;

  ~HashTable() { delete[] buckets; }

  void insert(int key);
  void remove(int key);
};

inline int hash(int x) {
  x = 65539 * x;
  int m = std::pow(2, 31);
  return x % m;
}

inline void HashTable::insert(int key) {
  int index = hash(key) % capacity;
  buckets[index].push_back(key);
}

#endif  // !HASH_TABLE_H
