#include "cozi.h"

Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

 void enQueue(Queue*q, Data v){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=NULL;

	if (q->rear==NULL) q->rear=newNode; 
	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear; 
}
 
Data deQueue(Queue*q) {  
	Node* aux; Data d;
	if (isEmptyQ(q)) return INT_MIN;
	
	aux=q->front; 
	d=aux->val;
	q->front=(q->front)->next;
	free(aux);
	return d;  	
} 

int isEmptyQ(Queue*q){
	return (q->front==NULL);
}

void deleteQueue(Queue*q){
	Node* aux;
	while (!isEmptyQ(q)){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}	

void reverse() {
	Queue *q = createQueue();
	int n = 6;
	Data i;

	for (i = 'a'; i < 'f'; i++) {
		enQueue(q, i);
	}

	Node *top = NULL;
	Data aux;
	
	while (!isEmptyQ(q)) {
		aux = deQueue(q);
		push(&top, aux);
	}

	while (!isEmpty(top)) {
		enQueue(q, pop(&top));
	}

	while (!isEmptyQ(q)) {
		printf("%c", deQueue(q));
	}
	printf("\n");
}