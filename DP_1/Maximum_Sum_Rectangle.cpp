/*Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29*/

#include <bits/stdc++.h>
using namespace std;
long kadane_sum(long arr[],int n){
    long curr=arr[0],best=arr[0];
    for(int i=1 ; i<n ; i++){
        curr=max(arr[i],curr+arr[i]);
        best=max(best,curr);
    }
    return best;
}
long max_sum(int **input,int n,int m){
    long ans=-1;
    for(int l=0 ; l<m ; l++){
        long sum[n]={};
        for(int r=l ; r<m ; r++){
            for(int i=0 ; i<n ; i++){
                sum[i]+=input[i][r];
            }
            ans=max(ans,kadane_sum(sum,n));
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **input=new int*[n];
    for(int i=0;i<n;i++){
        input[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }
    cout<<max_sum(input,n,m);
    return 0;
}
