
#include<bits/stdc++.h>

using namespace std;

void Merge(int *A, int *L, int nL, int *R, int nR){
    int i=0, j=0, k=0;
    while(i<nL && j<nR){
        if (L[i]<R[j]){
            A[k++]=L[i++];
        }
        else{
            A[k++]=R[j++];
        }
    }
    // for leftover elements in L, if any
    while(i<nL){
        A[k++]=L[i++];
    }
    // for leftover elements in R, if any
    while(j<nR){
        A[k++]=R[j++];
    }
}

void MergeSort(int *A, int n){
    if(n>1){
        int mid=n/2;
        int *L=new int[mid];
        int *R=new int[n-mid];

        for(int i=0;i<mid;i++)L[i]=A[i];
        for(int i=mid;i<n;i++)R[i-mid]=A[i];

        MergeSort(L, mid);
        MergeSort(R, n-mid);
        Merge(A, L, mid, R, n-mid);

        delete L;
        delete R;

    }
}

int main(){

    cout<<"\nTest for Merge Logic ...\n";
    int L[]={1, 2, 4};
    int R[]={3, 5, 6, 7};
    int A[]={0, 0, 0, 0, 0, 0, 0};
    Merge(A, L, 3, R, 4);
    for(int i=0;i<7;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    cout<<"\nTest for MergeSort Logic ...\n";
    int arr[]={3, 4, -1, 2, 7, -5};
    MergeSort(arr, 6);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}




