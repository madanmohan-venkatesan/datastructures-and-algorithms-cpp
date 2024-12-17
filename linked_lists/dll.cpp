//need to check delete part, middle part 
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *prev_node;
    Node *next_node;
    Node(int data)
    {
        this->data=data;
        this->prev_node=NULL;
        this->next_node=NULL;
    }
};
class dll
{
    private:
    Node *head;
    public:
    dll()
    {
        this->head=NULL;
    }
    void print_nodes()
    {
        Node *curr=this->head;
        int size=0;
        while(curr!=NULL)
        {
            cout<<curr->data<<"\n";
            curr=curr->next_node;
            size++;
        }
        cout<<"Size of list is :"<<size<<"\n";
    }
    void insert_at_beginning(int data)
    {
        Node *temp=new Node(data);
        Node *curr=this->head;
        if (curr==NULL)
        {
            cout<<"Empty node"<<"\n";
            this->head=temp;
        }
        else
        {
            temp->next_node=this->head;
            head->prev_node=temp;
            this->head=temp;
        }
    }

    void insert_at_end(int data)
    {
        Node *temp=new Node(data);
        Node *curr=this->head;
        if (curr==NULL)
        {
            this->head=temp;
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
    }

    void insert_at_middle(int data,int pos)
    {
        Node *buffer,*curr=this->head;
        Node *temp=new Node(data);
        int counter=1;
        if (curr=NULL)
        {
            cout<<"Empty list"<<"\n";
        }
        else if (pos==1)
        {
            insert_at_beginning(data);
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
                cout<<"Position not found"<<"\n";
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
    }

    void delete_node(int pos)
    {
        Node *temp,*buffer,*curr=this->head;
        int counter=1;
        if (pos=1)
        {
            this->head=this->head->next_node;
            head->prev_node=NULL;
            free(curr);
        }
        else
        {
            while(curr->next_node!=NULL && counter>pos)
            {
                buffer=curr;
                curr=curr->next_node;
                counter++;
            }
            if (counter<pos)
            {
                //review counter checking here
                cout<<"Position not found"<<"\n";
            }
            else if(curr->next_node==NULL)
            {
                temp=curr->next_node;
                buffer->next_node=temp;
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
    }

};

int main()
{
    dll a;
    a.insert_at_beginning(10);
    a.print_nodes();
    a.insert_at_beginning(100);
    a.print_nodes();
    a.insert_at_end(1000);
    a.print_nodes();
    a.insert_at_middle(1234,1);
    a.print_nodes();
    a.delete_node(3);
    a.print_nodes();
    return 0;
}