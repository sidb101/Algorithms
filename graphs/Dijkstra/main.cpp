#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class Graph{
private:
	int v, e;
	vector<vector< ii >> adj;

	vi d; // storing the shortest distance
	vi p; // storing the traces

	void resetSP(){
		d.assign(v, INT_MAX);
		p.assign(v, 0);
	}

public:
	Graph(const vector<vector< ii >> &_adj, int _v,  int _e) {
		adj = _adj;
		v = _v;
		e = _e;
		resetSP();
	}

	void dijkstra(int src) {
	/*  For given graph calculates shortest distance for all nodes
		in G; run printSP, printTrace to see reflected change
	*/
		resetSP();
		d[src] = 0; p[src]=src;
		vector<bool> picked(v, false);

		for(int i=0; i<v; i++) {  // Set picked=true for v vertices
			// Pick unmarked vertex with min weight 
			int next=0, minw=INT_MAX;
			for(int j=0; j<v; j++)
				if(!picked[j] && d[j]<minw){
					next = j;
					minw = d[j];
				}
			picked[next] = true;

			// Refresh minimum for neighbours of picked
			for(auto nbr: adj[next]) {
				int to, w;
				to = nbr.first;
				w = nbr.second;
				if((d[next]+w)<d[to]){
					p[to] = next; // store parent
					d[to] = d[next]+w;
				}
			}
		}
	}

	void printSP() {
		for(auto w: d) {
			cout<<w<<" ";
		}cout<<endl;
	}

	void printTrace() {
		for(auto x: p) {
			cout<<x<<" ";
		}cout<<endl;
	}

};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int v, e;
	cin>>v>>e;
	
	int i, j, w;
	vector<vector<ii>> adj(v, vector<ii>());
	for(int c=0; c<e; c++) {
		cin>>i>>j>>w;
		adj[i].push_back(ii(j, w));
		adj[j].push_back(ii(i, w));
	}

	// Create graph
	Graph g(adj, v, e);

	// Run Dijkstra's Algorithm, 0 as source node
	g.dijkstra(0);

	// Get Results
	g.printSP();
	g.printTrace();

	return 0;
	
}

(select row_number() over partition by(rider) order by ride_time desc as ride_no)
