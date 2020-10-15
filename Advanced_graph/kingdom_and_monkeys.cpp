/*This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.
Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
0 ≤ Ai ≤ 10^12
SAMPLE INPUT
1
4 3
1 2
2 3
3 1
1 2 3 5
SAMPLE OUTPUT
6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges, int sv, vector<int> &component, bool* visited){
    visited[sv] = true;
    component.push_back(sv);
    for(int i=0;i<edges[sv].size();i++){
        int adjacent = edges[sv][i];
        if(!visited[adjacent]){
            dfs(edges, adjacent, component, visited);
        }
    }
}
vector<vector<int>> getComponents(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    vector<vector<int>> output;
    for(int i=0;i<n;i++){
        if(! visited[i]){
            vector<int> component;
            dfs(edges,i,component,visited);
            output.push_back(component);
        }
    }
    delete[] visited;
    return output;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        for(int i=0;i<m;i++){
            int x, y;
            cin >> x >> y;
            edges[x-1].push_back(y-1);
            edges[y-1].push_back(x-1);
        }
        long long* arr = new long long[n];
        for(int i=0;i<n;i++) 
            cin >> arr[i];
        vector<vector<int>> ans = getComponents(edges, n);
        long long max = 0;
        for(int i=0;i<ans.size();i++){
            long long sum = 0;
            for(int j=0;j<ans[i].size();j++){
                sum = sum + arr[ans[i][j]];
            }
            if(sum > max) 
                max = sum;
        }
        cout << max << endl;
    }
	return 0;
}
