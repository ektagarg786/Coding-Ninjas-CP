/*You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2*/

#include<bits/stdc++.h>
using namespace std;
struct node{
    long long int max_sum;
    long long int sum;
    long long int prefix_sum;
    long long int sufix_sum;
};
void build_tree(int* arr, node* tree, int start, int end, int treeIndex){
    if(start == end){
        tree[treeIndex].max_sum = arr[start];
        tree[treeIndex].sum = arr[start];
        tree[treeIndex].prefix_sum = arr[start];
        tree[treeIndex].sufix_sum = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, start, mid, 2*treeIndex);
    build_tree(arr, tree, mid+1, end, 2*treeIndex+1);
    tree[treeIndex].max_sum = max(max(tree[2*treeIndex+1].max_sum,tree[2*treeIndex].max_sum),tree[2*treeIndex].sufix_sum+tree[2*treeIndex+1].prefix_sum);
    tree[treeIndex].sum = tree[2*treeIndex].sum + tree[2*treeIndex+1].sum;
    tree[treeIndex].prefix_sum = max(tree[2*treeIndex].prefix_sum, tree[2*treeIndex].sum + tree[2*treeIndex+1].prefix_sum);
    tree[treeIndex].sufix_sum = max(tree[2*treeIndex+1].sufix_sum, tree[2*treeIndex+1].sum + tree[2*treeIndex].sufix_sum);
}
node query(node* tree, int start, int end, int treeIndex, int left, int right){
    if(start > right || end < left){
        node temp;
        temp.max_sum = INT_MIN;
        temp.sum = INT_MIN;
        temp.prefix_sum = INT_MIN;
        temp.sufix_sum = INT_MIN;
        return temp;
    }    
    if(start >= left && end <= right){
        return tree[treeIndex];
    }
    int mid = (start+end)/2;
    node x = query(tree, start, mid, 2*treeIndex, left, right);
    node y = query(tree, mid+1, end, 2*treeIndex+1, left, right);
    node ans;
    ans.max_sum = max(max(y.max_sum, x.max_sum), x.sufix_sum + y.prefix_sum);
    ans.sum = x.sum + y.sum;
    ans.prefix_sum = max(x.prefix_sum, x.sum + y.prefix_sum);
    ans.sufix_sum = max(y.sufix_sum, y.sum + x.sufix_sum);
    return ans;
}
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    node* tree = new node[4*n];
    build_tree(arr, tree, 0, n-1, 1);
    int q;
    cin >> q;
    while(q--){
        int left, right;
        cin >> left >> right;
        node ans;
        ans = query(tree, 0, n-1, 1, left-1, right-1);
        cout << ans.max_sum << endl;
    }
    return 0;
}
