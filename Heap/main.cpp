#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Heap{
private:
	vi heap;
	int size;

int left(int idx) {return idx<<1;}
int right(int idx) {return (idx<<1) + 1;}
int parent(int idx) {return idx>>1;}

void swap(int i, int j) {
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}

void heapifyDown(){
	// start from root
	int idx = 1;

	// bubble down to correct position for root
	while (left(idx) <= size)  {
		int smaller = left(idx);
		if(right(idx) <= size and heap[right(idx)]<heap[smaller])
			smaller = right(idx);
		if (heap[idx] > heap[smaller]){
			swap(idx, smaller);
			idx = smaller;
		}
		else
			break;
	}

}

void heapifyUp() {
	// take the last element
	int idx = size;

	// keep comparing with parent until root
	while (parent(idx)>0 && (heap[parent(idx)]>heap[idx])){
		swap(idx, parent(idx));
		idx = parent(idx);
	}

}

public:
	Heap(){
		heap = vi {0}; // 1 based indexing
		size = 0;
	}
	void push(int x){
		heap.push_back(x);
		size++;
		heapifyUp();
	}

	int top(){
		if (size>0){
			return heap[1];
		}else
			return -1;
	}

	void pop(){
		if(size==0)
			return;
		heap[1] = heap[size];
		heap.pop_back();
		size--;
		heapifyDown();
	}

	void printHeap(){
		for (auto &i:heap) {
			cout<<i<<" ";
		}cout<<endl;
	}

};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Heap hp;
	vi arr = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
	for(auto &i: arr) {
		hp.push(i);
	}
	
	hp.printHeap();
	cout<<hp.top()<<endl;
	hp.pop();
	hp.printHeap();
	// cout<<"hello world!"<<endl;

	return 0;
	
}