#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *prev_node;
    struct Node *next_node;
};

void print_nodes(struct Node *head)
{
    struct Node *curr=head;
    int size=0;
    while(curr!=NULL)
    {
        cout<<curr->data<<"\n";
        curr=curr->next_node;
        size++;
    }
    cout<<"Size of list is :"<<size<<"\n";
}


struct Node *insert_at_beginning(struct Node *head,int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev_node=NULL;
    temp->next_node=NULL;
    struct Node *curr=head;
    if (curr==NULL)
    {
        //EMPTY NODE
        cout<<"Empty node"<<"\n";
        head=temp;
    }
    else
    {
        temp->next_node=head;
        head->prev_node=temp;
        head=temp;
    }
    return head;
}

struct Node *insert_at_end(struct Node *head,int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    struct Node *curr=head;
    temp->data=data;
    temp->prev_node=NULL;
    temp->next_node=NULL;
    if (curr==NULL)
    {
        head=temp;
    }
    else
    {
        while(curr->next_node!=NULL)
        {
            curr=curr->next_node;
        }
        
        curr->next_node=temp;
        temp->prev_node=curr;
    }
    return head;
}

struct Node *insert_at_middle(struct Node *head,int data,int pos)
{
    struct Node *buffer,*curr=head;
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev_node=NULL;
    temp->next_node=NULL;
    int counter=1;
    if (curr==NULL)
    {
        cout<<"Empty list"<<"\n";
        return head;
    }
    else if (pos==1)
    {
        head=insert_at_beginning(head,data);
    }
    else
    {
        while (curr->next_node!=NULL && counter<pos)
        {
            buffer=curr;
            curr=curr->next_node;
            counter++;
        }
        if (counter<pos)
        {
            cout<<"Position not found"<<"\n";
            return head;
        }

        else if (curr->next_node==NULL)
        {
            buffer->next_node=temp;
            temp->prev_node=buffer;
            temp->next_node=curr;
            curr->prev_node=temp;
        }
        else
        {
            buffer->next_node=temp;
            temp->prev_node=buffer;
            temp->next_node=curr;
            curr->prev_node=temp;
        }
    }
    return head;
}

struct Node *delete_node(struct Node *head,int pos)
{
    struct Node *temp,*buffer,*curr=head;
    int counter=1;
    if (pos==1)
    {
        head=head->next_node;
        head->prev_node=NULL;

        free(curr);
    }
    else
    {
        while(curr->next_node!=NULL && counter<pos)
        {
            buffer=curr;
            curr=curr->next_node;
            counter++;
        }
        if (counter<pos)
        {
 //review counter checking here

            cout<<"Position not found"<<"\n";
            return head;
        }
        else if (curr->next_node==NULL)
        {
            temp=curr->next_node;
            buffer->next_node=temp;
            // temp->prev_node=buffer;
            free(curr);
        }
        else
        {
            temp=curr->next_node;
            buffer->next_node=temp;
            temp->prev_node=buffer;
            free(curr);
        }

        
    }
    return head;
}

int main()
{
    struct Node *head;
    head=insert_at_beginning(NULL,10);
    print_nodes(head);
    head=insert_at_beginning(head,100);
    print_nodes(head);
    head=insert_at_end(head,1000);
    print_nodes(head);
    head=insert_at_middle(head,1234,4);
    print_nodes(head);
    head=delete_node(head,3);
    print_nodes(head);
    return 0;
}