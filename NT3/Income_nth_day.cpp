/*Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:
The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.
Output:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
CONSTRAINTS:
1 ≤ T ≤ 10^5

0 ≤ F0, F1, N ≤ 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007
ll power(ll a, ll b)
{
    ll res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return res;
}
void multiply(ll A[2][2], ll M[2][2])
{
    ll fvalue = (A[0][0] * M[0][0]) % (m - 1) + (A[0][1] * M[1][0]) % (m - 1);
    ll svalue = (A[0][0] * M[0][1]) % (m - 1) + (A[0][1] * M[1][1]) % (m - 1);
    ll tvalue = (A[1][0] * M[0][0]) % (m - 1) + (A[1][1] * M[1][0]) % (m - 1);
    ll lvalue = (A[1][0] * M[0][1]) % (m - 1) + (A[1][1] * M[1][1]) % (m - 1);
    A[0][0] = fvalue % (m - 1);
    A[0][1] = svalue % (m - 1);
    A[1][0] = tvalue % (m - 1);
    A[1][1] = lvalue % (m - 1);
}
void fib_power(ll A[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;
    fib_power(A, n / 2);
    multiply(A, A);
    if (n % 2 != 0)
    {
        ll M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}
ll fib(ll n)
{
    ll A[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    fib_power(A, n - 1);
    return A[0][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        if (n == 0)
        {
            cout << a << endl;
        }
        else if (n == 1)
        {
            cout << b << endl;
        }
        else
        {
            ll x = (fib(n - 1)) % (m - 1);
            ll y = (fib(n)) % (m - 1);
            ll ans = (power(a + 1, x) % m * power(b + 1, y) % m) % m;
            ans--;
            if (ans < 0)
            {
                ans = (ans + m) % m;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
