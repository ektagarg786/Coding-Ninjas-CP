/*Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3*/

int dfs(char cake[NMAX][NMAX], int n, int i, int j, bool** visited){
    visited[i][j] = true;
    int count = 0;
    if(i-1 >= 0 && j>= 0){
        if(cake[i-1][j] == '1' && ! visited[i-1][j]){
            count += dfs(cake, n, i-1, j, visited);
        }
    }
    if(i >= 0 && j + 1 >= 0){
        if(cake[i][j+1] == '1' && ! visited[i][j+1]){
            count += dfs(cake, n, i, j+1, visited);
        }
    }
    if(i >= 0 && j-1>= 0){
        if(cake[i][j-1] == '1' && ! visited[i][j-1]){
            count += dfs(cake, n, i, j-1, visited);
        }
    }
    if(i+1 >= 0 && j>= 0){
        if(cake[i+1][j] == '1' && ! visited[i+1][j]){
            count += dfs(cake, n, i+1, j, visited);
        }
    }
    return count+1;
}
int solve(int n, char cake[NMAX][NMAX]){
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j] == '1' && ! visited[i][j]){
                int x = dfs(cake, n, i, j, visited);
                if(x > max){
                    max = x;
                }
            }     
        }
    }
    return max;
}
