/*We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges, int start, bool* &visited, stack<int> &s){
    visited[start] = true;
    for(int i=0;i<edges[start].size();i++){
        int next = edges[start][i];
        if(visited[next] == false) 
            dfs(edges, next, visited, s);
    }
	s.push(start);
}

void dfs1(vector<int>* edges, int start, vector<int> &v, bool* &visited){
    visited[start] = true;
    for(int i=0;i<edges[start].size();i++){
        int next = edges[start][i];
        if(visited[next] == false) 
            dfs1(edges, next, v, visited);
    }
    v.push_back(start);
}

vector<vector<int>> bottom(vector<int>* edges, vector<int>* edgesT, int n){
    stack<int> s;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)  
        visited[i] = false;
    for(int i=0;i<n;i++){
        if(visited[i] == false) 
            dfs(edges, i, visited, s);
    }
    for(int i=0;i<n;i++)  
        visited[i] = false;
    vector<vector<int>> output;
    while(s.size() != 0){
        int ele = s.top();
        s.pop();
        if(visited[ele] != false) 
            continue;
        vector<int> v;
        dfs1(edgesT, ele, v, visited);
        output.push_back(v);
    }
    return output;
}
int main(){
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0) 
            break;
        vector<int>* edges = new vector<int>[n];
        vector<int>* edgesT = new vector<int>[n];
        for(int i=0;i<m;i++){
            int x, y;
            cin >> x >> y;
            edges[x-1].push_back(y-1);
            edgesT[y-1].push_back(x-1);
        }
        vector<vector<int>> ans = bottom(edges,edgesT,n);
        map<int,int> mp;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                mp[ans[i][j]] = i;
            }
        }
        vector<int> finals;
        for(int i=0;i<ans.size();i++){
            int f = 0;
            for(int j=0;j<ans[i].size();j++){
                int v = ans[i][j];
                for(int k=0;k<edges[v].size();k++){
                    int w = edges[v][k];
                    if(i != mp[w]) 
                        f=1;
                    if(f == 1) 
                        break;
                }
                if(f == 1) 
                    break;
            }
            if(f == 0){
                for(int j=0;j<ans[i].size();j++)
                    finals.push_back(ans[i][j]);
            }
        }
        sort(finals.begin(),finals.end());
        for(int i=0;i<finals.size();i++)
            cout << finals[i]+1 << " ";
        cout << endl;
    }
	return 0;
}
