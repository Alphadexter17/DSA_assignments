#ifndef start
#define start
#include<iostream>
using namespace std;
template <class T>
class stack;
template <class T>
class node{
    public:
    T data;
    node <T>*next;
    node()
    {
        data=0;
        next=NULL;
    }
};
template <class T>
class stack{
    public:
    node <T>*top=NULL;
    T at_top();
    void pop();
    void push(T item);
    bool is_empty();
};
#endif