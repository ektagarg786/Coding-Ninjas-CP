/*Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
int get_path_BFS(int** edges, int v, int v1, int v2, bool* visited, map<int,int> &m){
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    while(! q.empty()){
        int current_vertex = q.front();
        q.pop();
        for(int i=0;i<v;i++){
             if(i == current_vertex) 
                continue;
            if(edges[current_vertex][i] == 1){
                if(visited[i]) 
                    continue;
                // if(i == v2) 
                //     return 1;
                q.push(i);
                m.insert({i, current_vertex});
                visited[i] = true;
                if(i == v2)
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
    int v1, v2;
    cin >> v1 >> v2;
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    if(edges[v1][v2] == 1)
        cout << v2 << " " << v1 << endl;
    else{
        map<int, int> m;
        int ans = get_path_BFS(edges, v, v1, v2, visited, m);
        if(ans == 1){
            int a = v2;
            while(a != v1){
                cout << a << " ";
                a = m[a];
            }
            cout << v1 << endl;
        }
    }    
    return 0;
}
