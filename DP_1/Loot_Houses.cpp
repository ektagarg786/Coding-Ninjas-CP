/*A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110*/

#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){
    // int* output = new int[(n/2)];
    // output[0] = arr[0];
    // int j = 0, i=1;
    // while(j+2 <= n){
    //     output[i] = output[i-1] + arr[j+2];
    //     j += 2;
    //     i++;
    // }
    // int x = output[(n-1)/2];
    // j = 0, i = 1;
    // output[0] = arr[1];
    // while(j+3 <= n){
    //     output[i] = output[i-1] + arr[j+3];
    //     j += 2;
    //     i++;
    // }
    // int y = output[(n-1)/2];
    // int result = max(x, y);
    // delete [] output;
    // return result;
    int* dp = new int[n+1];
    dp[0] = arr[0];
    dp[1] = max(arr[1], dp[0]);
    for(int i=2;i<=n;i++){
        dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
    }
    int output = dp[n-1];
    delete [] dp;
    return output;
    
}
