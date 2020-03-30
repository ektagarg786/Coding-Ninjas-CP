/*Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :*/

#include<bits/stdc++.h>
using namespace std;
int get_path_DFS(int** edges, int v, int v1, int v2, bool* visited, vector<int> &q){
    visited[v1] = true;
     if(v1 == v2) {
        q.push_back(v1);
        return 1;
    }
    for(int i=0;i<v;i++){
        if(i == v1)
            continue;
        if(edges[v1][i] == 1){
            if(visited[i])
                continue;
            int ans = get_path_DFS(edges, v, i, v2, visited, q);
            if(ans == 1){
                q.push_back(v1);
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int v, e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i] = new int[v];
        for(int j=0;j<v;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    int v1, v2;
    cin >> v1 >> v2;
    // if(v1 == v2)
    //     cout << v2 << endl;
    if(edges[v1][v2] == 1){
        cout << v2 << " " << v1 << endl;
    }
    else{
        vector<int> q;
        int ans = get_path_DFS(edges, v, v1, v2, visited, q);
        if(ans == 1){
        for(int i=0;i<q.size();i++) 
            cout << q[i] << " ";
        }
    }
    return 0;
}
