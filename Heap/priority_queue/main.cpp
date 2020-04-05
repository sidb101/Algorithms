#include <bits/stdc++.h>
using namespace std;

template<class t, class u>
void printHeap(priority_queue<t, vector<t>, u> heap) {
    priority_queue<t, vector<t>, u> newHeap = heap;
    while(newHeap.size()) {
        cout<<newHeap.top()<<" ";
        newHeap.pop();
    }
    cout<<"\n";
}

int main() {
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, less<int>> maxheap;
    
    minheap.push(1); minheap.push(2);
    maxheap.push(1); maxheap.push(2);
    
    printHeap<int, greater<int>>(minheap);
    printHeap<int, less<int>>(maxheap);
	// your code goes here
	return 0;
}