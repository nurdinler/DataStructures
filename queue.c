#include <stdio.h>
#include <stdlib.h> //for malloc

typedef struct QueueStruct{
	int data;
	struct QueueStruct *next;
}node;

//will store root and tail because datas will add to next of tail
node *root=NULL;
node *rear=NULL; //stores end of the queue

void enqueue(int _data){	
	if(root==NULL){ //if queue is empty	
		root=(node*)malloc(sizeof(node));
		root->data=_data;
		rear=root;
		rear->next=NULL;	
		return;	
	}
	node *temp=(node*)malloc(sizeof(node));
	temp->data=_data;
	rear->next=temp;
	temp->next=NULL;
	rear=temp;
}

void dequeue(){
	if(root==NULL){//if queue is empty
		printf("Can not dequeue since queue is empty\n");
		return;
	}
	if(root==rear){//there is only one data im queue 
		rear==NULL;
	}
	node *temp=root;
	root=root->next;
	free(temp);
}
void print_queue(){
	if(root==NULL){
		printf("Queue is empty");
	}
	node *temp=root; 
	// since root is global var we using a temp var to roam in the queue
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	print_queue();
	enqueue(5);
	print_queue();
	enqueue(9);
	print_queue();
	enqueue(6);
	print_queue();
	enqueue(16);
	print_queue();
	enqueue(77);
	print_queue();
	enqueue(34);
	print_queue();
	dequeue();
	print_queue();
	dequeue();
	print_queue();
	dequeue();
	print_queue();
	dequeue();
	print_queue();
	dequeue();
	print_queue();
	dequeue();
	print_queue();
	dequeue();
	return 0;
}
