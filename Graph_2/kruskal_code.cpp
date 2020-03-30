/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5*/

#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src;
    int dest;
    int weight;
};
bool comparison(Edge a, Edge b){
    return a.weight < b.weight;
}
int get_parent(int v, int* parent){
    if(parent[v] == v)
        return v;
    return get_parent(parent[v], parent);
}
Edge* kruskal(Edge* edges, int v, int e){
    sort(edges, edges+e, comparison);
    Edge* output = new Edge[v-1];
    int* parent = new int[v];
    for(int i=0;i<v;i++){
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while(count < (v-1)){
        Edge curr_edge = edges[i];
        int src_parent = get_parent(curr_edge.src, parent);
        int dest_parent = get_parent(curr_edge.dest, parent);
        if(src_parent != dest_parent){
            output[count] = curr_edge;
            count++;
            parent[src_parent] = dest_parent;
        }
        i++;
    }
    return output;
}
int main(){
    int v, e;
    cin >> v >> e;
    Edge* edges = new Edge[e];
    for(int i=0;i<e;i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }
    Edge* output = kruskal(edges, v, e);
    for(int i=0;i<v-1;i++){
        if(output[i].src < output[i].dest){
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else{
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
        }
    }
    return 0;
}
