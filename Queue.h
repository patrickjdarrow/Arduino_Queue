#ifndef Queue_h
#define Queue_h

#include "Arduino.h"


template <typename T>
class Queue
{
    public:

        typedef struct node
        {
          T data;
          node * next = nullptr;
        } * nodePtr;

        nodePtr head = nullptr;
        nodePtr tail = nullptr;
        nodePtr curr = nullptr;
        nodePtr temp = nullptr;

        uint16_t counter;
        T sum;

        Queue();
        void push(T);
        T& peek();
        T pop();
        int size();
        bool isEmpty();
        void clear();
};

template <typename T>
Queue<T>::Queue()
{
    // Constructor
}

template <typename T>
void Queue<T>::push(T data)
{
    // Empty
    if (head == nullptr)
    {
        head = new node;
        head->data = data;
        tail = head;
    }
    // Populated
    else
    {
        temp = head;
        head = new node;
        head->data = data;
        head->next = temp;    
    }
    counter ++;
    sum += data;
}

template <typename T>
T& Queue<T>::peek()
{
  if (head == nullptr)
  {
    return 0;
  }
  return head->data;
   
}

template <typename T>
T Queue<T>::pop()
{
  // Empty
  if (head == nullptr)
  {
    return 0;
  }

  // Head = tail
  if (head == tail)
  {
    T data = head->data;
    delete head;
    counter = 0;
    sum -= data;
    return data;
  }

  // Size > 1
  curr = head;
  while (curr->next != tail)
  {
    curr = curr->next;
  }
  T data = curr->next->data;  
  tail = curr;
  curr = curr->next;
  delete curr;
  counter --;
  sum -= data;
  return data;
}

template <typename T>
int Queue<T>::size()
{
  return counter;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  if (counter == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
void Queue<T>::clear()
{
  while (head->data != nullptr)
  {
    temp = head->next;
    delete head;
    head = temp;    
  }
  if (head == nullptr)
  {
    return;
  }
  delete head;
  counter = 0;
  sum = 0;
  return;
}



#endif