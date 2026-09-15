#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> bfs(const vector<vector<int>> &adjList, const int startNode) {
    const int V = adjList.size();
    queue<int> bfsQueue;
    unordered_set<int> visited;
    vector<int> levelOrderTrace;

	bfsQueue.push(startNode);
	visited.insert(startNode);

	while(!bfsQueue.empty()) {
        int currSize = bfsQueue.size();
        while (currSize--) {
            int u = bfsQueue.front();
            bfsQueue.pop();
            levelOrderTrace.push_back(u);
            for (int v: adjList[u]) {
                if (visited.count(v) > 0) continue;
                visited.insert(v);
                bfsQueue.push(v);
            }
        }	
	}

    return levelOrderTrace;
}


int main(){
	const int V = 6, E = 8, startNode = 2;
    vector<vector<int>> adjList = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2, 4, 5},
        {2, 3, 5},
        {3, 4} 
    };

	vector<int> levelOrderTrace = bfs(adjList, startNode);
    for (int node: levelOrderTrace) {
        cout << node << ", ";
    }
    cout << endl;

    return 0;
}