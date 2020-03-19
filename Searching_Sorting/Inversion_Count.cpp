/*Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4*/

typedef long long ll;
ll merge(int arr[], int left, int mid, int right){
    int i = left, j = mid, k = 0;
    int temp[right-left+1];
    ll count = 0;
    while(i < mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            count += mid-i;
        }
    }
    while(i < mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i=left, k=0; i<= right; i++,k++){
        arr[i] = temp[k];
    }
    return count;
}
ll merge_sort(int arr[], int left, int right){
    ll count = 0;
    if(right > left){
        int mid = (left + right)/2;
        ll count_left = merge_sort(arr, left, mid);
        ll count_right = merge_sort(arr, mid+1, right);
        ll my_count = merge(arr, left, mid+1, right);
        return count_left + count_right + my_count;
    }
    return count;
}
ll solve(int A[], int n)
{
	ll ans = merge_sort(A, 0, n-1);
    return ans;
}
