/*Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 */

#include <bits/stdc++.h>
using namespace std;
int pilot_helper(int n, int* a, int* c, int** dp, int x){
    if(n==0 || x>n) 
        return 0;
    if(dp[n][x] > -1)
        return dp[n][x];
    if(x == 0)
        dp[n][x] = a[0] + pilot_helper(n-1, a+1, c+1, dp, 1);
    else if(x == n)
        dp[n][x] = c[0] + pilot_helper(n-1, a+1, c+1, dp, x-1);
    else{
        dp[n][x] = min((a[0] + pilot_helper(n-1, a+1, c+1, dp, x+1)), (c[0] + pilot_helper(n-1, a+1, c+1, dp, x-1)));
    }
    int ans = dp[n][x];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    int* c = new int[n];
    for(int i=0;i<n;i++){
        cin >> c[i] >> a[i];
    }
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++) 
            dp[i][j] = -1;
    }
    int count = 0;
    cout << pilot_helper(n, a, c, dp, count);
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return 0;
}
