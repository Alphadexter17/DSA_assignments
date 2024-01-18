#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;
struct dat{
    int roll;
    string name;
    int div;
    string address;
};
class operations{
    fstream obj;
    public:
    void clear();
    void open();
    void write();
    void search(int roll);
    void modify_roll(int roll);
    void del_record(int roll);
    void display();
    operations()
    {
        clear();
        open();
    }
};
void operations::clear()
{
    obj.open("sample.txt",ios::out | ios::trunc);
    obj.clear();
}
void operations::open()
{
    obj.open("sample.txt");
    obj.close();
}
void operations::write()
{
    obj.open("sample.txt",ios::app);
    dat collection;
    cout<<"Enter the name of the student: ";
    cin>>collection.name;
    cout<<"\nEnter the roll number of the student : ";
    cin>>collection.roll;
    cout<<"\nEnter the Division of the student: ";
    cin>>collection.div;
    cout<<"\nEnter Address of the student: ";
    cin>>collection.address;
    obj<<collection.name<<"\t\t"<<collection.roll<<"\t\t"<<collection.div<<"\t\t"<<collection.address<<"\n";
    obj.close();
}
void operations:: search(int roll)
{
    obj.open("sample.txt");
    if(obj.is_open())
    {
        string s;
        while(getline(obj,s))
        {
        string arr[4];
        int i=0;
        stringstream input(s);
            while(input.good() && i<4)
            {
                input>>arr[i];
                i++;
            }
            if(arr[1]==to_string(roll))
            {
                cout<<"\n";
                cout<<"\nFOUND IN DATA BASE!!!"<<endl;
                cout<<"NAME\t\tROLLNUMBER\tDIVISION\tADDRESS\t\t"<<endl;
                for(int j=0;j<4;j++)
                {
                    cout<<arr[j]<<"\t\t";
                }
                cout<<"\n\n";
                return ;
            }
        }
        cout<<"DATA IS NOT FOUND IN DATA BASE"<<endl;
    }
    obj.close();
}
void operations::modify_roll(int roll)
{
    obj.open("sample.txt");
    string inputroll;
    string s;
    fstream obj2;
    obj2.open("temp.txt",ios::app);
    while(getline(obj,s))
    {
        int i=0;
        string arr[4];
        stringstream input(s);
        while(input.good() && i<4)
        {
            input>>arr[i];
            i++;
        }
        if(arr[1]==to_string(roll))
        {
            cout<<"Enter new roll number:  ";
            cin>>inputroll;
            arr[1]=inputroll;
            for(int w=0;w<4;w++)
            {
                obj2<<arr[w]<<"\t\t";
            }
            obj2<<"\n";
        }
        else
        {
            for(int w=0;w<4;w++)
            {
                obj2<<arr[w]<<"\t\t";
            }
            obj2<<"\n";
        }
    }
    obj.close();
    remove("sample.txt");
    obj2.close();
    rename("temp.txt","sample.txt");
   
}
void operations::display()
{
    obj.open("sample.txt",ios::in);
    string s;
    cout<<"NAME\t\tROLLNUMBER\tDIVISION\tADDRESS\t\t"<<endl;
    while(getline(obj,s))
    {
        cout<<s<<"\t\t\t";
        cout<<endl;
    }
    obj.close();
}
void operations::del_record(int roll)
{
    obj.open("sample.txt");
    fstream obj3;
    obj3.open("temp.txt",ios::app);
    string s;
    while(getline(obj,s))
    {
        stringstream input(s);
        int i=0;
        string arr[4];
        while(input.good() && i<4)
        {
            input>>arr[i];
            i++;
        }
        if(arr[1]!=to_string(roll))
        {
            for(int i=0;i<4;i++)
            {
                obj3<<arr[i]<<"\t\t";
            }
            obj3<<"\n";
        }
    }
    cout<<"The Element has been removed from the record successfully!"<<endl;
    remove("sample.txt");
    obj.close();
    rename("temp.txt","sample.txt");
    obj3.close();
}
int main()
{
    operations obj1;
    int choice;
    while(true)
    {
        cout<<"1.Add Record in Data Base!"<<endl;
        cout<<"2.Delete Record in Data Base!"<<endl;
        cout<<"3.Display the Data Base!"<<endl;
        cout<<"4.Search Roll number in the Data Base"<<endl;
        cout<<"5.Modify roll number in the Data Base"<<endl;
        cout<<"6.Exit the Programm"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj1.write();
            cout<<endl;
            break;
            case 2:
            int roll;
            cout<<"Enter the roll number you want to delete in the data base"<<endl;
            cin>>roll;
            obj1.del_record(roll);
            cout<<endl;
            break;
            case 3:
            cout<<endl<<"Displaying the Records in the Data Base"<<endl;
            obj1.display();
            cout<<endl;
            break;
            case 4:
            cout<<endl<<"Searching the record in the Data Base"<<endl;
            cout<<"Enter the roll number you want to search"<<endl;
            int roll2;
            cin>>roll2;
            obj1.search(roll2);
            break;
            case 5:
            cout<<endl<<"Enter the roll number which you want to modify"<<endl;
            int roll3;
            cin>>roll3;
            obj1.modify_roll(roll3);
            break;
        }
        if(choice==6)
        {
            cout<<"Succesfully exited the programm"<<endl;
            break;
        }
        else if(choice>6)
        {
            cout<<"Please enter proper choice \n Enter choice again: "<<endl;
        }
    }
    return 0;
}