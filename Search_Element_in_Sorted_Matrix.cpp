/*
	Search integer value K in a 2D sorted matrix.

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
	3 4
	0 1 2 3
	4 5 6 7
	8 9 10 11
	5
	3 4
	0 1 2 3
	4 5 6 7
	8 9 10 11
	12
	Sample Output:
	True
	FALSE

	Complexity:
	Time Complexity : O(logNM)
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
  
	int matrix[N][M];
	for(i=0; i<N; ++i){
		for(j=0; j<M; ++j)
			FS_int(matrix[i][j]);
	}
	
	FS_int(K);

	//Searching element in matrix using Binary Search and index mapping from 1D to 2D
	int s = 0, e = N*M-1;
	int mid;
	while(s <= e){
	    mid = (s+e)/2;
	    i = mid/N;
	    j = mid%M;
	    //Found element at index i, j
	    if(matrix[i][j] == K){
	        return 1;
	    }
	    else if(matrix[i][j] < K)
	        s = mid + 1;
	    else
	        e = mid - 1;
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