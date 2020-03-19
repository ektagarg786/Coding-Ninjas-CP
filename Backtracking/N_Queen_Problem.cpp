/*You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 */

#include<bits/stdc++.h>
using namespace std;
int chess[11][11];
bool is_safe(int i, int j, int n)
{
	for( int row=0;row<i;row++ )
	{
		if(chess[row][j] == 1)
			return false;
	}
	int x = i;
	int y = j;
	while( x >= 0 && y < n )
	{
		if(chess[x][y] == 1)
			return false;
		x--;
		y++;
	}
	x = i;
	y = j;
	while( x >= 0 && y >= 0 )
	{
		if(chess[x][y] == 1)
			return false;
		x--;
		y--;
	}
	return true;
}
void nQueenHelper(int n, int row){
	if(row == n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << chess[i][j] << " ";
			}
		}
		cout << endl;
		return;
	}
	for(int j=0;j<n;j++){
		if(is_safe(row, j, n)){
			chess[row][j] = 1;
			nQueenHelper(n, row+1);
			chess[row][j] = 0;
		}
	}
	return;
}
void placeNQueens(int n){
	memset(chess, 0, 11*11*sizeof(int));
	nQueenHelper(n, 0);
}

