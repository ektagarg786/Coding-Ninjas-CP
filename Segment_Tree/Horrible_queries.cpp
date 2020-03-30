/*World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void update_tree_lazy(ll* tree, ll* lazy, ll start, ll end, ll left, ll right, ll currPos, ll inc){
    if(start > end)
        return;
    if(lazy[currPos] != 0){
        tree[currPos] += lazy[currPos]*(end-start+1);
        if(start != end){
            lazy[2*currPos] += lazy[currPos];
            lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    if(left > end || right < start)
        return;
    if(left <= start && right >= end){
        tree[currPos] += inc*(end-start+1);
        if(start != end){
            lazy[2*currPos] += inc;
            lazy[2*currPos+1] += inc;
        }
        return;
    }
    ll mid = (start+end)/2;
    update_tree_lazy(tree, lazy, start, mid, left, right, 2*currPos, inc);
    update_tree_lazy(tree, lazy, mid+1, end, left, right, 2*currPos+1, inc);
    tree[currPos] = tree[2*currPos] + tree[2*currPos+1];
}
ll query(ll* tree, ll* lazy, ll start, ll end, ll left, ll right, ll currPos){
    if(start > end) 
        return 0;
    if(lazy[currPos] != 0){
        tree[currPos] += lazy[currPos]*(end-start+1);
        if(start != end){
            lazy[2*currPos] += lazy[currPos];
            lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    if(left > end || right < start)
        return 0;
    if(left <= start && right >= end)
        return tree[currPos];
    ll mid = (start+end)/2;
    ll x = query(tree, lazy, start, mid, left, right, 2*currPos);
    ll y = query(tree, lazy, mid+1, end, left, right, 2*currPos+1);
    return x+y;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, c;
        cin >> n >> c;
        ll* tree = new ll[4*n];
        ll* lazy = new ll[4*n];
        for(ll i=0;i<4*n;i++){
            tree[i] = 0;
            lazy[i] = 0;
        }
        while(c--){
            ll type, left, right, inc;
            cin >> type;
            if(type == 0){
                cin >> left >> right >> inc;
                update_tree_lazy(tree, lazy, 0, n-1, left-1, right-1, 1, inc);
            }
            else{
                cin >> left >> right;
                cout << query(tree, lazy, 0, n-1, left-1, right-1, 1) << endl;
            }
        }
    }
}
