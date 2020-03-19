/*Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = pow(10,9)+7;
int ans(int h, ll dp[])
{
    if(h == 0 || h == 1)
        return 1;
    
    if(dp[h]!=0)
    {
        return dp[h];
    }
     ll x = ans(h-1,dp);
     ll y = ans(h-2,dp);
     dp[h]=((((((x%m) * (x%m)%m))%m) + (((2*((x%m)*(y%m)))%m)%m))%m);
     return dp[h];
}

int balancedBTs(int h){
    ll dp[100]={0};
    return ans(h,dp); 
}
