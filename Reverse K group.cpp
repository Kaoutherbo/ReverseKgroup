#include<stdio.h>
#include<stdlib.h>
//Creat type Node
typedef struct node{
	int data;
	struct node *next;
}Node;

//Function that creat the linked list

Node* createLList(int n){

	int d;
	printf("enter the data number 1  : ");
	scanf("%d",&d);
	Node *head=(Node*) malloc(sizeof(Node));
	if(head==NULL)
		printf("element not created try again! ");
	else{
		head->next=NULL;
		head->data=d;
		Node *temp=head;
		int i;
		for(i=2;i<=n;i++){ 
			Node *newNode= (Node*)malloc(sizeof(Node));
			printf("enter the data number %d  : ",i);
	 		scanf("%d",&d);
	 		newNode->next=NULL;
			newNode->data=d;
			temp->next=newNode;
			temp= temp->next;
		}
		
	}
	return head;
	
	
}

// calculate the lenght of the list
int lenght_list(Node *head){
	Node *snode=head;
	int len=0;
	if(snode==NULL) return NULL;
	else{
		while(snode!=NULL){
			len++;
			snode=snode->next;
		}
	}
	return len;
}

//To display the list

void displayList(Node *head){
	if(head==NULL)//empty linked list
	printf("your list is empty!!");
	else if(head->next==NULL)//contains only one node
	{
		printf("%d  ",head->data);	
	}
	else//contains more than one node
	{
		Node *temp=head;
		while(temp!=NULL){
			printf("%d  ",temp->data);
			temp=temp->next;
		}
	}
}
//To reverse the k group nodes of the list

Node* Reverse_K_Group(Node *head,int k){
	
	if(head==NULL||k<=1) return head;
	
	int count=0;
	struct node *temp=head;
	
	//To check if the lenght of nodes is equal to k or not
	
	while(temp!=NULL&&count<k){
		temp=temp->next;
		count++;
	}
	 /*If the lenght of the nodes is not equal to k 
	(it means the total lenght of list not multiple of k )
	then return the head wuthout reversing */
	if(count<k){
		return head;
	
	}
//For reverse the k grouop nodes
 
	Node *previousNode=NULL,*currentNode=head,*nextNode;
	for(int i=0;i<k;i++){
		nextNode=currentNode->next;
		currentNode->next=previousNode;
		previousNode=currentNode;
		currentNode=nextNode;
	}
	
	/*currentNode has the address of the rest nodes 
	previousNode has the address of reversing nodes */
	
	head->next=Reverse_K_Group(currentNode,k);
	return previousNode;//return the reverse groups 
}

//Driver code
int main(){
	Node *list;
	int numNodes,k;
	printf("How many node you want in the list  ? ");
	scanf("%d",&numNodes);
	list=createLList(numNodes);
	do{
	printf("Enter the number of nodes to reverse your list into groups : ");
	scanf("%d",&k);
	}while(k<1||k>lenght_list(list));
	
	printf("\nThe list before the reversing : \n");
	displayList(list);
	list=Reverse_K_Group(list,k);
	printf("\nThe list after the reversing : \n");
	displayList(list);
	
	return 0;
}
