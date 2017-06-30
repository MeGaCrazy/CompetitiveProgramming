#include <bits/stdc++.h>
using namespace std;
const int N=12345678;
bool prime[N];
int sum_prime[N],sum_plan[N];
inline bool check(int i){
   int t=i;
   int ans=0;
   while(i){
     ans=(ans*10)+(i%10);
     i/=10;
   }
  return ans==t;
}
void solve(){
   prime[1]=1;
   prime[0]=1;
   for(int i=2;i<N;i++){
       if(!prime[i]){
          for(int j=2;i*j<N;j++){
             prime[i*j]=1;
          }
       }
   }
   for(int i=1;i<N;i++){
      sum_prime[i]=sum_prime[i-1]+(prime[i]==0);
      sum_plan[i]=sum_plan[i-1]+(check(i)==1);
   }
}
int main(){
    double p,q;
    scanf("%lf %lf",&p,&q);
    solve();
    for(int i=N-1;i>=1;i--){
       if((double)(1LL*sum_prime[i]*q)<=(double)(1LL*p*sum_plan[i])){
          //cerr<<"first side "<<p<<" second side "<<q<<endl;
          printf("%d\n",i);
          return 0;
       }
    }
    printf("Palindromic tree is better than splay tree\n");
 
    
}