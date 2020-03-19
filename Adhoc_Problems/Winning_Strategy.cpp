/*Our college team is going to the sports fest to play a football match with our coach. There are n players in our team, numbered from 1 to n.
The coach will know the position of another team hence create a winning strategy. He creates the position of every player in a specific order so that we will win and then he starts swapping two players at a time to form the positions.
He swaps payers in such a way that it can't be understood by another team:
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose
Input Format
The First line contains numbers of players in team: n
The second line contains n space separated integers denoting the specific position of players: i-th integer denotes the position of Ai player in winning strategy
Output Format
If our team wins print "YES"(without quotes) and in next line print the minimum numbers of swapping required to form this specific order otherwise print "NO"(without quotes) 
Constraints
1 =< n <= 10^5 
1 <= Ai <= n
Sample Input1:
5
2 1 5 3 4
Sample Output1:
YES
3
Sample Input2:
5
2 5 1 3 4
Sample Output3:
NO   
Explaination
In the First Sample case, 
    Initial state: 1 2 3 4 5
    Three moves required to form this order:
    1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
In the second case, no way to form this specific order*/

#include<bits/stdc++.h>
using namespace std;
#define crap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    int total_swap = 0;
    int j = n-1;
        while(j >= 1){
            if(a[j] == j+1)
                j --;
            else{
                if(a[j-1] == j+1){
                    ll temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp; 
                    total_swap += 1;
                    j -= 2;
                }
                else if(a[j-2] == j+1){
                    a[j-2] = a[j-1];
                    a[j-1] = a[j];
                    a[j] = j+1;
                    total_swap += 2;
                    j -= 3;
                }
                else{
                    cout << "NO" << endl;
                    break;
                }
            }
            if(j < 1){
                cout << "YES" << endl;
                cout << total_swap << endl;
            }
        }
    return 0;
}
