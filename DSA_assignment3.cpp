#include<iostream>
using namespace std;
class queue{
  private:
   int a[5];
   int front=-1;
   int rear=-1;
  public:
   void enque(int num);
   void deque();
   void display();
   void isfull();
   void isempty();
   void search();
};
void queue::display()
{
   if(rear>front)
   {
   for(int i=front;i<=rear;i++)
   {
     cout<<a[i]<<" ";
   }
   cout<<endl;
   }
   else
   {
   for(int i=front;i<5;i++)
   {
     cout<<a[i]<<" ";
   }
   cout<<a[rear]<<" ";
   cout<<endl;
   }
}
void queue::isempty()
{
   if(front==-1 && rear==-1)
     cout<<"It is empty"<<endl;
   else
   cout<<"It is not empty"<<endl;
}
void queue:: enque(int num)
{
    if(rear==-1)
    {
      rear++;
      front++;
      a[rear]=num;
    }
    else
    {
      rear=(rear+1)%5;
      a[rear]=num;
    }
}
void queue::isfull()
{
   if((rear+1)%5==front)
   {
    cout<<"Queue is full"<<endl;
   }
   else
   {
   cout<<"Queue is empty"<<endl;
   }
}
void queue:: deque()
{
  isempty();
  int x;
  if(front==rear)
  {
   x=a[rear];
    front=rear=-1;
   }
   else
   {
     x=a[front];
     front=(front+1)%5;
     cout<<"\nThe element which is dequed is: "<<x<<endl;
   }
}
void queue::search(){
     cout<<"Which number you want to find: ";
     int v;
     cin>>v;
     for(int i=front;i<=rear;i++)
     {
       if(v==a[i])
       {
         cout<<"Key is found at"<<i<<endl;
       }
       else
       {
          cout<<"Key not found\n";
       }
     }
}
int main()
{
  int n;
  queue q;
  int choice;
  int h=0;
  while(true)
  {
     cout<<"1.Enter the element in the queue\n";
     cout<<"2.Delete the element in the queue\n";
     cout<<"3.Display the elements in the queue\n";
     cout<<"4. Search an element in the queue\n";
     cout<<"5.Exit the operation\n";
     cin>>choice;
     switch(choice)
     {
        case 1:
        if(h<5)
        {
        cout<<"Which number you want to add in the queue: ";
        cin>>n;
        q.enque(n);
        h=h+1;
        }
        else
        cout<<"Maximum limit reached"<<endl;
        break;
        case 2:
        cout<<"You have selected to degue the element from the queue\n";
        q.deque();
        h=h-1;
        break;
        case 3:
        q.display();
        break;
        case 4:
        q.search();
        break;
    }
    if(choice==5)
    {
       cout<<"Exited the code";
       break;
    }
  }
  return 0;
}