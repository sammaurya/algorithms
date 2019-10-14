/*
Find the size of largest square of 1's possible in a 2D binary matrix i.e., matrix of 0's and 1's.

Input:
First line, N,M number of rows and columns respectively
Next N line, M integers which is values in the matrix

Output:
Size of largest square of 1's

Sample Input:
4 5
1 0 0 1 0
0 1 1 1 0
1 1 1 1 1
0 1 1 1 0

Sample Output:
3

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int matrix[n][m];
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j)
			scanf("%d",&matrix[i][j]);
	}
	int maxSquareSize = 0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(i==0 || j==0){}
			else{
				if(matrix[i][j] == 1){
					matrix[i][j] = 1 + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));
					if(matrix[i][j] > maxSquareSize)
						maxSquareSize = matrix[i][j];
				}
			}
		}	
	}
	printf("%d", maxSquareSize);

	return 0;
}