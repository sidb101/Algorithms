// c++ program to insert in the beginning of a linked list

#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void LLprint(Node* head){
	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* Insert(Node* head, int data){
	// create a new node, pointed by tmp
	Node* tmp = new Node();

	// assign temp->next to head
	tmp->data = data;
	tmp->next = head;

	// head = tmp
	head = tmp;

	// return head
	return head;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// cout<<"hello world!"<<endl;
	Node* head = NULL;
	int a, b, c;
	cin>>a>>b>>c;

	head = Insert(head, a);
	LLprint(head);
	head = Insert(head, b);
	LLprint(head);
	head = Insert(head, c);
	LLprint(head);
	

	return 0;
	
}