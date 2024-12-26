#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
class stack
{
    public:
    Node *top;
    stack()
    {
        this->top=NULL;
    }
    int size()
    {
        int count=0;
        Node *temp;
        temp=this->top;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    bool isEmpty()
    {
        int count=0;
        count=size();
        if(count==0)
        {
            return 1;
        }
        return 0;
    }
    void push(int data)
    {
        Node *temp=(Node *)malloc(sizeof(Node));
        if(!temp)
        {
            cout<<"Memory error while creating node"<<"\n";
        }
        temp->data=data;
        temp->next=this->top;
        this->top=temp;
    }
    int pop()
    {
        Node *temp=(Node *)malloc(sizeof(Node));
        temp=this->top;
        this->top=temp->next;
        return temp->data;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<"\n";
            return 0;
        }
        return(this->top)->data;
    }

};

int main()
{
    stack a;
    int s,p;
    a=stack();
    s=a.peek();
    cout<<s<<"\n";
    a.push(10);
    s=a.peek();
    cout<<s<<"\n";
    a.push(20);
    s=a.peek();
    cout<<s<<"\n";
    p=a.pop();
    s=a.peek();
    cout<<s<<"\n";p=a.pop();
    s=a.peek();
    cout<<s<<"\n";


    return 0;

}