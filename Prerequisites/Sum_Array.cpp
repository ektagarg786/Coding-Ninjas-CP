/*Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
Input:
First line will have a single integer ‘n’ denoting the order of matrix.
Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.
Constraints:
1<=n<=100
Output:
Print a single integer denoting the sum.
Sample input:
3
1 2 3
4 5 6
7 8 9
Sample Output:
45*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                sum += arr[i][j];
            }
        } 
    }
    if(n%2 == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+j == n-1){
                    sum += arr[i][j];
                }
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+j == n-1){
                    sum += arr[i][j];
                }
            }
        }
        sum = sum - arr[(n-1)/2][(n-1)/2];
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==n-1 || j==n-1){
                    sum += arr[i][j];
                }
            }
    }
    sum = sum - arr[0][0] - arr[0][n-1] - arr[n-1][0] - arr[n-1][n-1];
    cout << sum;
	return 0;
}
