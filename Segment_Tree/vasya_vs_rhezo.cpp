/*Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int A;
    int B;
    int in;
};

void buildTree(int* a,int* b,node* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode].A = a[start];
        tree[treeNode].B = b[start];
        tree[treeNode].in = start;
        return;
    }
    int mid = (start+end)/2;
    buildTree(a,b,tree,start,mid,2*treeNode);
    buildTree(a,b,tree,mid+1,end,2*treeNode+1);
    if(tree[2*treeNode].A != tree[2*treeNode+1].A){
        if(tree[2*treeNode].A > tree[2*treeNode+1].A){
            tree[treeNode].A = tree[2*treeNode].A;
            tree[treeNode].B = tree[2*treeNode].B;
            tree[treeNode].in = tree[2*treeNode].in;
        }else{
            tree[treeNode].A = tree[2*treeNode+1].A;
            tree[treeNode].B = tree[2*treeNode+1].B;
            tree[treeNode].in = tree[2*treeNode+1].in;
        }
    }else{
        if(tree[2*treeNode].B < tree[2*treeNode+1].B){
            tree[treeNode].A = tree[2*treeNode].A;
            tree[treeNode].B = tree[2*treeNode].B;
            tree[treeNode].in = tree[2*treeNode].in;
        }else{
            tree[treeNode].A = tree[2*treeNode+1].A;
            tree[treeNode].B = tree[2*treeNode+1].B;
            tree[treeNode].in = tree[2*treeNode+1].in;
        }
    }
}

node query(node* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left) {
        node temp;
        temp.A = INT_MIN;
        temp.B = INT_MAX;
        temp.in = -1;
        return temp;
    }
    if(left<=start && end<=right) return tree[treeNode];
    int mid = (start+end)/2;
    node n1 = query(tree,start,mid,2*treeNode,left,right);
    node n2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    if(n1.A != n2.A){
        if(n1.A > n2.A){
            ans.A = n1.A;
            ans.B = n1.B;
            ans.in = n1.in;
        }else{
            ans.A = n2.A;
            ans.B = n2.B;
            ans.in = n2.in;
        }
    }else{
        if(n1.B < n2.B){
            ans.A = n1.A;
            ans.B = n1.B;
            ans.in = n1.in;
        }else{
            ans.A = n2.A;
            ans.B = n2.B;
            ans.in = n2.in;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    int* b = new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int q;
    cin>>q;
    node* tree = new node[4*n];
    buildTree(a,b,tree,0,n-1,1);
    while(q--){
        int li,ri;
        cin>>li>>ri;
        node ans = query(tree,0,n-1,1,li-1,ri-1);
        cout<<ans.in+1<<endl;
    }
    return 0;
}
