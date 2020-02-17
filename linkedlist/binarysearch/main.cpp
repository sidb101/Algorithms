#include<bits/stdc++.h>

using namespace std;

struct Node{
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

void Insert(Node** head, int data) {
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = (*head);
	(*head) = tmp;
}

Node* midLL(Node* head, Node* last){
	if(head==NULL)
		return NULL;

	Node* slow = head;
	Node* fast = head;

	while(fast!=last && fast->next!=last){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void binarySearch(Node* start, Node* last, int val) {
	// search val in given LL
	if(start==last){
		cout<< "Not Present"<<endl;
		return;
	}

	Node* midl = midLL(start, last);
	if (midl->data == val){
		cout<< "present"<<endl;
		return;
	}
	else if (midl->data < val){
		binarySearch(midl->next, last, val);
	}else {
		binarySearch(start, midl, val);
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, x;
	Node* head = NULL;

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x;
		Insert(&head, x);
	}

	LLprint(head);

	// Node* midl = midLL(head, NULL);
	// cout << "middle element: " << midl->data;

	binarySearch(head, NULL, 2);
	binarySearch(head, NULL, 8);
	binarySearch(head, NULL, 12);
	binarySearch(head, NULL, 4);
	binarySearch(head, NULL, 5);
	binarySearch(head, NULL, 1);
	binarySearch(head, NULL, 19);

	// cout<<"hello world!"<<endl;

	return 0;
	
}