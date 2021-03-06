/*Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1*/

#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** a, int m, int n){
    int** dp = new int*[m];
    for(int i=0;i<m;i++){
        dp[i] = new int[n];
        for(int j=0;j<n;j++) 
            dp[i][j] = 0;
    }
    for(int i=0;i<m;i++){
        if(a[i][0]==0) 
            dp[i][0] = 1;
    }
    for(int i=0;i<n;i++){
        if(a[0][i]==0) 
            dp[0][i] = 1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(a[i][j]==0)
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
        }
    }
    int maxi = -1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            if(dp[i][j]>maxi) 
                maxi = dp[i][j];
    }
    return maxi;
}
