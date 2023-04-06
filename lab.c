#include "lab.h"

Node* createNode(char type, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type; newNode->num = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* createTree() {
    Node *root;	
	root = createNode('Q',1);
	root->left = createNode('Q',2);
	root->right = createNode('Q',3);
	root->left->left = createNode('Q',4);
	root->left->right = createNode('Q',5);
	root->right->left = createNode('Q',6);
	root->right->right = createNode('C',2);	
	root->left->left->left = createNode('Q',7);
	root->left->left->right = createNode('Q',8);
	root->left->right->left = createNode('Q',9);
	root->left->right->right = createNode('C',3);
	root->right->left->left = createNode('C',4);
	root->right->left->right = createNode('Q',10);
	root->left->left->left->left = createNode('C',1);
	root->left->left->left->right = createNode('C',2);
	root->left->left->right->left = createNode('C',2);
	root->left->left->right->right = createNode('C',4);
	root->left->right->left->left = createNode('C',2);
	root->left->right->left->right = createNode('C',1);
	root->right->left->right->left = createNode('C',1);
	root->right->left->right->right = createNode('C',4);
	
	return root;
}

void parcurgere_preordine(Node *current, int pas, char *v){
	if(current->type == 'C'){
		printf("%c%d: ",current->type,current->num);
		int i;
		for(i=0;i<pas;i++) {
			printf("%c ",v[i]);
		}
		printf("\n");
		pas--;
	} else {
		v[pas]='d';
		pas++;
		parcurgere_preordine(current->left,pas,v);
		pas--;
		v[pas]='n';
		pas++;
		parcurgere_preordine(current->right,pas,v);
	}

}

void displayleaves() {

    Node *root = createTree();
	char path[4];
    parcurgere_preordine(root, 0, path);
    printf("\n");

}

void parcurgere_preordine_p2(Node *current, int pas, char *v, Node_l **cai){

	if(current->type == 'C'){
		Data tmp;
		tmp.id = current->num;
		tmp.path = (char *)malloc(pas * sizeof(char));
		int i;
		for(i=0;i<pas;i++) {
			tmp.path[i] = v[i];
		}
		tmp.pas = pas;
		pas--;

		addAtEnd(cai, tmp);

	} else {
		v[pas]='d';
		pas++;
		parcurgere_preordine_p2(current->left,pas,v, cai);
		pas--;
		v[pas]='n';
		pas++;
		parcurgere_preordine_p2(current->right,pas,v, cai);
	}

}

void displaypp(Node_l *cai, int v) {
	printf("\n");
	while (cai != NULL) {
		if (cai->frunza.id == v) {
			printf("%s\n", cai->frunza.path);
		}
		cai = cai->next;
	}
}

void displaypaths() {
	Node_l *cai = NULL;
	Node *root = createTree();
	char path[4];
	parcurgere_preordine_p2(root, 0, path, &cai);
	int *v = NULL, n = 0, i, ok;
	Node_l *p = cai;
	while (p != NULL) {
		ok = 0;
		for (i = 0; i < n; i++) {
			if (v[i] == p->frunza.id) {
				ok = 1;
			}
		}
		if (!ok) {
			n++;
			v = (int *)realloc(v, n * sizeof(int));
			v[n-1] = p->frunza.id;
		}

		p = p->next;
	}
//	display(cai);
	int ap[5] = {0};
	p = cai; 
	while (p != NULL) {
		for (i = 0; i < n; i++) {
			if (v[i] == p->frunza.id) {
				ap[v[i]]++;
			}
		}
		p = p->next;
	}
	for (i = 0; i < n; i++) {
		printf("C%d: %d", v[i], ap[v[i]]);
		if (ap[v[i]] == 1) {
			printf(" cale");
		} else {
			printf(" cai");
		}
		displaypp(cai, v[i]);
	}

} 