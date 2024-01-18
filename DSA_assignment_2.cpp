`#include<iostream>
#include<string>
#include<cmath>
#include "stack.h"
#include "stack.cpp"
using namespace std;
class expression{
    public:
    string infix_prefix(string input);
    string infix_postfix(string input);
    int postfix_evaluation(string input);
    int prefix_evaluation(string input);
};
int prece(char s)
{
    if(s=='^')
    return 3;
    else if(s=='*' || s=='/')
    return 2;
    else if(s=='+' || s=='-')
    return 1;
    else 
    return 0;
}
string expression::infix_postfix(string input)
{
    stack <char> st;
    string result="";
    for(int i=0;i<input.length();i++)
    {
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') )
        {
            result=result+input[i];
        } 
        if(input[i]=='(')
        {
            st.push(input[i]);
        }
        if(input[i]==')')
        {
            while(!st.is_empty() && st.at_top()!='(')
            {
                result=result+st.at_top();
                st.pop();
            }
            st.pop();
        }
        if((input[i]=='+') ||(input[i]=='-')|| (input[i]=='*')||(input[i]=='/'))
        {
            while(!st.is_empty() && prece(st.at_top())>=prece(input[i]))
            {
                result=result+st.at_top();
                st.pop();
            }
            st.push(input[i]);
        }
    }
    while(!st.is_empty())
    {
        result=result+st.at_top();
        st.pop();
    }
    return result;
}
string expression::infix_prefix(string input)
{
    stack<char> st;
    string result="";
    for(int i=input.length()-1;i>=0;i--)
    {
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') )
        {
            result=result+input[i];
        } 
        if(input[i]==')')
        {
            st.push(input[i]);
        }
        if(input[i]=='(')
        {
            while(st.at_top()!='(' && !st.is_empty())
            {
                result=result+st.at_top();
                st.pop();
            }
            st.pop();
        }
        if((input[i]=='+') ||(input[i]=='-')|| (input[i]=='*')||(input[i]=='/') || (input[i]=='^'))
        {
            while(!st.is_empty() && prece(st.at_top())>=prece(input[i]))
            {
                result=result+st.at_top();
                st.pop();
            }
            st.push(input[i]);
        }
    }
    while(!st.is_empty())
    {
        result=result+st.at_top();
        st.pop();
    }
    string reverse="";
    for(int i=0;i<result.length();i++)
    {
        reverse=reverse+result[result.length()-i-1];
    }
    return reverse;
}
int expression::postfix_evaluation(string input)
{
    stack<int> st;
    int num1;
    int num2;
    int num3;
    int res;
    for(int i=0;i<input.length();i++)
    {
        if((input[i]=='*') || (input[i]=='/') || (input[i]=='-') || (input[i]=='+'))
        {
            num1=st.at_top();
            st.pop();
            num2=st.at_top();
            st.pop();
            char s=input[i];
            switch(s)
            {
                case '+':
                res=num1+num2;
                break;
                case '-':
                res=num2-num1;
                break;
                case '/':
                res=num2/num1;
                break;
                case '*':
                res=num1*num2;
                break;
                case '^':
                res=pow(num2,num1);
                break;
            }
            st.push(res);
        }
        else
        {
            cout<<"Enter the value of  "<<input[i]<<" ";
            cin>>num3;
            st.push(num3);
        }
    }
    res=st.at_top();
    st.pop();
    return res;
}
int expression::prefix_evaluation(string input)
{
    stack<int> st;
    int num1;
    int num2;
    int num3;
    int res;
    for(int i=input.length()-1;i>=0;i--)
    {
        if((input[i]=='*') || (input[i]=='+') || (input[i]=='-') || (input[i]=='/') || (input[i]=='^'))
        {
            num1=st.at_top();
            st.pop();
            num2=st.at_top();
            char s=input[i];
            switch(s)
            {
                case '+':
                res=num2+num1;
                break;
                case '-':
                res=num2-num1;
                break;
                case '*':
                res=num2*num1;
                break;
                case '/':
                res=num2/num1;
                break;
                case '^':
                res=pow(num2,num1);
                break;
            }
            st.push(res);
        }
        else
        {
            cout<<"Enter the value of "<<input[i]<<":  ";
            cin>>num3;
            st.push(num3);
        }
    }
    res=st.at_top();
    return res;
}
int main()
{
    expression obj1;
    int choice;
    string input;
    string result;
    int finresult;
    while(true)
    {
        cout<<"1.Convert to Prefix\n2.Convert to postfix\n3.Evalute Postfix\n4.Evaluate Prefix\n5.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter your expression : ";
            cin>>input;
            cout<<"\nResult of Prefix is: "<<obj1.infix_prefix(input)<<endl;
            break;
            case 2:
            cout<<"\nEnter your expression: ";
            cin>>input;
            cout<<"\nResult of Postfix is: "<<obj1.infix_postfix(input)<<endl;
            break;
            case 3:
            cout<<"\nPlease enter your infix expression: ";
            cin>>input;
            result=obj1.infix_postfix(input);
            cout<<"The Postfix expression is: "<<result<<endl;
            finresult=obj1.postfix_evaluation(result);
            cout<<"Evaluation of Postfix expression is: "<<finresult<<endl;
            break;
            case 4:
            cout<<"Please enter your expression: ";
            cin>>input;
            result=obj1.infix_prefix(input);
            cout<<"The prefix expression is: "<<result<<endl;
            finresult=obj1.prefix_evaluation(result);
            cout<<"The postfix evaluation of expression is:  "<<finresult<<endl;
            break;
        }
        if(choice==5)
        {
            break;
        }
        else if(choice>5)
        {
            cout<<"Please enter proper choice!!"<<endl;
        }
    }
    return 0;
}