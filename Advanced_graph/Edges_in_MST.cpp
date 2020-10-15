/*You are given a connected weighted undirected graph without any loops and multiple edges.

Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.

Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input
The first line contains two integers n and m (2 ≤ n ≤ 10^5, ) — the number of the graph's vertexes and edges, correspondingly. Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 10^6, ai ≠ bi), where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or multiple edges.
Output
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Sample input 1
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
sample output 1
none
any
at least one
at least one
any
Sample input 2
3 3
1 2 1
2 3 1
1 3 2
sample output 2
any
any
none
sample input 3
3 3
1 2 1
2 3 1
1 3 1
sample output 3
at least one
at least one
at least one
Note
In the second sample the MST is unique for the given graph: it contains two first edges.

In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST.*/

#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int src;
    int dest;
    int weight;
    int index;
    int output;
    
};
bool comparison(Edge a, Edge b){
    return a.weight < b.weight;
}
bool comparison1(Edge a, Edge b){
    return a.index < b.index;
}

int get_parent(int v, int* parent){
    if(parent[v] == v)
        return v;
    return get_parent(parent[v], parent);
}

void kruskal(Edge* edges, int v, int e){
    sort(edges, edges+e, comparison);
    int* parent = new int[v+1];
    
    for(int i=0;i<v;i++){
        parent[i] = i;
    }
    
    int count = 0;
    int i;
    while(count < (v-1)){ 
        
        int j = count+1; 
        
        while(edges[j].weight == edges[count].weight &&j<v-1){
            j++;
        }
        
    vector<pair<int,int>> change; 
        
        for(int x=count;x<j;x++){   
            Edge curr_edge = edges[x];
            int src_parent = get_parent(curr_edge.src, parent);
            int dest_parent = get_parent(curr_edge.dest, parent);
            
          pair<int,int> p(max(src_parent,dest_parent),min(src_parent,dest_parent));
         change.push_back(p);
            
        }
        unordered_map<int,unordered_map<int,int>>check;
        
        for(int i=0;i<change.size();i++){            
            
            pair<int,int> p = change[i];
            
            if(p.first==p.second){
                        edges[count+i].output=2;
            }else{
                if(check.count(p.first)==1 && check[p.first].count(p.second)==1){
                 int pos=check[p.first][p.second];
                    edges[count+i].output=0;
                    edges[count+pos].output=0;
                }else{
                  check[p.first][p.second]=i;
                  edges[count+i].output=1;  
                }      
            }
        } 
        count = j;
    }
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
        edges[i].index = i;
    }
    kruskal(edges, v, e);
    sort(edges, edges+e, comparison1);
    for(int i=0;i<e;i++){
        if(edges[i].output == 1)
            cout << "any" << endl;
        else if(edges[i].output == 0)
            cout << "at least one" << endl;
        else
            cout << "none" << endl;
    }
    return 0;
}
