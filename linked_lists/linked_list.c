#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
    
};

void print_Nodes(struct Node *head){
    struct Node *curr=head;
    int size=0;
    for (curr=head;curr!=NULL;curr=curr->next){
        cout<<curr->data<<"\n";
        size++;
    }
    cout<<"Size of array is "<<size <<"\n";

}

struct Node *insert_at_begin(struct Node *head,int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if (head==NULL){
        //If empty List
        temp->next=NULL;
        head=temp;
    }
    else{
        //If existing List
        temp->next=head;
        head=temp;
    }
    return head;

}

struct Node *insert_at_end(struct Node *head,int data){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    struct Node *curr=head;
    temp->data=data;
    temp->next=NULL;
    if (head==NULL){
        //If empty list
        head=temp;
    }
    else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
    return head;
}

struct Node *insert_at_middle(struct Node *head,int data,int position){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    struct Node *curr=head,*buffer;
    temp->data=data;
    temp->next=NULL;
    int counter=1;

    if (curr==NULL){
        //EMTPY LIST
        head=temp;
    }
    else if(position==1){
        head=insert_at_begin(head,data);
    }
    else{
        while (curr!=NULL && counter<position){
            buffer=curr;
            curr=curr->next;
            counter++;
        }
        if (counter<position){
            cout<<"Position not found"<<"\n";
            return head;
        }
        buffer->next=temp;
        temp->next=curr;
    }  
    return head;
}



int main(){
    struct Node *head;
    head=insert_at_begin(NULL,15);
    print_Nodes(head);
    head=insert_at_begin(head,10);
    print_Nodes(head);
    head=insert_at_end(head,325);
    print_Nodes(head);
    head=insert_at_middle(head,1000,5);
    print_Nodes(head);
    return 0;
}
