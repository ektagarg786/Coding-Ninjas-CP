/*Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format
The first line of input contains an integer q denoting the number of queries.

The first line of each test case contains a positive integer k, denoting the number of transactions. 

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
Constraints
1<=q<=100

0<k<10

2<=n<=30

0<=elements of array A<=1000
Output Format
For each query print the maximum profit earned by Mike on a new line. 
Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Sample Output
87
1040
0*/

#include <bits/stdc++.h>
using namespace std;
int trader_helper(int n, int k, int* arr, int*** dp, int ongoing){
    if(n == 0 || k == 0)
        return 0;
    if(dp[n][k][ongoing] > -1)
        return dp[n][k][ongoing];
    int option1 = trader_helper(n-1, k, arr+1, dp, ongoing);
    int option2;
    if(ongoing){
        option2 = trader_helper(n-1, k-1, arr+1, dp, 0) + arr[0];
    }
    else{
        if(k > 0)
            option2 = trader_helper(n-1, k, arr+1, dp, 1) - arr[0];
    }
    dp[n][k][ongoing] = max(option1, option2);
    int ans = dp[n][k][ongoing];
    return ans;   
}
int main()
{
    int q;
    cin >> q;
    while(q--){
        int k, n;
        cin >> k;
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int*** dp =new int** [n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int* [k+1];
            for(int j=0;j<=k;j++){
                dp[i][j] = new int[2];
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        int ongoing = 0;
        int ans = trader_helper(n, k, arr, dp, ongoing);
        cout << ans << endl;
        for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;
    }
    return 0;
}
