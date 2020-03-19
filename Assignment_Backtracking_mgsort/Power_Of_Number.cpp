/*Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to print the answer.
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints:
0 <= x <= 8, 0 <= n <= 9
Sample Input 1 :
 3 4
Sample Output 1 :
81
Sample Input 2 :
 2 5
Sample Output 2 :
32*/

#include<iostream>
typedef long long ll;
using namespace std;

int main() {
	int x, n;
    ll result = 1;
    cin >> x >> n;
    while(n != 0){
        result *= x;
        --n;
    }
	cout << result << endl;
}
