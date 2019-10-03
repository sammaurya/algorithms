
/*
	Kth Largest Element in an unsorted array.

	Input:
	First line input is N and K which is size of array and Kth largest element
	Second line n input as element of array

	Output:
	Print Kth largest element in array

	Sample Input:
	5 2
	4 3 1 2 5

	Sample Output:
	4

	Constraint:
	Complexity: O(n)

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
/*
	Three ways we can do this
	1. Sorting the array and returing value at n-k index with complexity of O(nlogn)
	2. Using minHeap() with complexity of O(nlogk)
	3. Using quickSort partition technique with complexity of O(n-1)-logk
*/
int partition(int arr[], int l, int r){

	int i,j,temp;
	i = l-1;
	for(j = l; j<=r; ++j){
		if(arr[j] < arr[r]){
		    i++;
			swap(arr[i], arr[j]);
		}
	}
    i = i+1;
	swap(arr[i], arr[r]);

	return i;

}
int KthLargestElement(int arr[], int n, int k){

	int l = 0, r = n-1, index = n-k, pivot;

	while(l <= r){
		pivot = partition(arr, l, r);
		if(pivot == index)
			return arr[pivot];
		else if(pivot < index)
			l = pivot + 1;
		else
			r = pivot - 1;
	}
	return -1;
} 

int main(int argc, char const *argv[])
{
	int n,k;
	FS_int(n);
	FS_int(k);
	int arr[n];

	for(int i=0; i<n; ++i)
		FS_int(arr[i]);

	printf("%d\n", KthLargestElement(arr,n,k));

	return 0;
}