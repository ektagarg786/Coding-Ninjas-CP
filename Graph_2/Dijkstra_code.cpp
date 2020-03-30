/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5*/

#include<bits/stdc++.h>
using namespace std;
int get_min_vertex(int* distance, int v, bool* visited){
    int min_vertex = -1;
    for(int i=0;i<v;i++){
        if(! visited[i] && ((min_vertex == -1) || (distance[min_vertex] > distance[i])))
            min_vertex = i;
    }
    return min_vertex;
}
void dijkstra_mst(int** edges, int v){
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    int* distance = new int[v];
    for(int i=0;i<v;i++){
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int i=0;i<v-1;i++){
        int min_vertex = get_min_vertex(distance, v, visited);
        visited[min_vertex] = true;
        for(int j=0;j<v;j++){
            if(edges[min_vertex][j] != 0 && !visited[j]){
                if(distance[j] >  distance[min_vertex] + edges[min_vertex][j]){
                    distance[j] = distance[min_vertex] + edges[min_vertex][j];
                }
            }
        }
    }
    for(int i=0;i<v;i++){
            cout << i << " " << distance[i] << endl;
    }
    delete [] distance;
    delete [] visited;
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
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    dijkstra_mst(edges, v);
    for(int i=0;i<v;i++){
        delete edges[i];
    }
    delete [] edges;
    return 0;
}
