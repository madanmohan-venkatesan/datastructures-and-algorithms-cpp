#include<iostream>
#include<limits.h>
using namespace std;

class stack
{
    private:
    int top;
    int capacity;
    int *arr;
    public:
    stack(int capacity)
    {
        this->top=-1;
        this->capacity=capacity;
        this->arr=(int *)malloc(this->capacity*sizeof(int));
        if (!this->arr)
        {
            cout<<"Memory error"<<"\n";
        }
    }
    int isEmpty()
    {
        if (this->top==-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    int isFull()
    {
        if (this->top==this->capacity-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(int data)
    {
        if (isFull())
        {
            cout<<"Stack overflow"<<"\n";
        }
        else
        {
            this->arr[++this->top]=data;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Under flow"<<"\n";
        }
        else
        {
            return(this->arr[this->top]);
        }
        return INT_MIN;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout<<"Empty stack"<<"\n";
        }
        else
        {
            return(this->arr[this->top--]);
        }
    }
    void increase_capacity()
    {
        this->capacity=2*this->capacity;
        this->arr=(int *)realloc(this->arr,this->capacity*sizeof(int));
    }
    ~stack()
    {
        cout<<"stack deleted"<<"\n";
    }
};

int main()
{
    stack a=stack(10);
    int s,p;
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
    cout<<s<<"\n";
    a.increase_capacity();
    s=a.peek();
    cout<<s<<"\n";
    delete &a;
    // s=a.peek();
    // cout<<s<<"\n";
    return 0;
}