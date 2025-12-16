#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// use all of vector's already existing functions and operations to implement the needed methods for Stack

template <typename T> 
Stack<T>::Stack() : std::vector<T>() {}

template <typename T> 
Stack<T>::~Stack() {}

template <typename T> 
bool Stack<T>::empty() const {
    return std::vector<T>::empty();
}

template <typename T> 
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

template <typename T> 
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item);
}
// throw underflow_error if Stack is empty
template <typename T> 
void Stack<T>::pop() {
    if (std::vector<T>::empty()) {
        throw std::underflow_error("Stack is empty: can't pop");
    }
    std::vector<T>::pop_back();
}
// throw underflow_error if Stack is empty
// return back() of vector since we want to get the item that was most recently added (this would be the top of the stack)
template <typename T> 
const T& Stack<T>::top() const {
    if (std::vector<T>::empty()) {
        throw std::underflow_error("Stack is empty: can't access top");
    }
    return std::vector<T>::back();
}


#endif