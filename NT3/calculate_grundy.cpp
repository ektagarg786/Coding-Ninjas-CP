/*Calculate Grundy Number
Send Feedback
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format
An Integer 'n'
Output Format
Grundy Number(n)
Sample Input 1 -
10
Sample Output 1-
0*/

#include<bits/stdc++.h>
using namespace std;
int grundy_number(int n){
		if(n == 0) 
            return 0;
    int a = grundy_number(n/2);
    int b = grundy_number(n/3);
    int c = grundy_number(n/6);
    for(int i=0; ;i++){
        if(i != a && i != b && i != c) 
        	return i;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
    cin >> n;
    cout << grundy_number(n);
    return 0;
    
}
