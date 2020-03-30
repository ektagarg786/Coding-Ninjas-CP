/*Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1*/

#include<bits/stdc++.h>
using namespace std;
int code(char board[][MAXN], char str, int n, int m, int start, int end, int i, int j, bool** visited, int x){
    visited[i][j] = true;
    if((i==start+1 && j==end)||(i==start && j==end-1)||(i==start && j==end+1)||(i==start-1 && j==end)){
        if(x >= 4 && board[i][j] == str) 
            return 1;
    }
    if(i>=0 && j-1>=0){
        if(board[i][j-1] == str){
            if(visited[i][j-1] == false){
                int a = code(board, str, n, m, start, end, i, j-1, visited, x+1);
                if(a == 1) 
                    return 1;
            }
        }
    }
    if(i+1<n && j>=0){
        if(board[i+1][j]==str){
            if(visited[i+1][j]==false){
                int b = code(board, str, n, m, start, end, i+1, j, visited, x+1);
                if(b==1) 
                    return 1;
            }
        }
    }
    if(i>=0 && j+1<m){
        if(board[i][j+1]==str){
            if(visited[i][j+1]==false){
                int c = code(board, str, n, m, start, end, i, j+1, visited, x+1);
                if(c==1) 
                    return 1;
            }
        }
    }
    if(i-1>=0 && j>=0){
        if(board[i-1][j]==str){
            if(visited[i-1][j]==false){
                int d = code(board, str, n, m, start, end, i-1, j, visited, x+1);
                if(d==1) 
                    return 1;
            }
        }
    }
    visited[i][j] = false;
    return 0;
}

int solve(char board[][MAXN], int n, int m){
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int size = s.length();
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    while(size > 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == s[0]){
                    int x = 1;
                    int ans = code(board, s[0], n, m, i, j, i, j, visited, x);
                    if(ans == 1) 
                        return 1;
                }
            }
        }
        s = s.substr(1);
        size = size-1;
    }
    return 0;
}
    
