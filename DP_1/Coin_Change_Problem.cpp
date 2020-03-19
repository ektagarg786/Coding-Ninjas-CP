/*You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).*/

int count(int* d, int num, int n, int** arr){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(num == 0)
        return 0;
    if(arr[n][num] >= 0){
        return arr[n][num];
    }
    int output1 = count(d, num, (n-d[0]), arr);
    int output2 = count(d+1, num-1, n, arr);
    arr[n][num] = output1 + output2;
    return output1 + output2;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int** arr = new int*[value+1];
    for(int i=0;i<=value;i++){
        arr[i] = new int[numDenominations+1];
        for(int j=0;j<=numDenominations;j++){
            arr[i][j] = -1;
        }
    }
    int c = count(denominations, numDenominations, value, arr);
    delete[] arr;
    return c;
}
