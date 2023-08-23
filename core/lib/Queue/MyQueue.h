#pragma once

class MyQueue {
public:
    explicit MyQueue(int capacity);
    ~MyQueue();
    void Enqueue(const int& element);
    int* Dequeue();
    const int& size() const;
    const int& capacity() const;
private:
    int* _data{ nullptr };
    int _capacity { 0 }, _size { 0 }; 
};