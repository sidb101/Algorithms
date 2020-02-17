#include<bits/stdc++.h>

using namespace std;

class GraphEdge{
public:
	int src, dest, weight;
	GraphEdge(){
		src = -1;
		dest = -1;
		weight = 0;
	}

	GraphEdge(int x, int y, int z){
		src = x;
		dest = y;
		weight = z;
	}
};

class Graph {
public:
	int E, V;
	GraphEdge* edge;

	Graph(int e, int v, GraphEdge edges[]){
		E = e;
		V = v;
		edge = edges;
	}

	void printGraph(){
		cout<<"Vertices: "<<V<<endl;
		cout<<"Edges: "<<endl;
		for(int i=0; i<E; i++){
			cout << edge[i].src << " " << edge[i].dest << " " << edge[i].weight <<endl;
		}
	}
};



int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int v, e;
	cin>>v>>e;

	GraphEdge* edges = new GraphEdge[e];

	for(int i=0; i<e; i++) {
		int s, d;
		cin>>s>>d;
		edges[i].src  = s;
		edges[i].dest = d;
	}

	Graph gr(e, v, edges);

	gr.printGraph();
	// cout<<"hello world!"<<endl;

	return 0;
	
}