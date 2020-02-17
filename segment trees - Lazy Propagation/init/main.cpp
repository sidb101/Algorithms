/*
Construct segment tree for array A(size n) with following specification
Query: 1 L R val 
	for all i in [L, R] set A[i] = val;
Query: 2 pos
	return A[pos]
*/
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

class SegmentTree{
private:
	int n;
	vi st;
	vb marked;

	int left(int i) {
		return (i<<1);
	}
	int right(int i) {
		return (i<<1) + 1;
	}
	void push(int idx){
		marked[left(idx)] = marked[right(idx)] = true;
		st[left(idx)] = st[right(idx)] = st[idx];
		marked[idx] = false;
	}

	void update(int p, int i, int j, int L, int R, int val) {
		if(i>R || j<L) { // if completely outside
			return;
		}
		if(marked[p]){ // if already marked
			if(!(i==j)){
				push(p);
			}
		}
		if(i>=L && j<=R) { // if completely inside
			st[p] = val;
			marked[p] = true;
			return;
		}

		int mid = (i+j)/2;
		update(left(p), i, mid, L, R, val);
		update(right(p), mid+1, j, L, R, val);
	}

	int query(int p, int i, int j, int pos) {
		if(i==j){
			return st[p];
		}
		if(marked[p])
			push(p);
		int mid = (i+j)/2;
		if(pos<=mid) {
			return query(left(p), i, mid, pos);
		}
		else{
			return query(right(p), mid+1, j, pos);
		}
	}
	
public:
	SegmentTree(int size) {
		n = size;
		st.assign(4*n, 0);
		marked.assign(4*n, false);
	}

	void update(int L, int R, int val) {
		update(1, 0, n-1, L, R, val);
	}

	int query(int idx) {
		return query(1, 0, n-1, idx);
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, q;
	int type, x1, x2, x3;

	cin>>n>>q;
	SegmentTree st(n);

	while(q--) {
		cin>>type;
		if(type==1) {
			cin>>x1>>x2>>x3;
			st.update(x1, x2, x3);
		}
		if(type==2) {
			cin>>x1;
			cout<<st.query(x1)<<endl;
		}
	}


	return 0;
	
}