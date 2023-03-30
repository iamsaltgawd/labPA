#include "stive.h"

Data top(Node *top){
	if (isEmpty(top)) return INT_MIN;
	return top->val;
} 

void push(Node**top, Data v) {
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	*top=newNode;
}

Data pop(Node**top) {
	if (isEmpty(*top)) return INT_MIN;
	Node *temp=(*top); 		
	Data aux=temp->val;	
	*top=(*top)->next;      		
	free(temp);
	return aux;
}

int isEmpty(Node*top){
	return top==NULL;
}
	
void deleteStack(Node**top){
	Node  *temp;
	while (!isEmpty(*top)) {
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}

void checkP() {
	Node *top = NULL;
    char sir[]="a(b)c)def()(\0";
	int *pozitii = NULL, *temp = NULL, nr = 1, j = 0;

	int i = 0, n = strlen(sir);
    
	for (i = 0; i < n; i++) {
		if (sir[i] == '(') {
			push(&top, i);
		} else if (sir[i] == ')') {
			if (pop(&top) == (Data) INT_MIN) {
				temp = (int *)realloc(pozitii, nr * sizeof(int));
				pozitii = temp;
				pozitii[j++] = i;
				nr++;
			}
		}
	}

	while (!(isEmpty(top))) {
		pozitii[j++] = pop(&top);
	}
	
	if (j == 0) {
		printf("parantezele s ok\n");
		return;
	} else {
		printf("parantezele nu s bune \n");
		for (i = 0; i < j; i++) {
			printf("%d ", pozitii[i]);
		}
		printf("\n");
	}

	return;
}
