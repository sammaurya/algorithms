/*
	Fast I/O Operation

	1.Using scanf() and printf() instead of cin and cout
	2.Using ios_base::sync_with_stdio(false) followed by cin.tie(NULL) just after main
	3.Using FastScan(number) custom method given below

*/

#include <bits/stdc++.h>

#define ll long long;

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

void FS_ll(ll& number){
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

ll scan_ll() 
{
    register int c; 
    ll number = 0;
    c = getchar_unlocked(); 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
    return number;
} 

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int number;
	FS_int(number);

	printf("%d",number);	//Instead of cout
	getchar();

	return 0;
}