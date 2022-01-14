#include <stdio.h>
#include <stdlib.h>
/*
	Dosya sisteminin isleyisi
	theTree yapisinda kendinden sonraki klasoru ve alt klasorlerini
	gosteren iki pointer tanimlandi
	ornegin:
	C
	|-> X
		|-> A
	    |-> B
	|-> Y
		|-> C
		|-> D
		
	_________
	|		|
	|	C	| --next-->NULL
	|_______|
		|
		sub
		|
	_________												_________
	|		|												|		|
	|	X	| --------------next----------------------->	|	Y	| --next-->NULL
	|_______|												|_______|
		|														|
		sub														sub
	____|____			_________							____|____			_________	
	|		|			|		|							|		|			|		|
	|	A	| --next--> |	B	| --next-->NULL				|	C	| --next->  |	D	| --next--> NULL
	|_______|			|_______|							|_______|			|_______|
		|					|									|					|
		sub					sub									sub					sub
		|					|									|					|
		NULL				NULL								NULL				NULL

 */
struct theTree{
	char data;
	int tabnum;//klasorun seviyesini gosteriyor
	theTree *next;//bir sonraki klasoru gosteriyor
	theTree *sub;//alt klasorleri gosteriyor
};
typedef theTree tree;
tree* add(tree *root,tree *temp){
	tree *iter;
	iter=root;
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));	
		root->data=temp->data;
		root->next=NULL;
		root->sub=NULL;
		return root;			
	}
	if(iter->data < temp->data){
		//buyuk olan saga eklenir
		iter->next = add(iter->next,temp);
		return root;
	}
	else{//diger durumlarda asagi eklenecek
		iter->sub=add(iter->sub,temp);
		return root;
	}		
}
 void list(tree *root){
 	//infix = left node right,right node left 
	//kucuken buyuge siralar
	//prefix = node left right,node right left
	//postfix = left right node , right left  
	/* 
		if (root == NULL) 
        return; 
    space += 7; 
     
	print2DUtil(root->sag, space); 
  
  	printf("\n"); 
    
	for (int i = 10; i < space; i++) 
        printf(" ");
		 
    printf("%d\n", root->data); 
  	print2DUtil(root->sol, space); 
	*/
	tree *iter;
	iter=root;	
	if(root==NULL){
		return;
	}
	
	
 }

int main(){
	tree *root,*x,*y,*a,*b,*c,*d;
	root=(tree*)malloc(sizeof(tree));
	root->data=10;
	root->next=NULL;
	root->sub=NULL;
	root->tabnum=0;
	x=(tree*)malloc(sizeof(tree));
	x->data=16;
	x->next=NULL;
	x->sub=NULL;
	x->tabnum=5;
	y=(tree*)malloc(sizeof(tree));
	y->data=19;
	y->next=NULL;
	y->sub=NULL;
	y->tabnum=1;
	a=(tree*)malloc(sizeof(tree));
	a->data=17;
	a->next=NULL;
	a->sub=NULL;
	a->tabnum=2;
	b=(tree*)malloc(sizeof(tree));
	b->data=13;
	b->next=NULL;
	b->sub=NULL;
	b->tabnum=2;	
	root=add(root,x);
	root=add(root,y);
	root=add(root,a);
	root=add(root,b);
/*	root=add(root,58);
	root=add(root,8);
	root=add(root,18);
	root=add(root,88);
	root=add(root,98);
	root=add(root,48); */
	list(root);
	
}
