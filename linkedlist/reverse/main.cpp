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

void reverse(Node** head, Node* prev){
	// in-place
	if ((*head)->next==NULL){
		(*head)->next = prev;
		return;
	}
	Node *temp = (*head);
	(*head) = (*head)->next;
	temp->next = prev;
	reverse(head, temp);
}

Node* reversed(Node* head, Node* prev) {
	// returning
	if(head==NULL)
		return prev;
	Node *tmp = head;
	head = head->next;
	tmp->next = prev;
	return reversed(head, tmp);
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
	reverse(&head, NULL);

	LLprint(head);

	LLprint(reversed(head, NULL));
	// cout<<"hello world!"<<endl;

	return 0;
	
}