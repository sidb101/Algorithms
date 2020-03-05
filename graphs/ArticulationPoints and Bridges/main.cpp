#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class Graph{
private:
	int v, e;
	vector<vector<ii>> adj;

	int rootChildren, turn, dfs_root;
	vi artp, dfs_num, dfs_low, dfs_baap;

	void dfs(int u) {
		dfs_num[u] = dfs_low[u] = turn++;
		for(int i=0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i].first;
			if(dfs_num[v] == -1) {
				dfs_baap[v] = u;
				if(u==dfs_root)
					rootChildren++;
				dfs(v);
				dfs_low[u] = min(dfs_low[u], dfs_low[v]);
				if(dfs_low[v]>= dfs_num[u])
					artp[u] = 1;
				// if(dfs_low[v]>dfs_num[u]) {cout<<"bridge between: "<<u<<" & "<<v<<endl;}
			}
			else if(v!=dfs_baap[u]){
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			}
		}
	}

public:
	Graph(const vector<vector<ii>> _adj, int _v, int _e){
		adj = _adj;
		v = _v;
		e = _e;
	}

	vector<int> getArticulationPoints() {
		artp.assign(v, 0);
		dfs_num.assign(v, -1);
		dfs_low.assign(v, -1);
		dfs_baap.assign(v, -1);
		turn = 0;
		rootChildren = 0;
		dfs_root = 0;
		dfs(dfs_root);
		artp[dfs_root] = (rootChildren > 1);
		// for(auto it: dfs_num)
		// 	cout<<(it)<<" ";
		// cout<<endl;
		// for(auto it: dfs_low)
		// 	cout<<(it)<<" ";
		// cout<<endl;
		return vi(artp.begin(), artp.end());
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// cout<<"hello world!"<<endl;
	int t;
	cin>>t;
	while(t--) {
		int v, e;
		cin>>v>>e;
		vector<vector<ii>> adj(v, vector<ii>());
		for(int i=0; i<e; i++) {
			int s, t, w=1;
			cin>>s>>t;
			adj[s-1].push_back(ii(t-1, w));
			adj[t-1].push_back(ii(s-1, w));
		}
		Graph g1(adj, v, e);
		int i=1;
		for(auto it: g1.getArticulationPoints()) {
			cout<<(i++)<<" - Articulation Point: "<<(it?"true":"false")<<endl;
		}
	}

	return 0;
	
}