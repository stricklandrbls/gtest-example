#include <Queue/MyQueue.h>

MyQueue::MyQueue(int capacity): _capacity{ capacity }, _size{ 0 }, _data{ new int[capacity] }{}
MyQueue::~MyQueue(){ delete[] _data; }

void MyQueue::Enqueue(const int& element) {
    _data[_size++] = element;
}
int* MyQueue::Dequeue() {
    return &(_data[--_size]);
}
const int& MyQueue::size() const { return _size; }
const int& MyQueue::capacity() const { return _capacity; }