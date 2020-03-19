/*Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.
Output Format
A single integer which will be minimum unfairness.
Constraints
2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9
Sample Input
7
3
10
100
300
200
1000
20
30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.*/


#include <bits/stdc++.h>
using namespace std;
long long s[100005];
long long unfair(int n, int k, long long* arr){
    sort(arr, arr+n);
    long long t=0;
    long long min=0;
    for(int i=0;i<k-1;i++)
        t+=arr[i];
    s[0]=t;
    for(int i=1;i<n-k;i++)
    {
        t-=arr[i-1];
        t+=arr[i+k-2];
        s[i]=t;
    }
    for(int i=0;i<k;i++)
        min+=(2*i+1-k)*c[i];
    long long temp=min;
    for(int i=1;i<n-k;i++)
    {
        temp+=(k-1)*arr[i-1]-2*s[i]+(k-1)*arr[i+k-1];
        if(temp<min)
        {
            min=temp;
        }
    }
    return min;
}
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << unfair(n, k, arr) << endl;
    return 0;
}
