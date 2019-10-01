/*
	Maximum Sum SubArray

	Find the sub array which has maximum sum of its element.

	Input:
	Size of array
	Elements of array

	Output
	Maximum sum of sub array

	Sample Input:
	5
	-2 1 0 4 -1

	Sample output:
	5
*/

#include <bits/stdc++.h>


using namespace std;

void FS_int(int& number){
	//Variable to indicate sign of input number
	bool negative = false;
	register int c;
	number = 0;

	//extract current character from buffer
	c = getchar(); //Can use getchar_unlocked() for more speed but it is not thread safe

	if(c == '-'){
		negative = true;
		c = getchar();
	}
	// Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for( ; (c > 47 && c < 58); c = getchar()){
    	number = number*10 + c - 48;
    }

    if(negative)
    	number *= -1;

}
int maxSumSubArray(int arr[], int n){

	int max, maxSum, start = 0, end = 0;
	max = maxSum = arr[0];

	for(int i = 1; i<n; ++i){

		if(max + arr[i] < arr[i]){
			max = arr[i];
			if(max >= maxSum){
				maxSum = max;
				start = i;
			}
		}
		else{
			max = max + arr[i];
			if(max >= maxSum){
				maxSum = max;
				end = i;
			}
		}
	}
	
	printf("%d %d\n",start, end);

	return maxSum;

}
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int n;
	FS_int(n);
	int arr[n];
	for(int i=0; i<n; ++i)
		FS_int(arr[i]);
	
	//Iterative method using Kadane's Algorithm complexity O(n)
	printf("%d", maxSumSubArray(arr,n)); 

	return 0;
} 