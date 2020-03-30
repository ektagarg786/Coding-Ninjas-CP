/*Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2.*/


#include<bits/stdc++.h>
using namespace std;
void dfs(int** edges, int v, int sv, bool* visited){
    visited[sv] = true;
    for(int i=0;i<v;i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i])
            dfs(edges, v, i, visited);
    }
}
int main(){
    int v, e, i;
    cin >> v >> e;
    int** edges = new int*[v];
    for(i=0;i<v;i++){
        edges[i] = new int[v];
        for(int j=0;j<v;j++){
            edges[i][j] = 0;
        }
    }
    for(i=0;i<e;i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[v];
    for(i=0;i<v;i++){
        visited[i] = 0;
    }
    dfs(edges, v, 0, visited);
    for(i=0;i<v;i++){
        if(visited[i] == 0){
            cout << "false" << endl;
            break;
        }
        if(i == v-1)
            cout << "true" << endl;
    }
    for(int i=0;i<v;i++){
        delete edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}
