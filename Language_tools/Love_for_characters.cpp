/*Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char c[n];
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    map<char, int> m;
    for(int i=0;i<n;i++){
        m[c[i]]++;
    }
    char char1 = 'a';
    char char2 = 's';
    char char3 = 'p';
        if(m.find(char1) == m.end())
            cout << 0 << " ";
        else
            cout << m[char1] << " ";
        if(m.find(char2) == m.end())
            cout << 0 << " ";
        else
            cout << m[char2] << " ";
        if(m.find(char3) == m.end())
            cout << 0 << " ";
        else
            cout << m[char3] << " ";
	return 0;
}
