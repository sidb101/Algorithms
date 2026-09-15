#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class Graph {
private:
	int v, e;
	vector<vi> AdjList;
	vi visited;

	void dfs(int node, vector<int> &arr) {
		visited[node] = 1;
		for(auto adj: AdjList[node]) {
			if(!visited[adj]){
				dfs(adj, arr);
			}
		}
		arr.push_back(node);
	}

public:
	Graph(int v){
		this->v = v;
		this->e = 0;
		AdjList.assign(v+1, vi());
	}
	void addEdge(int u, int v){
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
		this->e += 1;
	}

	vector<int> topSort(){
		visited.assign(v+1, 0);
		vi ts;
		dfs(1, ts);
		return ts;
	}
};


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int v, e;
	cin >> v >> e; 
	Graph g1(v);
	for(int i=0, u, v; i<e; i++) {
		cin >> u >> v;
		g1.addEdge(u, v);
	}

	cout<<"topological sort: ";
	for(auto vtx: g1.topSort())
		cout<<vtx<<" ";
	cout<<endl;

	return 0;
	
}