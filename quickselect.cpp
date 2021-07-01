// To get kth smallest element in unsorted list 
// Complexity - O(lgn)

#include <iostream>
using namespace std;

int partition(int *A, int L, int R) {
    int pivot=A[L], i=L+1;
    for(int j=L+1; j<=R; j++){
        if(A[j] < pivot)
            swap(A[j], A[i]), i++;
    }
    swap(A[i-1], A[L]);
    return i-1;
}

int quickselect(int *A, int L, int R, int k) {
    int p = partition(A, L, R); // key-idea: after partition, pivot is placed at the same place as in sorted list
    if(p==k) 
        return A[p];
    else if(p<k)
        quickselect(A, p+1, R, k);
    else
        quickselect(A, L, p-1, k);
}

int main() {
    int arr[] = {5, 1, 6, 9, 3, 10, 7, 4, 8, 0, 2}; // random.shuffle(list(range(11))) ## simple testcase: kth smallest = k
    cout << quickselect(arr, 0, 10, 4); // 4
    return 0;
}
