/*Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1*/

#include<bits/stdc++.h>
using namespace std;
void dfs_1(vector<int>* edges, int start, bool* &visited, stack<int> &s){
    visited[start] = true;
    for(int i=0;i<edges[start].size();i++){
        int adjacent = edges[start][i];
        if(! visited[adjacent]){
            dfs_1(edges, adjacent, visited, s);
        }
    }
    s.push(start);
}
void dfs_2(vector<int>* edges, int start, bool* &visited){
    visited[start] = true;
    for(int i=0;i<edges[start].size();i++){
        int adjacent = edges[start][i];
        if(! visited[adjacent]){
            dfs_2(edges, adjacent, visited);
        }
    }
}
int min_dominos(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    stack<int> s;
    for(int i=0;i<n;i++){
        if(! visited[i]){
            dfs_1(edges, i, visited, s);
        }
    }
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int count = 0;
    while(s.size() != 0){
        int element = s.top();
        s.pop();
        if(! visited[element]){
            dfs_2(edges, element, visited);
            count++;
        }
    }
    return count;
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
        }
        int ans = min_dominos(edges, n);
        cout << ans << endl;
    }
	return 0;
}
