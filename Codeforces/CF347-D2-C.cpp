/*
*    Just when u try to subtract u must take a look of Gcd :)
*    u will found that if you subtract x1-x2 the result the multiple of it's 
*    Gcd x1 x2 :) from that obervation take gcd for all and the answer will Max number / Gcd then subtract the orginial 
*    number (all  we need the new elements ) :) 
*
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
   return b==0?a:gcd(b,a%b);
}
int main(){
    int n;
    scanf("%d",&n);
    int a,Max,Gcd;
    scanf("%d",&a);
    Max=a,Gcd=a;
    for(int i=1;i<n;i++){
        scanf("%d",&a);
        Max=max(Max,a);
        Gcd=gcd(Gcd,a);
    }
    int ans=(Max)/Gcd-n;
    if(ans&1){
     puts("Alice");
    }else{
      puts("Bob");
    }
}




