/*You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2 */

#include <bits/stdc++.h>
using namespace std;
int helper(int o, int c, int n, bool* arr, int** dp){
    if(o > n || c > n)
        return 0;
    if(o == n && c == n)
        return 1;
    if(dp[o][c] != -1)
        return dp[o][c];
    if(o == c || arr[o+c] == true)
        dp[o][c] = helper(o+1, c, n, arr, dp);
    else if(o == n){
        if(arr[o+c] == true)
            dp[o][c] = 0;
        else
            dp[o][c] = helper(o, c+1, n, arr, dp);
    }
    else
        dp[o][c] = helper(o, c+1, n, arr, dp) + helper(o+1, c, n, arr, dp);
    int ans = dp[o][c];
    return ans;
}
int main()
{
    int d;
    cin >> d;
    while(d--){
        int n, k;
        cin >> n >> k;
        bool* arr = new bool[2*n];
        for(int i=0;i<2*n;i++){
            arr[i] = false;
        }
        for(int i=0;i<k;i++){
            int s;
            cin>>s;
            arr[s-1] = true;
        }
        int**dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        cout<<helper(0, 0, n, arr, dp)<<endl;
        for(int i=0;i<=n;i++){
        delete [] dp[i];
        }
        delete []dp;
    }
    return 0;
}
