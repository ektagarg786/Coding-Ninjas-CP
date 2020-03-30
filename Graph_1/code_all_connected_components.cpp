/*Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2*/

#include<bits/stdc++.h>
using namespace std;
void print_dfs(int** edges, int v, int sv, bool* visited, vector<int> &q){
    visited[sv] = true;
    q.push_back(sv);
    for(int i=0;i<v;i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i])
            print_dfs(edges, v, i, visited, q);
    }
}
void dfs(int** edges, int v){
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int i=0;i<v;i++){
        if(! visited[i]){
            vector<int> q;
            print_dfs(edges, v, i, visited, q);
            sort(q.begin(), q.end());
            for(int j=0;j<q.size();j++){
                cout << q[j] << " ";
            }
            cout << endl;
        }
    }
    delete[] visited;
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
    dfs(edges, v);
    for(int i=0;i<v;i++){
        delete edges[i];
    }
    delete [] edges;
    return 0;
}
