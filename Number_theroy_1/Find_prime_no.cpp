/*Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 */
		//SIEVE OF ERATHSTHENE 				


#include<bits/stdc++.h>
using namespace std;
int make_sieve(int n){
    bool* is_prime = new bool[n+1];
    for(int i=0;i<=n;i++){
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i=0;i<=n;i++){
        if(is_prime[i])
            count++;
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    int ans = make_sieve(n);
    cout << ans << endl;
    return 0;
}



                   // COMPLEXITY : Nsqrt(N)
// #include<bits/stdc++.h>
// using namespace std;
// bool check_prime(int n){
//     int count = 0;
//     for(int j=1;j*j<=n;j++){
//         if(n%j == 0){
//         	if(j*j == n)
//             	count += 1;
//             else
//                 count += 2;
//     	}
//     }
//     if(count == 2)
//         return true;
//     else
//         return false;
// }
// int main(){
// 	int n;
//     cin >> n;
//     int count = 0;
//     for(int i=1;i<=n;i++){
//         if(check_prime(i)){
//             count++;
//         }
//     }
//     cout << count << endl;
// 	return 0;
// }
