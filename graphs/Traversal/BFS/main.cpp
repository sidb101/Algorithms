#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> AdjList;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// input graph G(V, E)
	int V, E;
	cin >> V;
	AdjList.assign(V+1, vi()); 
	cin >> E;
	for(int i=0, u, v; i<E; i++) {
		cin >> u >> v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}

	// BFS
	queue<int> qq;
	vi visited(V+1, 0);
	qq.push(1);
	visited[1] = 1;
	while(!qq.empty()) {
		int f = qq.front();
		qq.pop();
		cout<<f<<" ";
		for(auto i : AdjList[f]){
			if(!visited[i]){
				visited[i]=1;
				qq.push(i);
			}
		}	
	}
	cout<<endl;

	// cout<<"hello world!"<<endl;

	return 0;
}