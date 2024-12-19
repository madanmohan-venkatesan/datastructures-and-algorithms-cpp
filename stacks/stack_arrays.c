#include <iostream>
#include<limits.h>
using namespace std;

struct stack
{
    int top;
    int capacity;
    int *arr;
};

struct stack *create_stack(int capacity)
{
    struct stack *S=(struct stack *)malloc(sizeof(struct stack));
    if (!S)
    {
        cout << "Memory error"<<"\n";
        return NULL;
    }
    S->top=-1;
    S->capacity=capacity;
    S->arr=(int *)malloc(S->capacity*sizeof(int));
    if (!S->arr)
    {
        cout<<"Memory error"<<"\n";
        return NULL;
    }
    return S;
}

int isEmpty(struct stack *S)
{
    if (S->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *S)
{
    if (S->top==S->capacity-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void push(struct stack *S, int data)
{
    if(isFull(S))
    {
        cout<<"Stack overflow"<<"\n";
        return;
    }
    else
    {
        S->arr[++S->top]=data;
    }
    return;
}

int peek(struct stack *S)
{
    if (isEmpty(S))
    {
        cout<<"Under flow"<<"\n";
    }
    else
    {
        return(S->arr[S->top]);
    }
    return INT_MIN;
}
int pop(struct stack *S)
{
    if (isEmpty(S))
    {
        cout<<"empty stack"<<"\n";
    }
    else
    {
        return (S->arr[S->top--]);
    }
}
void delete_stack(struct stack *S)
{
    if(S)
    {
        if(S->arr)
        {
            free(S->arr);
        }
        free(S);
    }
}



void increase_capacity(struct stack *S)
{
    S->capacity=2*S->capacity;
    S->arr=(int *)realloc(S->arr,S->capacity * sizeof(int));
}


int main()
{
    struct stack *a;
    int s,p;
    a=create_stack(10);
    s=peek(a);
    cout<<s<<"\n";
    push(a,10);
    s=peek(a);
    cout<<s<<"\n";
    push(a,20);
    s=peek(a);
    cout<<s<<"\n";
    p=pop(a);
    s=peek(a);
    cout<<s<<"\n";
    increase_capacity(a);
    s=peek(a);
    cout<<s<<"\n";
    delete_stack(a);
    s=peek(a);
    cout<<s<<"\n";
return 0;
}