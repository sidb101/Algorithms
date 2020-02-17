
#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

class LCA{
private:
	int n, m;
	vvi AdjList;
	vi euler, st, height, first;
	vb visited;

	int left(int idx) {
		return idx<<1;
	}

	int right(int idx) {
		return (idx<<1)+1;
	}

	void dfs(int node, int h) {
		first[node] = euler.size();
		height[node] = h;
		euler.push_back(node);
		visited[node] = true;
		for(auto neighbour: AdjList[node]) {
			if(!visited[neighbour]) {
				dfs(neighbour, h+1);
				euler.push_back(node);
			}
		}
	}

	void build(int p, int l, int r) {
		if(l==r) {
			st[p] = euler[l];
			return;
		}
		
		int mid = (l+r)/2;
		build(left(p), l, mid);
		build(right(p), mid+1, r);

		if ( height[st[left(p)]] <= height[st[right(p)]] )
			st[p] = st[left(p)];
		else
			st[p] = st[right(p)];
	}

	int query(int p, int i, int j, int L, int R){
		if(i>R || j<L)
			return -1;
		if(i>=L && j<=R)
			return st[p];
		
		int mid = (i+j)/2;
		int p1  = query(left(p), i, mid, L, R);
		int p2  = query(right(p), mid+1, j, L, R);
		
		if (p1==-1)
			return p2;
		else if (p2==-1)
			return p1;

		if (height[p1] <= height[p2])
			return p1;
		else
			return p2;

	}

public:
	LCA(const vvi &AdjL) {
		AdjList = AdjL;
		n = AdjList.size();
		
		visited.assign(n, false);
		height.assign(n, -1);
		first.assign(n, -1);
		euler.reserve(2*n);
		
		// perform dfs -> get euler, height, first
		dfs(1, 0);

		// build segtree for euler
		m = euler.size();
		st.assign(4*m, -1);
		build(1, 0, m-1);
		
	}

	int lca(int L, int R) {
		int l = first[L];
		int r = first[R];
		if(r<l)
			swap(l, r);
		return query(1, 0, m-1, l, r);
	}

	void printeuler(){
		for(auto x: euler){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	void printh(){
		for(auto x: height){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	void printfirst(){
		for(auto x: first){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	void printst(){
		for(auto it: st){
			cout<<it<<" ";
		}cout<<endl;
	}

};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, t;
	cin>>n;
	vvi	AdjList(n+1, vi());
	for(int i=1; i<=n; i++){
		cin>>t;
		AdjList[i].assign(t, 0);
		for(int j=0; j<t; j++){
			cin>>AdjList[i][j];
		}
	}

	LCA answer(AdjList);

	// answer.printst();

	// answer.printeuler();
	// answer.printh();
	// answer.printfirst();
	// answer.printst();

	int Q;
	cin>>Q;
	for(int q=0; q<Q; q++) {
		int l, r;
		cin>>l>>r;
		cout<<answer.lca(l, r)<<endl;
	}
	//cout<<"hello world!"<<endl;

	return 0;
	
}