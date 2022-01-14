//C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>

// stack structure
typedef struct Stackstructure{
	int data;
	struct Stackstructure *next;
}node;


// adding new node to stack
node* push(node *root,int _data){
	if(root==NULL){ //if stack is empty
		root=(node*)malloc(sizeof(node));
		root->data=_data;
		root->next=NULL;
		return root;
	}
	//if stack is not empty
	node *temp=(node*)malloc(sizeof(node));
	temp->data=_data;
	temp->next=root;
	return temp;	
}
//deleting first node because of FILO
node* pop(node *root){
	if(root==NULL){ //if stack is empty
		printf("stack is empty\n");
		return;
	}
	//if stack is not empty
	node *temp;
	temp=root;
	root=root->next;
	printf("%d data is popped\n",temp->data);
	free(temp);
	return root;	
}
void print_stack(node *root){
	if(root==NULL){
		printf("stack is empty\n");
		return;
	}
	printf("_____________________________________\n");
	while(root!=NULL){
		printf("|		%d		   |\n",root->data);
		printf("___________________________________\n");
		root=root->next;
	}
	printf("______________________________________\n");
	printf("******************************************\n");
}
int main(){
	printf("************************STACK DATA STRUCTURE************************\n");
	node *root=NULL;
	print_stack(root);
	root=push(root,5);
	print_stack(root);
	root=push(root,17);
	print_stack(root);
	root=push(root,1);
	print_stack(root);
	root=push(root,13);
	print_stack(root);
	root=push(root,6);
	print_stack(root);
	root=pop(root);
	root=pop(root);
	root=pop(root);
	root=pop(root);
	root=pop(root);
	root=pop(root); // should sya stack is empty	
	return 0;
}
