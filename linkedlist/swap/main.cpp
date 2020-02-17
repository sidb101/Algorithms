#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void LLprint(Node* head){
	while(head!=NULL){
		cout << head->data << " " ;
		head = head->next;
	}
	cout<<endl;
}

void Insert(Node** ptrToHead, int data){
	// create a new node, pointed by tmp
	Node* tmp = new Node;

	// point tmp->next to head
	tmp->next=(*ptrToHead);
	tmp->data=data;

	// head = tmp
	(*ptrToHead) = tmp;

}

void LLswap(Node** head, int xval, int yval){
	// assume that x, y will always be present in the list
	if(xval==yval)
		return;

	Node *xprev=NULL, *yprev=NULL, *x=(*head), *y=(*head);

	// find xprev, x
	while (x!=NULL && x->data!=xval){
		xprev = x;
		x     = x->next;
	}

	while (y!=NULL && y->data!=yval){
		yprev = y;
		y     = y->next;
	}

	// Set next pointers for prev elements
	if(xprev!=NULL) {
		xprev->next = y;
	}
	else 
		(*head) = y;

	if(yprev!=NULL){
		yprev->next = x;
	}
	else
		(*head) = x;

	// Swap next pointers for x and y
	Node* tmp = x->next;
	x->next = y->next;
	y->next = tmp;

	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Node* head = NULL;
	int n, x;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x;
		Insert(&head, x);
	}

	LLprint(head);

	LLswap(&head, 4, 8);
	LLprint(head);

	LLswap(&head, 2, 8);
	LLprint(head);


	// cout<<"hello world!"<<endl;

	return 0;
	
}