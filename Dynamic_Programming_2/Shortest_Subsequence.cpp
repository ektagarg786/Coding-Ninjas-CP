/*Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3*/

#include<bits/stdc++.h>
using namespace std;
int helper(string s1,int n1, string s2,int n2, int**dp){
    if(n2==0)
        return 1;
    if(n1==0)
        return 1001;
    int k;
    if(dp[n1][n2]!=-1)
        return dp[n1][n2];
    int option1=helper(s1.substr(1),n1-1,s2,n2,dp);
    k=s2.find(s1[0]);
    if(k==-1)
        return 1;
    int option2=1+helper(s1.substr(1),n1-1,s2.substr(k+1),n2-k-1,dp);
    int ans;
    dp[n1][n2]=min(option1,option2);
    ans = dp[n1][n2];
    return ans;
}
int solve(string S,string V)
{
	int n1 = S.length();
    int n2 = V.length();
    int** dp=new int*[n1+1];
    for(int i=0;i<=n1;i++){
        dp[i]=new int[n2+1];
        for(int j=0;j<=n2;j++){
            dp[i][j]=-1;
        }
    }
    int ans=helper(S,n1,V,n2,dp);

    return ans;
}
