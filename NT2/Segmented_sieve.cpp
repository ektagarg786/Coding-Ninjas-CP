/*In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
#define eb emplace_back
vector<int> make_sieve(){
    bool* prime = new bool[MAX];
    for(int i=0;i<MAX;i++){
        prime[i] = true;
    }
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                prime[j] = false;
            }
        }
    }
    vector<int> v;
    v.eb(2);
    for(int i=3;i<MAX;i+=2){
        if(prime[i])
            v.eb(i);
    }
    return v;
}
void print_prime(ll l, ll r, vector<int> &v){
    bool* prime = new bool[r-l+1];
    for(int i=0;i<=r-l;i++){
        prime[i] = true;
    }
    for(int i=0;v[i]*(ll)v[i]<=r;i++){
        int curr_prime = v[i];
        ll base = (l/curr_prime)*(curr_prime);
        if(base < l){
            base = base + curr_prime;
        }
        for(ll j=base;j<=r;j+=curr_prime){
            prime[j-l] = false;
        }
        if(base == curr_prime){
            prime[base-l] = true;
        }
    }
    for(int i=0;i<=r-l;i++){
        if(prime[i] == true){
            cout << i+l << endl;
        }
    }
}
int main()
{
    vector<int> v = make_sieve();
	int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        print_prime(l, r, v);
    }
	return 0;
}
