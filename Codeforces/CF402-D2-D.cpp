/*
*    make best gcd from 1-n to every index
*    and make function as he said :) 
*    then to get make beatuy u must walk from right coz it's have smaller divior :)
*    and then if the divisor can has some bad primes we take him to take off my element to get minimum loss or Best gain :) in this element =D 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int arr[N];
int di[N];
set<int>prim;
int gcd(int a,int b){
     if(!b){
        return a;
     }
    return gcd(b,a%b);
}
int f(int i){
     if(i==1)return 0;
     for(int j=2;j*j<=i;j++){
          if(i%j==0){
            return ((prim.find(j)!=prim.end())?-1:1)+f(i/j);
          }
     }
     return ((prim.find(i)!=prim.end())?-1:1);
}
int main(){
      int n,m;
      scanf("%d %d",&n,&m);
      for(int i=1;i<=n;i++){
          scanf("%d",arr+i);
      }
      di[1]=arr[1];
      for(int i=2;i<=n;i++){
         di[i]=gcd(di[i-1],arr[i]);
//         fprintf(stderr,"i is %d di[i] is %d \n",i,di[i]);
      }
      for(int i=1,a;i<=m;i++){
          scanf("%d",&a);
          prim.insert(a);
      }
      int ans=0,t=1;
      for(int i=n;i>=1;i--){
           if(f(di[i]/t)<=0){
              t=di[i];
           }
           ans+=f(arr[i]/t);
      }
      printf("%d\n",ans);

}