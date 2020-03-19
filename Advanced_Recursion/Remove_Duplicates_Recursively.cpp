/*Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba*/

void removeConsecutiveDuplicates(char *inp) {
   
    if(inp[0] == '\0'){
        return;
    }
    if(inp[0]==inp[1]){
        int i = 0;
        for(; inp[i]!= '\0'; i++){
            inp[i] = inp[i+1];
        }
        inp[i] = '\0';
        removeConsecutiveDuplicates(inp);
    }    
    removeConsecutiveDuplicates(inp+1);
}
