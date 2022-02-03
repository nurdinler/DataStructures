#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}node;
node *head=NULL;
node *tail=NULL;
void enqueue(){
    int x;
    scanf("%d",&x);
    node *newnode= (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL){//if the queue is empty
        head=newnode;
        tail=newnode; 
        tail->next=NULL;  
        return;     
    }  
    tail->next=newnode;
    tail=tail->next;
}
void dequeue(){
    if(head==NULL){//if queue is empty
        return;
    }
    node *temp;
    temp=head;
    head=head->next;
    free(temp);    
}
void printit(){//print the front element
    if(head==NULL){//if queue is empty
        return;
    }
    printf("%d",head->data);
    printf("\n");
}
int main() {
    /*
        1: enqueue
        2: dequeue
        3: print queue
     */
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int q;
    scanf("%d",&q); //num of queries
    for(int i=0;i<q;i++){
        int choice;
        scanf("%d",&choice);
        switch (choice) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: printit();
                    break;
            default: 
                printf("");                   
        }        
        
    }
    return 0;
}
