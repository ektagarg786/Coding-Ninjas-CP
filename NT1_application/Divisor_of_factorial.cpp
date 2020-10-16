/*Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007
#define eb emplace_back
#define MAX 50001
vector<int> make_sieve(){
    bool* prime = new bool[MAX];
    for(int i=0;i<=MAX;i++){
        prime[i] = true;
    }
    vector<int> v;
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                prime[j] = false;
            }
        }
    }
    v.eb(2);
    for(int i=3;i<=MAX;i+=2){
        if(prime[i]){
            v.eb(i);
        }
    }
    return v;
}
ll fact_divisor(int n, vector<int> v){
    ll result = 1;
    for(int i=0;v[i]<=n;i++){
        ll count = 0;
        int k = v[i];
        while((n/k)!=0){
            count = (count+ (n/k))%m;
            k *= v[i];
        }
        result = (result*((count+1)%m))%m;
    }
    return result;
}
int main(){
    int t;
    cin >> t;
    vector<int> output = make_sieve();
    while(t--){
        int n;
        cin >> n;
        cout << fact_divisor(n, output) << endl;
    }
}
