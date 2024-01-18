#include<iostream>
#include "stack.h"
using namespace std;
template <class T>
T stack<T>::at_top()
{
    return top->data;
}
template <class T>
void stack<T>::push(T item)
{
    node <T>*temp = new node<T>();
    if(top==NULL)
    {
        temp->next=NULL;
        temp->data=item;
        top=temp;
    }
    else
    {
        temp->next=NULL;
        temp->data=item;
        temp->next=top;
        top=temp;
    }
}
template <class T>
bool stack<T>::is_empty()
{
    if(top==NULL)
    return true;
    else 
    return false;
}
template <class T>
void stack<T>::pop()
{
    if(!is_empty())
    {
        node <T>*temp=top;
        top=top->next;
        delete temp;
    }
}