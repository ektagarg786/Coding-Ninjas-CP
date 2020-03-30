/*Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false*/


#include<bits/stdc++.h>
using namespace std;
int print_BFS(int**edges, int v, int v1, int v2, bool* visited){
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    while(!q.empty()){
        int current_vertex = q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(i == current_vertex) 
                continue;
            if(edges[current_vertex][i] == 1){
                if(visited[i]) 
                    continue;
                if(i == v2) 
                    return 1;
                q.push(i);
                visited[i] = true;
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
    for(int i=0;i<v;i++) 
        visited[i] = false;
    if(edges[v1][v2] == 1){
        cout << "true" << endl;
    }
    else{
        int ans = print_BFS(edges, v, v1, v2, visited);
        if(ans == 0)
            cout << "false" << endl;
        else
            cout << "true" << endl;
    }
    for(int i=0;i<v;i++){
        delete edges[i];
    }
    delete [] edges;
    delete [] visited;
    return 0;
}

