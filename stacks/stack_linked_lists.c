#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
};

struct stack
{
    struct Node *top;
};
struct stack *create_stack()
{
    struct stack *S=(struct stack *)malloc(sizeof(struct stack));
    S->top=NULL;
    return S;
}


int size(struct stack *S)
{
    int count=0;
    struct Node *temp;
    temp=S->top;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

bool isEmpty(struct stack *S)
{
    int count=0;
    count=size(S);
    if (count==0)
    {
        return 1;
    }
    return 0;
}

void *push(struct stack *S,int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    if(!temp)
    {
        cout<<"Memory error while creating node"<<"\n";
    }
    temp->data=data;
    temp->next=S->top;
    S->top=temp;
}

int pop(struct stack *S)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp=S->top;
    S->top=temp->next;
    return temp->data;
}
int peek(struct stack *S)
{
    if(isEmpty(S))
    {
        cout<<"Stack underflow"<<"\n";
        return 0;
    }
    return (S->top)->data;
}


int main()
{
    struct stack *a;
    int s,p;
    a=create_stack();
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
    s=peek(a);
    cout<<s<<"\n";
    // delete_stack(a);
    s=peek(a);
    cout<<s<<"\n";
return 0;
}
