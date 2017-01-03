
/*
-> define inversion(i, j) as pair of indices i and j such that i<j && A[i]>A[j]
-> A modified version of Merge Sort can be used to find number of inversion in
   order nlog(n) time complexity.
-> This version still performs an in place sort on Original Array in O(nlogn)
   using a divide and conquer strategy.
*/
#include<bits/stdc++.h>

using namespace std;

int Merge(int *A, int *L, int nL, int *R, int nR){
    int i=0, j=0, k=0, split_inv_count=0;
    while(i<nL && j<nR){
        if (L[i]<=R[j])
            A[k++]=L[i++];
        else{
            A[k++]=R[j++];
            split_inv_count += nL-i;
        }
    }
    // for leftover elements in L, if any
    while(i<nL)
        A[k++]=L[i++];
    
    // for leftover elements in R, if any
    while(j<nR)
        A[k++]=R[j++];
    /* since inversions inside leftover elements are local to subarray L or R, 
       their contribution to split inversions is not counted. */
    return split_inv_count;
}

int MergeSort(int *A, int n){
    if(n>1){
        int mid=n/2;
        int *L=new int[mid];
        int *R=new int[n-mid];

        for(int i=0;i<mid;i++)L[i]=A[i];
        for(int i=mid;i<n;i++)R[i-mid]=A[i];

        int L_inv = MergeSort(L, mid);
        int R_inv = MergeSort(R, n-mid);
        int split_inv = Merge(A, L, mid, R, n-mid);

        delete L;
        delete R;
        return (L_inv + R_inv + split_inv);
    }
    else return 0;
}

int main(){
    cout<<"Test on {3, 4, 1, 2, 6, 5}\n";
    int arr[]={3, 4, 1, 2, 6, 5};
    cout<<"ans: "<<MergeSort(arr, 6)<<endl;
    return 0;
}




