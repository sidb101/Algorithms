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

void deleteKey(Node** head, int val) {

	Node *prev, *curr;
	prev = *head;
	curr = *head;

	if(*head==NULL){
		cout<<"Empty List!"<<endl;
		return;
	}
	if ((*head)->data==val){
		*head = (curr)->next;
		free(curr);
		return;
	}

	while (curr!=NULL){
		if (curr->data == val){
			prev->next = curr->next;
			free(curr);
			return;
		}
		prev=curr;
		curr=curr->next;
	}

}

void deleteAtIndex(Node** head, int idx) {
	Node *prev, *curr;
	prev = *head;
	curr = *head;

	int count=0;
	if (*head == NULL){
		cout<<"Enpty List";
		return;
	}
	if (idx==0){
		(*head) = (curr)->next;
		free(curr);
		return;
	}


	while (curr!=NULL){
		if (count == idx){
			prev->next = curr->next;
			free(curr);
			return;
		}
		prev=curr;
		curr=curr->next;
		count++;
	}

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

	deleteKey(&head, 2);
	LLprint(head);

	deleteKey(&head, 10);
	LLprint(head);

	deleteAtIndex(&head, 3);
	LLprint(head);
	// cout<<"hello world!"<<endl;

	return 0;
	
}