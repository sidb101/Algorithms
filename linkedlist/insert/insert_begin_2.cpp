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

int main(){
	// cout<<"hello worl!";
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Node* head = NULL;
	int a, b, c;
	cin>>a>>b>>c;

	Insert(&head, a);
	LLprint(head);

	Insert(&head, b);
	LLprint(head);
	
	Insert(&head, c);
	LLprint(head);

	return 0;
}