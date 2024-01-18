#include "stack.cpp"
#include "stack.h"
#include<iostream>
using namespace std;
template <class T>
class dnode{
    public:
    dnode *left;
    dnode *right;
    T data;
    dnode()
    {
        data=NULL;
        left=nullptr;
        right=nullptr;
    }
};
class tree{
    public:
    dnode <char> *main_root;
    dnode<char> *make_tree(string s);
    void display_inorder(dnode<char> *root);
    void display_postorder(dnode<char> *root);
    void display_preorder(dnode<char> *root);
    void iterative_inorder(dnode<char> *root);   
    void iterative_postorder(dnode<char> *root);
    void iterative_preorder(dnode<char> *root);
};
void tree::iterative_preorder(dnode<char> *root)
{
    stack<dnode<char>* > st;
    dnode<char> *it_root=root;
        while(it_root!=nullptr)
        {
            cout<<it_root->data;
            st.push(it_root);
            it_root=it_root->left;
        }
        while(!st.is_empty())
        {
            it_root=st.at_top();
            st.pop();
            it_root=it_root->right;
            while(it_root!=nullptr)
            {
                cout<<it_root->data;
                st.push(it_root);
                it_root=it_root->left;
            }
        }
}
void tree::iterative_postorder(dnode<char> *root)
{
    if(root==nullptr)
    {
        return ;
    }
    stack<dnode <char> *> s1,s2;
    s1.push(root);
    while(!s1.is_empty())
    {
    dnode <char> *node=s1.at_top();
    s1.pop();
    s2.push(node);
    if(node->left!=nullptr)
    {
        s1.push(node->left);
    }
    if(node->right!=nullptr)
    {
        s1.push(node->right);
    }
    }
    while(!s2.is_empty())
    {
        dnode<char> *temp=s2.at_top();
        cout<<temp->data;
        s2.pop();
    }
}
void tree::iterative_inorder(dnode<char> *root)
{
    stack <dnode<char>* > st;
    dnode <char> *it_root=root;
    while(true)
    {
        while(it_root!=nullptr)
        {
            st.push(it_root);
            it_root=it_root->left;
        }
        if(!st.is_empty())
        {
            it_root=st.at_top();
            st.pop();
            cout<<it_root->data;
            it_root=it_root->right;
        }
        else 
        return ;
    }
}
void tree::display_preorder(dnode<char> *root)
{
    dnode<char> *temp=root;
    if(temp!=nullptr)
    {
        cout<<root->data;
        display_preorder(temp->left);
        display_preorder(temp->right);
    }
}
void tree::display_postorder(dnode<char> *root)
{
    dnode <char> *temp=root;
    if(temp!=nullptr)
    {
        display_postorder(temp->left);
        display_postorder(temp->right);
        cout<<root->data;
    }
}
void tree::display_inorder(dnode<char> *root)
{
    dnode<char> *temp=root;
    if(temp!=nullptr)
    {
        display_inorder(temp->left);
        cout<<root->data;
        display_inorder(temp->right);
    }
}
dnode<char>* tree ::make_tree(string s)
{
    dnode<char> *left1;
    dnode<char> *right1;
    stack <dnode<char>*> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
        {

            right1=st.at_top();
            st.pop();
            left1=st.at_top();
            st.pop();
            dnode <char>*temp= new dnode<char>();
            temp->left=left1;
            temp->right=right1;
            temp->data=s[i];
            st.push(temp);
        }
        else
        {
            dnode <char>*temp=new dnode<char>();
            temp->data=s[i];
            st.push(temp);
        }
    }
    main_root=st.at_top();
    return  main_root;
};
int main()
{
    string input;
    tree obj1;
    dnode <char> *main_root=nullptr;
    cout<<"Enter your postfix expression: ";
    cin>>input;
    main_root=obj1.make_tree(input);
    while(true)
    {
        cout<<"1.Display Postorder using recursion "<<endl;
        cout<<"2.Display Inorder using recursion"<<endl;
        cout<<"3.Display Preorder using recursion"<<endl;
        cout<<"4.Display Postorder without recursion"<<endl;
        cout<<"5.Display Inorder without recursion"<<endl;
        cout<<"6.Display Preorder without recursion"<<endl;
        cout<<"7.Exit the programm"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj1.display_postorder(main_root);
            cout<<endl;
            break;
            case 2:
            obj1.display_inorder(main_root);
            cout<<endl;
            break;
            case 3:
            obj1.display_preorder(main_root);
                        cout<<endl;
            break;
            case 4:
            obj1.iterative_postorder(main_root);
                        cout<<endl;
            break;
            case 5:
            obj1.iterative_inorder(main_root);
                        cout<<endl;
            break;
            case 6:
            obj1.iterative_preorder(main_root);
                        cout<<endl;
            break;
            case 7:
            cout<<"Prgramm has been exited"<<endl;
                        cout<<endl;
            break;
        }
        if(choice==7)
        break;
        else if(choice>7)
        cout<<"Please enter proper choice"<<endl;
    }
    return 0;
}