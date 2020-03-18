/*Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3*/

#include<bits/stdc++.h>
using namespace std;
// int lcshelper(string s1, string s2, int m, int n,  int** dp){
//     if(m == 0 || n == 0)
//         return 0;
//     if(dp[m][n] > -1)
//         return dp[m][n];
//     int ans;
//     if(s1[0] == s2[0])
//         ans = 1 + lcshelper(s1.substr(1), s2.substr(1), m-1, n-1, dp);
//     else{
//         int option1 = lcshelper(s1.substr(1), s2, m-1, n, dp);
//         int option2 = lcshelper(s1, s2.substr(1), m, n-1, dp);
//         ans = max(option1, option2);
//     }
//     dp[m][n] = ans;
//     return ans;
// }
// int lcs(string s1, string s2){
//     int m = s1.length();
//     int n = s2.length();
//     int** dp = new int* [m+1];
//     for(int i=0;i<=m;i++){
//         dp[i] = new int[n+1];
//         for(int j=0;j<=n;j++){
//             dp[i][j] = -1;
//         }
//     }
//     int ans = lcshelper(s1, s2, m, n, dp);
//     for(int i=0;i<=m;i++){
//         delete [] dp[i]; 
//     }
//     delete [] dp;
//     return ans;
// }
                                       ///////////////////////////////////OR

int lcs(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int** dp = new int* [m+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i] == s2[n-j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int ans = dp[m][n];
    for(int i=0;i<=m;i++){
        delete [] dp[i]; 
    }
    delete [] dp;
    return ans;
}
