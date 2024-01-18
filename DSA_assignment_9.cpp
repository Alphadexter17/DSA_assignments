#include<iostream>
using namespace std;
class heap_max{
    int *heap;
    int c;
    int n;
    public:
    void heapify(int c, int n)
    {
        int largest=c;
        int left_child=(2*c);
        int right_child=(2 *c)+1;
        while(left_child<=n && heap[left_child]>heap[largest])
        {
            largest=left_child;
        }
        while(right_child<=n && heap[right_child]>heap[largest])
        {
            largest=right_child;
        }
        if(largest!=c)
        {
            swap(heap[c],heap[largest]);
            heapify(largest,n);
        }
    }
    void max_heap()
    {
        cout<<"Enter the size of the heap: ";
        cin>>n;
        heap=new int[n+1];
        heap[0]=0;
        for(int i=1;i<n+1;i++)
        {
            cout<<"Enter your value: ";
            cin>>heap[i];
        }
    }
    void max()
    {
        for(int i=n/2;i>=1;i--)
        {
            heapify(i,n);
        }
    }
    void display_heap()
    {
        for(int i=1;i<n+1;i++)
        {
            cout<<heap[i]<<" ";
        }
    }
    void heap_sort()
    {
        max();
        for(int i=n-1;i>=0;i--)
        {
            swap(heap[1],heap[i]);
            heapify(i+1,1);
        }
    }
};
int main()   //code has wrong output
{
    heap_max obj1;
    while(true)
    {
        cout<<"1.Make Heap tree"<<endl;
        cout<<"2.Display heap"<<endl;
        cout<<"3.Perform heap sort"<<endl;
        cout<<"4.Display max heap"<<endl;
        cout<<"5.Exit the operation"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj1.max_heap();
            cout<<endl;
            break;
            case 2:
            obj1.display_heap();
            cout<<endl;
            break;
            case 3:
            obj1.heap_sort();
            cout<<endl;
            break;
            case 4:
            obj1.max();
            obj1.display_heap();
            cout<<endl;
            break;
        }
        if(choice==5)
        break;
    }
    return 0;
}