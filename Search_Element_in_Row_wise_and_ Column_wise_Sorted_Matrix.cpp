/*
	Search integer K in  a row-wise and column-wise sorted matrix.

	Input:
	First line, T number of test cases
	Second line, N,M number of rows and columns of matrix respectively
	Next N lines, M integer values of each column of ith row
	Last line, K integer value to be searched in matrix

	Output:
	True if K is found in matrix, 
	FALSE if K is not found in matrix, each in newline


	Sample Input:
	2
	4 4
	1 2 3 4
	8 11 12 13
	9 14 15 16
	10 17 18 19
	7
	4 4
	1 2 3 4
	8 11 12 13
	9 14 15 16
	10 17 18 19
	12
	Sample Output:
	FALSE
	TRUSE

	Complexity:
	Time Complexity : O(log(N + M))
	Space Complexity : O(1)

*/

#include <bits/stdc++.h>

using namespace std;

void FS_int(int& number){
    number = 0;
    register int c = getchar_unlocked();
    
    for( ; (c > 47 && c < 58); c = getchar_unlocked()){
        number  = number * 10 + c - 48;
    }
}

int go(){
    int N,M,K,i,j;
    FS_int(N);
    FS_int(M);
  	//Input Matrix Element
	int matrix[N][M];
	for(i=0; i<N; ++i){
		for(j=0; j<M; ++j)
			FS_int(matrix[i][j]);
	}
	
	//Value to be searched
	FS_int(K);

	//Searching element in matrix using Binary Search and index mapping from 1D to 2D
	i = N-1;
	j = 0;
	while(!(i < 0 || j < 0)){
	    if(matrix[i][j] == K)
	        return 1;
	    else if(matrix[i][j] > K)
	        i--;
	    else
	        j++;
	}
	
	
	return 0;
}

//More efficient method
int go_1(){
    int N,M,K,i,j;
    FS_int(N);
    FS_int(M);
  	//Input Matrix Element
	int matrix[N][M];
	for(i=0; i<N; ++i){
		for(j=0; j<M; ++j)
			FS_int(matrix[i][j]);
	}
	//Value to be searched
	FS_int(K);

	//Searching element in matrix using Binary Search and index mapping from 1D to 2D
	i = N-1;
	j = 0;
	int x = 0, y = M-1;
	while(!(i < 0 || j > M-1 || x > N-1 || y < 0)){
		//Starting from bottom left
	    if(matrix[i][j] == K)
	        return 1;
	    else if(matrix[i][j] > K)
	        i--;
	    else
	        j++;
	   
	   	//Starting from top right
	    if(matrix[x][y] == K)
	        return 1;
	    else if(matrix[x][y] > K)
	        y--;
	    else
	        x++;
	}
	
	
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T;
	FS_int(T);
	while(T--){
	    if(go())
	        printf("TRUE\n");
	    else
	        printf("FALSE\n");
	}
	return 0;
}