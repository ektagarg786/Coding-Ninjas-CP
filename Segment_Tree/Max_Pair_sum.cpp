/*You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12*/


#include<bits/stdc++.h>
using namespace std;
struct node{
    int maximum;
    int smaximum;
};
void build_tree(int* arr, node* tree, int start, int end, int treeIndex){
    if(start == end){
        tree[treeIndex].maximum = arr[start];
        tree[treeIndex].smaximum = INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, start, mid, 2*treeIndex);
    build_tree(arr, tree, mid+1, end, 2*treeIndex+1);
    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex + 1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
}
void update_tree(int* arr, node* tree, int start, int end, int treeIndex, int index, int value){
    if(start == end){
        arr[index] = value;
        tree[treeIndex].maximum = value;
        return;
    }
    int mid = (start+end)/2;
    if(index > mid)
        update_tree(arr, tree, mid+1, end, 2*treeIndex+1, index, value);
    else
        update_tree(arr, tree, start, mid, 2*treeIndex, index, value);
    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex + 1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
}
node query(node* tree, int start, int end, int treeIndex, int left, int right){
    if(end < left || start > right){
        node temp;
        temp.maximum=INT_MIN;
        temp.smaximum=INT_MIN;
        return temp;
    }
    if(start >= left && end <= right)
        return tree[treeIndex];
    int mid = (start+end)/2;
    node ans1 = query(tree,start,mid,2*treeIndex,left,right);
    node ans2 = query(tree,mid+1,end,2*treeIndex+1,left,right);
    node ans;
    ans.maximum = max(ans1.maximum, ans2.maximum);
    ans.smaximum = min(max(ans1.maximum, ans2.smaximum), max(ans2.maximum, ans1.smaximum));
    return ans;
}
int main(){
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    node* tree = new node[4*n];
    build_tree(arr, tree, 1, n, 1);
    int q;
    int left, right, index, value;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        if(c == 'Q'){
            cin >> left >> right;
            node ans;
            ans = query(tree,1,n,1,left,right);
            cout << ans.maximum + ans.smaximum <<endl;
        }
        else{
            cin >> index >> value;
            update_tree(arr,tree,1,n,1,index,value);
        }
    }
    return 0;
}
