/*A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no*/

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
