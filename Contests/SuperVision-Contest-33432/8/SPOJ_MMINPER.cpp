/*
*    Idea : make all values of (i) that = (i)*(i-1)/2 
*           There is 3 condition : 1- m=0 print same array
*                                  2- i can just reverse from end some number the it's i value equal = m
*                                  3- i need to swap 1 element in reversed array to statisfy the required value
*
*
*           Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=50005;
int arr[N];


int main(){
  for(int i=1;i<N;i++){
       arr[i]=((long long )(i)*(i-1)/2);
  }
  int n,m;
  while(scanf("%d %d",&n,&m)){
       if(n==-1&&m==-1)break;
       if(m==0){
         for(int i=1;i<=n;i++){
           printf(i==1?"%d":" %d",i);
         }
         puts("");
         continue;
       }
       int pos=lower_bound(arr,arr+N,m)-arr;
       for(int i=1;i<=(n-pos);i++){
         printf("%d ",i);
       }
       if(arr[pos]==m){
          for(int i=n;i>=(n-pos+1);i--){
              printf("%d ",i);
          }
       }else{
           int dif=m-arr[pos-1];
           int idx=(n-pos+1)+dif;
           printf("%d ",idx);
           for(int i=n;i>=(n-pos+1);i--){
              if(idx==i)continue;
              printf("%d ",i);
          }
          puts("");
       }
  }



}