/*
*   target : whose win and if 1 count the number of moves
*     sol  : from observation that player 2 win only if
*            the number (q) is prime number of factor 2
*
*
*/
#include <bits/stdc++.h>
using namespace std;


int main(){
       long long n,ans=1;
       scanf("%lld",&n);
       int cnt=0;
       for(long long i=2;i*i<=n;i++){
           while(n%i==0&&i*i<=n){
              cnt++;
              n/=i;
              ans*=i;
              if(cnt==2)break;
           }
           if(cnt==2)break;
       }
       if(cnt>=2){printf("1\n%lld\n",ans);}
       else if(cnt==1){
         printf("2");
       }else{
          printf("1\n0");
       }

}
