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

Node* reverseK(Node* head, int cnt, int k, Node* prev){

	if(head==NULL){
		return prev;
	}

	if(cnt==k){
		Node* last = prev;
		while(last->next!=NULL)
			last = last->next;
		last->next = reverseK(head, 0, k, NULL);
		return prev;
	}
	else{
		Node* temp = head; 
		head = head->next; 
		temp->next = prev; 
		return reverseK(head, cnt+1, k, temp);		
	}

}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Node* head = NULL;
	int n, x, k;
	cin>>n>>k;
	// cout<<n<<k<<endl;
	for(int i=0; i<n; i++) {
		cin>>x;
		Insert(&head, x);
	}

	LLprint(head);

	LLprint(reverseK(head, 0, k, NULL));
	// cout<<"hello world!"<<endl;

	return 0;
	
}