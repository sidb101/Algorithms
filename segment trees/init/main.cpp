#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree{
private:
	vi A, st;
	int n;

	int left(int n){ return (n<<1);}
	int right(int n){ return (n<<1) + 1;}

	void build(int p, int L, int R){
		if(L==R) {
			st[p] = L;
			return;
		}
		int k = (L+R)/2;
		build(left(p), L, k);
		build(right(p), k+1, R);
		int x, y;
		x = st[left(p)];
		y = st[right(p)];
		st[p] = A[x]>A[y]?y:x;
		return;
	}

	int query(int p, int i, int j, int L, int R) {
		// if outside the range
		if(j<L || i>R)
			return -1;
		
		// if completely inside
		if(j<=R && i>=L)
			return st[p];

		int mid = (i+j)/2;
		int p1 = query(left(p), i, mid, L, R);
		int p2 = query(right(p), mid+1, j, L, R);

		if(p1==-1)
			return p2;
		else if(p2==-1)
			return p1;

		return A[p1]<=A[p2]?p1:p2;
	}

	void update(int p, int i, int j, int pos, int val){
		if(i==j){
			A[pos] = val;
			return;
		}
		int mid = (i+j)/2;
		if(pos<=mid)
			update(left(p), i, mid, pos, val);
		else
			update(right(p), mid+1, j, pos, val);
		int x, y;
		x = st[left(p)];
		y = st[right(p)];
		st[p] = A[x]<=A[y]?x:y;
	}

public:	
	SegmentTree(const vi & _A) {
		A = _A;
		n = (int)A.size();
		st.assign(4*n, 0);
		build(1, 0, n-1);
	}
	
	int rmq(int i, int j) { 
		return query(1, 0, n - 1, i, j); 
	}
	
	void update(int pos, int val) {
		update(1, 0, n-1, pos, val);
	}

	void printT() {
	    for(auto n: st) {
	        cout<<n<<" ";
	    }
	    cout<<endl;
	}
	
};

int main(){
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
	vi A(arr, arr + 7);
	SegmentTree st(A);
	
	st.printT();

	st.update(0, 2);

	st.printT();
	
	printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // answer = index 2
	printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 5

	//cout<<"hello world!"<<endl;

	return 0;
	
}