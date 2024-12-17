#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class linked_list{
    private:
    Node *head;
    public:
    linked_list(){
        this->head=NULL;
    }
    void print_nodes(){
        Node *curr;
        int size=0;
        for (curr=this->head;curr!=NULL;curr=curr->next){
            cout<<curr->data<<"\n";
            size++;
        }
        cout<<"Size of array is "<<size<<"\n";
    }
    void insert_at_begin(int data)
    {
        Node *temp=new Node(data);
        if (this->head==NULL)
        {
            //IF EMPTY LIST
            this->head=temp;
        }
        else
        {
            //if existing list
            temp->next=this->head;
            this->head=temp;
        }
    }

    void insert_at_end(int data)
    {
        Node *temp=new Node(data);
        Node *curr=this->head;
        if (this->head==NULL)
        {
            //CHECK FOR EMPTY LIST
            this->head=temp;
        }
        else
        {
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            curr->next=temp;
        }
    }

    void insert_at_middle(int data,int position)
    {
        Node *temp=new Node(data);
        Node *curr=this->head,*buffer;
        int counter=1;
        if (curr==NULL)
        {
            //EMPTY LIST
            this->head=temp;
        }
        else if(position==1)
        {
            insert_at_begin(data);
        }
        else
        {
            while(curr!=NULL && counter < position)
            {
                buffer=curr;
                curr=curr->next;
                counter++;
            }
            if (counter<position)
            {
                cout<<"Position not found"<<"\n";
            }
            buffer->next=temp;
            temp->next=curr;
        }
    }

    void delete_node(int position)
    {
        int counter=1;
        Node *curr,*buffer;
        if (this->head==NULL)
        {
            cout<<"Empty list"<<"\n";
        }
        curr=this->head;
        if (position==1)
        {
            this->head=(this->head)->next;
            free(curr);
        }
        else
        {
            while(curr!=NULL && counter<position)
            {
                counter++;
                buffer=curr;
                curr=curr->next;
            }
            if (curr==NULL)
            {
                cout<<"Position not found"<<"\n";
            }
            else
            {
                buffer->next=curr->next;
                free(curr);
            }
        }

    }


};

int main(){
    linked_list a;
    a.insert_at_begin(100);
    a.print_nodes();
    a.insert_at_end(200);
    a.print_nodes();
    a.insert_at_middle(300,2);
    a.print_nodes();
    a.delete_node(2);
    a.print_nodes();
    return 0;
}