/*
Construct a Sparse Matrix for an Array A(size n) such that:
	1. It performs O(1) RMQ queries
	2. It does not take more than O(nlogn) to build
*/
#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class SparseMatrix{
private:
	int n;
	vi A;
	vector<vi> sprz;

	void buildMatrix(){
		for(int i=0; i<n; i++){
			sprz[i].push_back(i);
			for(int j=1; (i+(1<<j)-1) < n; j++)
				sprz[i].push_back(i);
		}
		for(int i=n-1; i>=0; i--) {
			for(int j=1; j<sprz[i].size(); j++) {
				if( A[sprz[i][j-1]] <= A[sprz[i+(1<<(j-1))][j-1]] ) 
					sprz[i][j] = sprz[i][j-1];
				else
					sprz[i][j] = sprz[i+(1<<(j-1))][j-1];
			}
		}
	}

public:
	SparseMatrix(const vi &_A){
		n = _A.size();
		A = _A;
		sprz.resize(n, vi());
		buildMatrix();
	}
	int rmq(int L, int R) {
		if (R<L || R>n || L<0) // invalid query
			return -1;
		int k = (int)log2(R-L+1);
		if(sprz[L][k] <= sprz[R-(1<<k)+1][k])
			return sprz[L][k];
		else
			return sprz[R-(1<<k)+1][k];
	}
	void printm(){
		cout<<"SPRZ: "<<endl;
		for(int i=0; i<n; i++) {
			for(int j=0; j<sprz[i].size(); j++)
				cout<<sprz[i][j]<<" ";
			cout<<endl;
		}
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vi A = {4, 5, 7, 6, 1, 2, 9};
	SparseMatrix sm(A);

	cout<<sm.rmq(0, 2)<<endl; // 0
	cout<<sm.rmq(3, 6)<<endl; // 4
	cout<<sm.rmq(1, 3)<<endl; // 1

	sm.printm();

	//cout<<"hello world!"<<endl;

	return 0;
	
}