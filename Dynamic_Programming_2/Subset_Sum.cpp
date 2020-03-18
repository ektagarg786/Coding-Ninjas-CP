/*Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes*/

#include <bits/stdc++.h>
using namespace std;
int subset_sum(int n, int* val, int sum){
    // bool** dp = new bool* [n+1];
    // for(int i=0;i<=n;i++){
    //     dp[i] = new bool[sum+1];
    // }
    // for(int i=0;i<=sum;i++){
    //     dp[0][i] = false;
    // }
    // for(int i=0;i<=n;i++){
    //     dp[i][0] = true;
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=sum;j++){
    //         dp[i][j] = dp[i-1][j];
    //         if(j >= val[i-1]){
    //             dp[i][j] = dp[i][j] || dp[i-1][j-val[i-1]];
    //         }
    //     }
    // }
    // int ans = dp[n][sum];
    // for(int i=0;i<=n;i++){
    //     delete [] dp[i];
    // }
    // delete [] dp;
    bool** dp = new bool* [2];
    for(int i=0;i<=1;i++){
        dp[i] = new bool[sum+1];
    }
    for(int i=0;i<=sum;i++){
        dp[0][i] = false;
    }
    dp[0][0] = true;
    dp[1][0] = true;
    int flag = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[flag][j] = dp[flag ^ 1][j];
            if(j >= val[i-1]){
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j-val[i-1]];
            }
        }
        flag = flag ^ 1;
    }
    int ans = dp[flag ^ 1][sum];
    for(int i=0;i<=1;i++){
        delete [] dp[i];
    }
    delete [] dp;
     return ans;
 }
int main()
{
    int n, sum;
    cin >> n;
    int val[n];
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    cin >> sum;
    int ans = subset_sum(n, val, sum);
    if(ans == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
