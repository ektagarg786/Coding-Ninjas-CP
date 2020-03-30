/*Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4*/


#include<bits/stdc++.h>
using namespace std;
struct node{
    int even;
    int odd;
};
void build_tree(int* arr, node* tree, int start, int end, int treeIndex){
    if(start == end){
        if(arr[start]%2 == 0){
            tree[treeIndex].even = 1;
            tree[treeIndex].odd = 0;
        }
        else{
            tree[treeIndex].even = 0;
            tree[treeIndex].odd = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, start, mid, 2*treeIndex);
    build_tree(arr, tree, mid+1, end, 2*treeIndex+1);
    tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex+1].odd;
    tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
}
void update_tree(int* arr, node* tree, int start, int end, int treeIndex, int index, int value){
    if(start == end){
        arr[index] = value;
        if(arr[start]%2 == 0){
            tree[treeIndex].even = 1;
            tree[treeIndex].odd = 0;
        }
        else{
            tree[treeIndex].even = 0;
            tree[treeIndex].odd = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    if(index > mid)
        update_tree(arr, tree, mid+1, end, 2*treeIndex+1, index, value);
    else
        update_tree(arr, tree, start, mid, 2*treeIndex, index, value);
    tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex+1].odd;
    tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
}
node query(node* tree, int start, int end, int treeIndex, int left, int right){
    if(start > right || end < left){
        node temp;
        temp.odd=0;
        temp.even=0;
        return temp;
    }
    if(start >= left && end <= right){
        return tree[treeIndex];
    }
        int mid = (start+end)/2;
        node ans;
        node n1 = query(tree, start, mid, 2*treeIndex, left, right);
        node n2 = query(tree, mid+1, end, 2*treeIndex+1, left, right);
        ans.odd = n1.odd + n2.odd;
        ans.even = n1.even + n2.even;
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
    build_tree(arr,tree,0,n-1,1);
    int q;
    cin >> q;
    while(q--){
        int qnum, x, y;
        cin >> qnum >> x >> y;
        if(qnum == 0)
            update_tree(arr, tree, 0, n-1, 1, x-1, y);
        else if(qnum == 1){
            node ans = query(tree, 0,n-1, 1, x-1, y-1);
            cout << ans.even << endl;
        }
        else{
            node ans = query(tree, 0,n-1, 1, x-1, y-1);
            cout << ans.odd << endl;
        }
    }
    return 0;
}
