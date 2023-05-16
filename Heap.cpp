#include <iostream>
#include <math.h>

class Heap {
private:
  int *arr;
  int capacity, size;

public:
  Heap(int);
  ~Heap();
  void Search(int);
  void insert(int);
  int parent(int);
  void swap(int &, int &);
  void print();
  int height();
  int extract();
  int right(int);
  int left(int);
  void heapify(int);
  void deleteKey(int);
};

Heap::Heap(int cap) {
  capacity = cap;
  arr = new int[this->capacity];
  size = 0;
}

Heap::~Heap() { delete[] this->arr; }

void Heap::Search(int val) {
  for (size_t i = 0; i < size; i++) {
    if (arr[i] == val)
      std::cout << "found \n";
  }
  std::cout << "not found \n";
}

int Heap::parent(int val) { return (val - 1) / 2; }

void Heap::swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void Heap::insert(int val) {
  if (this->size >= this->capacity) {
    std::cout << "heap overflow \n";
    return;
  }
  int i = size++;
  this->arr[i] = val;
  int p = parent(i);
  std::cout << arr[p] << "\n";
  while (i != 0 && arr[parent(i)] > arr[i]) {
    swap(arr[parent(i)], arr[i]);
    i = parent(i);
  }
}

int Heap::height() { return ceil(log2(size + 1)) - 1; }

void Heap::print() {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << "  ";
  }
  std::cout << "\n";
}

int Heap::right(int root) { return (root * 2) + 2; }
int Heap::left(int root) { return (root * 2) + 1; }

int Heap::extract() {
  if (!size)
    return -1;
  else if (size == 1)
    return arr[--size];
  int root = arr[0];
  arr[0] = arr[--size];
  heapify(0);
  return root;
}

void Heap::heapify(int root) {
  int smallest = root;
  int R = right(root);
  int L = left(root);
  if (L < size && arr[L] < arr[smallest])
    smallest = L;
  if (R < size && arr[R] < arr[smallest])
    smallest = R;
  if (smallest != root) {
    swap(arr[smallest], arr[root]);
    heapify(smallest);
  }
}
void Heap::deleteKey(int key) {
  arr[key] = -1;
  while (key != 0 && arr[parent(key)] > arr[key]) {
    swap(arr[parent(key)], arr[key]);
    key = parent(key);
  }
  extract();
}

int main(int argc, char const *argv[]) {
  Heap Minheap(5);
  Minheap.insert(5);
  Minheap.insert(15);
  Minheap.insert(25);
  Minheap.insert(30);
  Minheap.insert(45);
  Minheap.print();
  Minheap.deleteKey(1);
  Minheap.print();

  return 0;
}
