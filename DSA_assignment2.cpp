#include<iostream>
using namespace std;
class node{
public:
   node *next;
   int data;
};
class stack{
public:
       node *top=NULL;
       void push(int item);
       void display();
       int empty();
       void pop();
};
int  stack::empty()
{
  if(top==NULL)
  return 1;
  else 
  return 0;
}
void stack::push(int item)
{
  node *New;
  New=new node;
  New->data=item;
  New->next=top;
  top=New;
}
void stack::display()
{
  node *temp=top;
  if(empty())
  cout<<"Stack is empty";
  else
  {
  empty();
  while(temp!=NULL)
  {
   cout<<endl<<temp->data<<" ";
   temp=temp->next;
  }
  }
}
void stack::pop()
{
    int item;
    node *temp;
    if(empty())
    cout<<"Stack is empty"<<endl;
    else
    {
       item=top->data;
       temp=top;
       top=top->next;
       delete temp;
       cout<<"The item which is deleted is"<<item<<endl;
    }
}
int main()
{
   stack obj1;
   int choice;
   int item;
   while(true)
   {
      cout<<"\n1.Add an element in the stack\n2.Display the elements in stack\n3.Delete the element in the stack\n4.EXIT \n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice)
      {
        case 1:
        cout<<"Enter the number which you want to push in the stack: ";
        cin>>item;
        obj1.push(item);
        break;
        case 2:
        obj1.display();
        break;
        case 3:
        obj1.pop();
        break;    
      }
      if(choice==4)
      {
        cout<<"You have exited the programm";
        break;
      }
   }
   return 0;
}