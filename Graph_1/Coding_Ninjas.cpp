/*Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1*/

#include<bits/stdc++.h>
using namespace std;
int dfs(char graph[][MAXN], int n, int m, int i, int j, char* s, int size, bool** visited){
    visited[i][j] = true;
    if(i==n-1 && j==m-1){
        if(graph[i][j] == s[0] && size>0) 
            return 1;
    }
    if(size == 0)
        return 1;
    int ans;
        if(graph[i-1][j] == s[0] && i-1 >= 0 && j >=0 && size > 0 && ! visited[i-1][j]){
            ans = dfs(graph, n, m, i-1, j, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i-1][j+1] == s[0] && i-1 >= 0 && j+1 >=0 && size > 0 && ! visited[i-1][j+1]){
            ans = dfs(graph, n, m, i-1, j+1, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i-1][j-1] == s[0] && i-1 >= 0 && j-1 >=0 && size > 0 && ! visited[i-1][j-1]){
            ans = dfs(graph, n, m, i-1, j-1, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i][j+1] == s[0] && i >= 0 && j+1 >=0 && size > 0 && ! visited[i][j+1]){
            ans = dfs(graph, n, m, i, j+1, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i][j-1] == s[0] && i >= 0 && j-1 >=0 && size > 0 && ! visited[i][j-1]){
            ans = dfs(graph, n, m, i, j-1, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i+1][j] == s[0] && i+1 >= 0 && j >=0 && size > 0 && ! visited[i+1][j]){
            ans = dfs(graph, n, m, i+1, j, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i+1][j+1] == s[0] && i+1 >= 0 && j+1 >=0 && size > 0 && ! visited[i+1][j+1]){
            ans = dfs(graph, n, m, i+1, j+1, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
        if(graph[i+1][j-1] == s[0] && i+1 >= 0 && j-1 >=0 && size > 0 && ! visited[i+1][j-1]){
            ans = dfs(graph, n, m, i+1, j-1, s+1, size-1, visited);
            if(ans == 1)
                return 1;
        }
    visited[i][j] = false;
    return 0;
}
int solve(char graph[][MAXN], int n, int m){
    char s[] = "CODINGNINJA";
    int size = strlen(s);
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == s[0] && ! visited[i][j]){
                int x = dfs(graph, n, m, i, j, s+1, size-1, visited);
                if(x == 1)
                    return 1;
            }         
        }
    }
    return 0;
}
