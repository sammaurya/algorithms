
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll scan_ll() 
{
    register int c; 
    ll number = 0;
    c = getchar_unlocked(); 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
    return number;
} 
void FS_int(int& number){
	
	register int c;
	number = 0;

	c = getchar(); //Can use getchar_unlocked() for more speed but it is not thread safe
	
    for( ; (c > 47 && c < 58); c = getchar()){
    	number = number*10 + c - 48;
    }
}

int go(){
    int N,M,Q,s,count=0;
    FS_int(N);
    FS_int(M);
    FS_int(Q);
    int pages[100008] = {0};
    int torn;
    for(int i=1; i<=M; ++i){
        FS_int(torn);
        pages[torn] = -1;
    }
    for(int i=1; i<=Q; ++i){
        FS_int(s);
        for(int j=s; j<=N; j = j+s){
          //  printf("1.J %d ",j);
            if(pages[j] != -1){
                pages[j] = pages[j] + 1;
                count++;
              //  printf("%d ",pages[j]);
            }
        }
       // printf("\n");
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, i = 1;
    FS_int(T);
    while(T--){
        printf("Case #%d: %d\n",i++,go());
    }
    return 0;
}

