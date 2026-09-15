#include <vector>
#include <iostream>

using namespace std;

class Graph{
private:
	int v, e;
	vector<vector<int>> adj;

	int rootChildren, turn, dfs_root;
	vector<int> artp, dfs_num, dfs_low, dfs_baap;

	void dfs(int u) {
		dfs_num[u] = dfs_low[u] = turn++;
		for(int i=0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i];
			if(dfs_num[v] == -1) {
				dfs_baap[v] = u;
				if(u==dfs_root)
					rootChildren++;
				dfs(v);
				dfs_low[u] = min(dfs_low[u], dfs_low[v]);
				if(dfs_low[v]>= dfs_num[u])
					artp[u] = 1;
			}
			else if(v!=dfs_baap[u]){
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			}
		}
	}

public:
	Graph(const vector<vector<int>> _adj, int _v, int _e){
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
		return artp;
	}
};

int main(){
    const int V = 4, E = 4;
    vector<vector<int>> adj(4);

    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2};

    Graph g1(adj, V, E);
    
    vector<int> artp = g1.getArticulationPoints();
    for (int i = 0; i < V; i++) {
        if (artp[i])
            cout << i << ", ";
    }
    cout << endl;
    
	return 0;
}