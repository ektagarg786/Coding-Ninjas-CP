/*Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1*/

#include<bits/stdc++.h>
using namespace std;
#define Max 2000001
#define eb emplace_back
int* make_sieve(){
     int* sieve = new int[Max];
    for(int i=0;i<=Max;i++){
        sieve[i] = i;
    }
    for(int i=2;i*i<=Max;i++){
        for(int j=i*i;j<=Max;j+=i){
            if(sieve[j] > i){
                sieve[j] = i;
            }
        }
    }
    return sieve;
}
int* strange_order(int n){
    int* sieve = make_sieve();
    int* final_ans = new int[n];
    bool* mark = new bool[n+1];
    for (int i=0;i<=n;i++){
        mark[i] = false;
    }
    int k = 0;
    for(int i=n;i>=1;i--){
        if(! mark[i]){
            int smallest_divisor = sieve[i];
            int x = i;
            vector<int> v;
            mark[i] = true;
            v.eb(i);
            while(x != 1){
                for(int j= i-smallest_divisor;j>=1;j=j-smallest_divisor){
                    if(! mark[j]){
                        mark[j] = true;
                        v.eb(j);
                    }
                }
                while(x%smallest_divisor == 0){
                    x = x/smallest_divisor;
                }
                smallest_divisor = sieve[x];
            }
            sort(v.begin(), v.end(), greater<int>());
            for (int i=0;i<v.size();i++){
                final_ans[k] = v[i];
                k++;
            }
        }
    }
    final_ans[n-1] = 1;
    return final_ans;
}
int main(){
    int n;
    cin >> n;
    int* ans = strange_order(n); 
    for (int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
