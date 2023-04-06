#include "liste.h"

void addAtBeginning(Node_l **head, Data v)
{
	Node_l* newNode = (Node_l*)malloc(sizeof(Node_l));
	newNode->frunza = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node_l** head, Data v)
{
	Node_l *aux=*head;
	Node_l* newNode = (Node_l*)malloc(sizeof(Node_l)); 
	newNode->frunza = v; 
	if (*head == NULL) addAtBeginning(&*head, v);
	else {  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newNode;  
		newNode->next = NULL; 
	}
}

void display(Node_l *head)
{
	int i;
	while (head!=NULL){
		printf ("C%d ", head->frunza.id);
		printf("%s\n", head->frunza.path);
		
		head=head->next;
	}
	printf("\n");
}