#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class DisjointSet{
private:
	int n;
	vi parent, rank;
	
public:
	DisjointSet(int n){
		this->n = n;
		parent.assign(n, 0);
		for(int i=0; i<n; i++) {
			parent[i] = i;
		}
		rank.assign(n, 0);
	}

	void union_set(int s1, int s2){
		int p1 = find_parent(s1), p2 = find_parent(s2);
		
		if (p1==p2)
			return;
		
		if (rank[p1] > rank[p2])
			parent[p2] = p1;
		else if(rank[p2] > rank[p1])
			parent[p1] = p2;
		else{
			parent[p1] = p2;
			rank[p2]++;
		}
	}

	int find_parent(int child){
		if (parent[child] == child)
			return child;
		int p = find_parent(parent[child]);
		parent[child] = p;
		return p;
	}

	void printset(){
		for(int i=0; i<n; i++)
			cout<<"i: "<<i<<", set: "<<find_parent(i)<<endl;
		cout<<endl;
	}

};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; 
	cin>>n>>m;

	DisjointSet djset(n);

	for(int i=0, a, b; i<n; i++) {
		cin >> a >> b;
		djset.union_set(a-1, b-1);
	}

	djset.printset();
	// cout<<"hello world!"<<endl;

	return 0;
	
}