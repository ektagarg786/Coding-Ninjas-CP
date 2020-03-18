/*You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4*/

#include<bits/stdc++.h>
using namespace std;
struct activity
{
	int start;
	int finish;
};
bool comparison(activity a, activity b)
{
	return a.finish < b.finish;
}
int print_activity(activity* arr, int n)
{
	int i,j;
	i=0;
	sort(arr,arr+n,comparison);
    int max = 1;
	for(j=1;j<n;j++)
	{
		if(arr[j].start >= arr[i].finish)
		{
			i=j;
            max++;
		}
	}
    return max;
}
int main()
{
	int n,i;
	cin >> n;
    activity arr[n];
	for(i=0;i<n;i++)
		cin >> arr[i].start >> arr[i].finish ;
	cout << print_activity(arr, n);		
	return 0;
}
