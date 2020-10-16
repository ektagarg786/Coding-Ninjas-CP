/*A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2 
2
0
8
1*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
void make_sieve(int* arr){
    for(int i=0;i<MAX;i++){
        arr[i] = 0;
    }
    for(int i=2;i<=100;i++){
        int curr_num = i*i*i;
        for(int j=1;curr_num*j<MAX;j++){
            arr[curr_num*j] = -1;
        }
    }
    int k = 1;
    for(int i=1;i<MAX;i++){
        if(arr[i] != -1){
            arr[i] = k;
            k++;
        }
    }
}
int main(){
	int t;
    cin >> t;
    int* arr = new int[MAX];
    make_sieve(arr);
    int i= 1;
    while(t--){
        int n;
        cin >> n;
        if(arr[n] != -1){
            cout << "Case" << " " << i << ":" << " " << arr[n] << endl;
        }
        else{
            cout << "Case" << " " << i << ":" << " " << "Not Cube Free" << endl;
        }
        i++;     
    }
	return 0;
}
