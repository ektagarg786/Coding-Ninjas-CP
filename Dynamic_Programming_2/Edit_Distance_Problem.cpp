/*Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2*/

#include<bits/stdc++.h>
using namespace std;
// int edit_Distance_Helper(string s1, string s2, int m, int n,  int** dp){
//     if(m == 0)
//         return n;
//     if(n == 0)
//         return m;
//     if(dp[m][n] > -1)
//         return dp[m][n];
//     int ans;
//     if(s1[0] == s2[0])
//         ans = edit_Distance_Helper(s1.substr(1),s2.substr(1),m-1,n-1,dp);
//     else{
//         int option1 = edit_Distance_Helper(s1.substr(1), s2.substr(1), m-1, n-1, dp);
//         int option2 = edit_Distance_Helper(s1.substr(1), s2, m-1, n, dp);
//         int option3 = edit_Distance_Helper(s1, s2.substr(1), m, n-1, dp);
//         ans = 1 + min(option1, min(option2, option3));
//     }
//     dp[m][n] = ans;
//     return ans;
// }
// int editDistance(string s1, string s2){
//     int m = s1.length();
//     int n = s2.length();
//     int** dp = new int* [m+1];
//     for(int i=0;i<=m;i++){
//         dp[i] = new int[n+1];
//         for(int j=0;j<=n;j++){
//             dp[i][j] = -1;
//         }
//     }
//     int ans = edit_Distance_Helper(s1, s2, m, n, dp);
//     for(int i=0;i<=m;i++){
//         delete [] dp[i]; 
//     }
//     delete [] dp;
//     return ans;
// }
//                                        ///////////////////////////////////OR

int editDistance(string s1, string s2){
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
        dp[i][0] = i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i] == s2[n-j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));    
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
