//  Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include "iostream"

template <class T>
class MyStack{
 private:
     int max_length;
     int length = 0;
     T *arr;
     void expandArr(){
         this->max_length *= 2;
         T *tmp = new T[max_length];
         for (int i = 0; i < this->length; ++i) {
             tmp[i] = this->arr[i];
         }
         delete[] this->arr;
         this->arr = tmp;
     }
 public:
     explicit MyStack() {
         this->max_length = 2;
         this->arr = new T[this->max_length];
     }

     MyStack(const MyStack<T> &stack) {
         this->max_length = stack.max_length;
         this->length = stack.length;
         this->arr = new T[stack.max_length];
         for (int i = 0; i < stack.max_length; ++i) {
             this->arr[i] = stack.arr[i];
         }
     }

     ~MyStack() {
         delete[] this->arr;
     }

     T get() const {
         return this->arr[this->length-1];
     }

     T pop() {
         return this->arr[--this->length];
     }

     void push(T element) {
         if (this->length == this->max_length)
             this->expandArr();
         this->arr[this->length++] = element;
     }

     bool isFull() const {
         return this->length == this->max_length;
     }

     bool isEmpty() const {
         return this->length == 0;
     }

     int getLength() {
         return this->length;
     }

     int getMaxLength() {
         return this->max_length;
     }

     std::string to_string() const {
         std::string result;
         for (int i = 0; i < this->length; ++i) {
             result += "\"" + this->arr[i] + "\" ";
         }
         result[result.length()-1] = '\0';
         return result;
     }

     void printStack() const {
         std::cout << "Stack:" << std::endl;
         std::cout << '\"' <<this->to_string() << '\"';
         std::cout << "\n\n";
     }
};

#endif  // INCLUDE_MYSTACK_H_
