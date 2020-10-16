/*Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1*/

#include<bits/stdc++.h>
using namespace std;
int* get_lps(char* s){
    int n = strlen(s);
    int* lps = new int[n];
    lps[0] = 0;
    int i = 1;
    int j = 0;
    while(i < n){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int findString(char* s1, char* s2){
    int* lps = get_lps(s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j == n2){
        return i - n2;
    }
    return -1;
}
