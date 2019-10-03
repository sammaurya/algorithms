/*
	Find number of negative values in a row wise and column wise sorted matrix.

	Input:
	N M 	number of rows and columns of the matrix
	Next N lines are space separated M integers

	Output:
	Single integer denoting number of negative number

	Sample Input:
	3 3
	-3 -2 -1
	-2 -1 1
	0 2 3

	Sample Output:
	5

	Constraints:
	1<=N,M>=100000
	Time Complexity O(N+M)

*/

#include <bits/stdc++.h>
using namespace std;

int countNegativeNumbers(int n, int m, int *mat){
	int count = 0;

	for(int i=0; i<n; ++i){
		for(int j=m-1; j>=0; --j){
			if(*(mat+i*m + j) < 0){
				count += j + 1;
				i++;
			}
		}
	}
	return count;
}
int main(){
	int n,m,i,j,count;
	scanf("%d %d",&n,&m);
	int mat[n][m];
	for(i=0; i<n; i++){
		for(j=0; j<m; ++j)
			scanf("%d",&mat[i][j]);
	}

	count = countNegativeNumbers(n,m,&mat[0][0]);
	printf("%d\n", count);

	return 0;
}