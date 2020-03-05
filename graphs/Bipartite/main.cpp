#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class Graph {
	private:
	vector<vector<ii>> adj;
	int v, e;

	bool isBipartite(int src) {
		vi marked(v, -1); // flags
		queue<int> qq; // queue init
		qq.push(src);
		int color = 1; // color init
		marked[src] = color;
		color = 1-color; // flip
		while (!qq.empty()) {
			int u = qq.front();
			qq.pop();
			for(int i=0; i<adj[u].size(); i++){
				int v = adj[u][i].first;
				if(marked[v]!=-1){
					if(marked[v]==marked[u])
						return false;
					else
						continue;
				}
				qq.push(v);
				marked[v] = color;
			}
			color = 1-color;
		}
		return true;
	}

	public:
	Graph(const vector<vector<ii>> & _adj, int _v, int _e) {
		adj = _adj;
		v = _v;
		e = _e;
	}

	bool isBipartite(){
		return isBipartite(0);
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--) {
		int v, e;
		cin>>v>>e;
		vector<vector<ii>> adj(v, vector<ii> ());
		for(int i=0; i<e; i++) {
			int s, t, w=1;
			cin>> s>> t;
			adj[s-1].push_back(ii(t-1, w));
			adj[t-1].push_back(ii(s-1, w));
		}
		Graph g1(adj, v, e);
		cout<<"Bipartite: "<<(g1.isBipartite()?"true":"false")<<endl;

	}
	// cout<<"hello world!"<<endl;
	return 0;
	
}