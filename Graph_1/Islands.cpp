/*An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 */

#include<bits/stdc++.h>
using namespace std;
void print_dfs(int** edges, int v, int sv, bool* visited){
    visited[sv] = true;
    for(int i=0;i<v;i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i])
            print_dfs(edges, v, i, visited);
    }
}
int dfs(int** edges, int v){
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i=0;i<v;i++){
        if(! visited[i]){
            print_dfs(edges, v, i, visited);
            count++;
        }
    }
    return count;
    delete[] visited;
}
int solve(int n, int m, vector<int>u, vector<int>v){
     int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int f, s;
        f = u[i] - 1;
        s = v[i] - 1;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int ans = dfs(edges, n);
    return ans;
    for(int i=0;i<n;i++){
        delete edges[i];
    }
    delete [] edges;
}
