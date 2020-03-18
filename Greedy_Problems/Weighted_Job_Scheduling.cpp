/*You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250*/

#include<bits/stdc++.h>
using namespace std;
struct job{
	int start;
	int finish;
	int profit;
};
bool compare(job a, job b){
	return a.finish < b.finish;
}
int binarySearch(job arr[], int index){
    int lo = 0, hi = index - 1;
    while (lo <= hi){
        int mid = (lo + hi) / 2; 
        if(arr[mid].finish <= arr[index].start){
            if (arr[mid + 1].finish <= arr[index].start)
                lo = mid + 1; 
            else 
                return mid; 
        }
        else 
            hi = mid - 1;
     }
     return -1;
}
int max_profit(job* arr, int n){
    sort(arr, arr+n, compare);
    int* dp = new int[n];
    dp[0] = arr[0].profit;
    for(int i=1;i<n;i++){
        int including = arr[i].profit;
        int x = binarySearch(arr,i);     
        if(x != -1)
            including += dp[x];
        dp[i] = max(including, dp[i-1]);
    }
    int ans = dp[n-1];
    delete [] dp;
    return ans;
}
int main(){
	int i,n;
	cin >> n;
    job* arr = new job[n];
	for(i=0;i<n;i++)
		cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
	cout << max_profit(arr, n);
	return 0;
}
