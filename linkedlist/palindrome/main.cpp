#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

void printLL(Node* head) {
	while(head!=NULL){
		cout << (head->data) << " ";
		head = head->next;
	}
	cout<<endl;
}

void insert(Node** head, int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = (*head);
	(*head) = temp;
}

bool isPalin(Node* head1, Node** head2) {
	if (head1==NULL)
		return true;
	bool x = isPalin(head1->next, head2);
	bool y = head1->data==(*head2)->data;
	//cout<<"h1: "<< (head1->data)<<", h2: "<<((*head2)->data)<<endl;
	*head2 = (*head2)->next;
	return x&y?true:false;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Node* head = NULL;
	int n, x;  
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x;
		insert(&head, x);
	}

	printLL(head);
	Node **tmp = &head;
	cout<<"LL is palindrome: "<< isPalin(head, tmp)<<endl;

	// cout<<"hello world!"<<endl;

	return 0;
	
}