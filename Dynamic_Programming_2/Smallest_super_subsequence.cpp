/*Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.*/

#include<bits/stdc++.h>
using namespace std;
int helper(char* s1, int n1, char* s2, int n2, int** dp){
    if(n1 == 0)
        return n2;
    if(n2 == 0)
        return n1;
    if(dp[n1][n2] > -1)
        return dp[n1][n2];
    for(int i=0;i<=n1;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=n2;i++){
        dp[0][i] = i;
    }
    if(s1[0] == s2[0])
        dp[n1][n2] =  1 + helper(s1+1, n1-1, s2+1, n2-1, dp);
    else
        dp[n1][n2] = min((1+ helper(s1+1, n1-1, s2, n2, dp)), (1+ helper(s1, n1, s2+1, n2-1, dp)));
    int ans = dp[n1][n2];
    return ans;
}
int smallestSuperSequence(char* s1, int n1, char* s2, int n2){ 
    int** dp = new int* [n1+1];
    for(int i=0;i<=n1;i++){
        dp[i] =  new int[n2+1];
        for(int j=0;j<=n2;j++){
            dp[i][j] = -1;
        }
    }
    int ans = helper(s1, n1, s2, n2, dp);
    for(int i=0;i<=n1;i++){
        delete [] dp[i];
    }
    delete []dp;
    return ans;
}
