#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

enum GraphColor {
    WHITE,
    BLACK
};

bool checkBipartite(vector<vector<int>> &adj) {
    int startNode = 0;
    unordered_set<int> whiteSet, blackSet;
    queue<int> bfsQueue;

    bfsQueue.push(startNode);
    whiteSet.insert(startNode);


}


int main(){
    vector<vector<int>> adjList = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2, 4, 5},
        {2, 3, 5},
        {3, 4} 
    };
    cout << "Graph is Bipartite: " << checkBipartite(adjList) << endl;

    adjList = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    }
    cout << "Graph is Bipartite: " << checkBipartite(adjList) << endl;

    return 0;
}