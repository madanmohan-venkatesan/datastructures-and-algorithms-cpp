#include <stdio.h>
#include <cstdlib>

struct Node{
    int data;
    struct Node *next;
    
};

void print_Nodes(struct Node *head){
    struct Node *curr=head;
    int size=0;
    for (curr=head;curr!=NULL;curr->next){
        printf("%d",curr->data);
        printf("\n");
        size++;
    }
    printf("Size of array is %d,size");

}

struct Node *insert_at_begin(struct Node *head,int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if (head==NULL){
        printf("EMPTY LIST");
        temp->next=NULL;
        head=temp;
    }
    else{
        printf("appending list");
        temp->next=head;
        head=temp;
    }
    return head;

}

int main(){
    struct Node a,*head;
    head=&a;
    head=insert_at_begin(head,15);
    // print_Nodes(head);

    return 0;
    
}
