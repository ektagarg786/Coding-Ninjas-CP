/*Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1*/

#include<bits/stdc++.h>
using namespace std;
int solve(int n, int m, vector<int> &u, vector<int> &v){
	int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0; 
        }
    }
    for(int i=0;i<m;i++){
        int f, s;
        f = u[i]-1;
        s = v[i]-1;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j] == 1){
                for(int k=0;k<n;k++){
                    if(edges[j][k] == 1 && edges[k][i] == 1){
                        count++;
                    }
                }
            }
        }
    }
    return count/6;
    for(int i=0;i<n;i++){
        delete edges[i];
    }
    delete [] edges;
    return 0;
}
