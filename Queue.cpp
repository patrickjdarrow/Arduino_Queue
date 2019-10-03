#include "Arduino.h"
#include "Queue.h"

Queue::Queue()
//Queue<T>::Queue()
{
    nodePtr head = nullptr;
    nodePtr tail = nullptr;
    nodePtr curr = nullptr;
    nodePtr temp = nullptr;

    counter = 0;
}

template <typename T>
void Queue::push(T data)
//void Queue<T>::push(T data)
{
  if (head == nullptr)
  {
    head = new node;
    head->data = data;
    tail = head;
  }
  else
  {
    temp = head;
    head = new node;
    head->data = data;
    head->next = temp;    
  }
  counter ++;
}

template <typename T>
T& Queue::peek()
//T& Queue<T>::peek()
{
  if (head == nullptr)
  {
    return 0;
  }
  return head->data;
   
}

template <typename T>
T Queue::pop()
//T Queue<T>::pop()
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
  return data;
}

template <typename T>
int Queue::size()
//int Queue<T>::size()
{
  return counter;
}

template <typename T>
bool Queue::isEmpty()
//bool Queue<T>::isEmpty()
{
  if (counter ==0)
  {
    return true;
  }
  return false;
}

template <typename T>
void Queue::clear()
//void Queue<T>::clear()
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
  return;
}


