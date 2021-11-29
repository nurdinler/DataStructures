#include <stdio.h>
#include <stdlib.h>
/*
_________________________________________________________________
|*******************TEK YONLU BAGLI LISTE***********************|
|	*eleman sayma												|
|	*ekleme														|
|	*listeleme													|
|	*silme														|
|	*ekleme														|
|	*siralama													|
|																|
|************************************************************** |
|_______________________________________________________________|	
 */

struct mystruct{
	int data;
	mystruct *next;
};
typedef mystruct node;

//Listedeki eleman sayisini bulan ve ekrana yazdiran fonksiyon
node* count_em(node *r){ //SORULACAK
	int sayac=0;
	while(r->next!=NULL){
		r=r->next;
		sayac++;
	}
	printf("\n ELEMAN SAYISI : %d\n",sayac);
	
}
/* 
	Listeye ekleme yapma
*/
//sondan ekleme
node* addto_end(node *r,int data){
	node *iter; //listenin içinde gezmemizi saglayan pointer
	node *temp; //listeye eklenecek dugum
	temp=(node*)malloc(sizeof(node)); //eklenecek dugum olusturuldu
	temp->data=data; // dugumun icine data eklendi
	if(r==NULL){ //liste bos mu kontrolu
		r = (node*)malloc(sizeof(node));
		r->next=NULL;
		return r;
	}
	iter=r;		
	// iter roota esitlendi boylece listeye bastan baslayarak sona kadar gezebilecegiz
	while(iter->next!=NULL){
		/*  su anki dugumden sonraki dugum NULL'u gostermedigi surece
			bir sonraki dugume gec.
			Bu sekilde listeni son dugumunde duracagiz			
		*/
		iter=iter->next;
	}
	iter->next=temp;
	temp->next=NULL;
	/*
						_______			_________
	Listenin			|	   |		|		|
	diger		--->	|iter  | --->   | temp	| ---> NULL
	elemanlari			|______|		|_______|
	 */
			
}
//Bastan Ekleme
node* addto_beg(node *r,int _data){
	node *iter;	//listenin içinde gezmemizi saglayan pointer
	node *temp; //listeye eklenecek dugum
	temp = (node*)malloc(sizeof(node)); //eklenecek dugum olusturuldu
	temp->data =_data; // dugumun icine data eklendi
	if(r==NULL){ //liste bos mu kontrolu
		r = (node*)malloc(sizeof(node));
		r->next=NULL;
		return r;
	}
	else{
		//Listenin basina eleman eklenecegi icin root degisecek		
		temp->next=r;
		r=temp;
		return r;		
		/* 
			_________		________
			|		|		|		|
			|temp	| ---> 	|r		| ---> Listenin geri kalani
			|_______|		|_______|
			
			Yeni temp artik yeni root
			_________		________
			|		|		|		|
			|r		| ---> 	|		| ---> Listenin geri kalani
			|_______|		|_______|
		*/
	}
}
// Listeleme fonksiyonu
void list_em_all(node *r){
	node *iter;
	iter=r;
	if(r==NULL){ //Liste bos mu kontrolu
		printf("Liste bos");
	}
	while(iter->next!=NULL){
		printf("%d -> ",iter->data);
		iter=iter->next;
		/*
			iter'in gosterdigi dugumden sonraki dugum NULL'a esit olmadigi surece
			bir sonraki dugume gececek.
			Bir sonraki dugume gecmeden once o dugumdeki datayi yazdir
		 */
	}
	count_em(r);
	printf("\n"); // bir satir asagiya gec
}

node* delete_list(node *r,int _data){
	node *deleted; //silinecek olan dugum
	node *iter;	// listede gezmemizi saglayan pointer
	iter=r;	 // listede gezinebilmek icin iteri roota esitleme
	if(r->data==_data){ // ilk dugum silinecekse
		deleted=r;
		r=r->next;
		free(deleted);
		printf("Bastaki eleman silindi");
		return r;
		/*
			_________
			|		|
			|root	| -> listenin kalani
			|_______|
			
			deleted = root;
			_________
			|root	|
			|deleted| -> listenin kalani
			|_______|
			
			r=r->next
			_________		________
			|		|		|		|
			|deleted| ---> 	|r		| ---> Listenin geri kalani
			|_______|		|_______|
			
			free(deleted) deleted dugumu silindi
			________
			|		|
			|r  	| -> listenin kalani
			|_______|
						
		 */	
	}
	else{
		while(iter->data!=_data){
			if(iter->next==NULL)//listenin sonuna gelindi mi?
				break;
			iter=iter->next;			
			/*  su anki dugumden sonraki dugum silinecek dataya esit
			olmadigi surece	bir sonraki dugume gec.
			Bu sekilde silinecek dugumun bir onceki dugumunde durulacak			
			*/
		}
		if(iter->data==_data){
			deleted=iter->next;
			iter->next = iter->next->next;
			free(deleted);
			return r;				
		/*
			_________		___________		 _________
			|		|		|silinecek|		 |		 |	
			|iter   | ---> 	|dugum    | ---> |       | --> Listenin geri kalani
			|_______|		|_________|		 |_______|
			
			deleted = iter->next
			_________		________		________
			|		|		|		|		|		|
			|iter	| ---> 	|deleted| --->  |*		| --> Listenin geri kalani
			|_______|		|_______|		|_______|
			
			iter->next = iter->next->next
			_________		________
			|		|		|		|
			|iter	| ---> 	|*		| --> Listenin geri kalani
			|_______|		|_______|
			
			free(deleted)	
		 */	
		}
		printf("Eleman bulunamadi\n");
		return r;
	
	}	
}

// dataya gore siralama
void order_em(node *r){
	node *iter;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	iter = r;
	while(iter->next!=NULL){
		if(r->data > r->next->data){
			//roottaki degere erisemedigi icin ayri if actim
			temp->data=iter->data;
			iter->data=iter->next->data;
			iter->next->data=temp->data;
			
		}
		if(iter->data > iter->next->data){
			temp->data=iter->data;
			iter->data=iter->next->data;
			iter->next->data=temp->data;
		}
		iter=iter->next;
	}
	list_em_all(r);
}

int main(){
	node *root,*iter;
	root=NULL;
	root=(node*)malloc(sizeof(node));
	root->data=87;
	//list_em_all(root); 
	//NULL'A ESITLEMEDEN LIST ISTERSEN SONSUZ DONGUYE GIRER
	root->next=NULL;
	list_em_all(root);
	addto_end(root,65);
	list_em_all(root);
	root=addto_beg(root,56);
	list_em_all(root);
	root=addto_beg(root,93);
	list_em_all(root);
	root=addto_beg(root,77);
	list_em_all(root);
	addto_end(root,16);
	list_em_all(root);
	addto_end(root,23);
	list_em_all(root);
	delete_list(root,93);
	list_em_all(root);
	delete_list(root,100);
	list_em_all(root);
	printf("SIRALAMA\n");
	order_em(root);

	
	

	
	
	
}
