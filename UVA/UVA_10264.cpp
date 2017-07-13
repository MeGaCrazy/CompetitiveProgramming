/*
*   target : get the maximum sum of two adjacent corner
*   sol    :1- if we have corner like that (1,0,1) so each adjacent is The one have same coordinate but different in one only like (0,0,1)
*           2- to check that make xor for the two coordinate then if they different in Only one bit so they are corner :)
*           3- to check they difference in only one corrdiante just check if number is 2^n or not u see 
*            only number 2^n if make & with thery negative number will get the same number :)
*            the forumla: 2^n &(-2^n) = 2^n
*
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N=1<<15;
int arr[N];
bool check(int i,int j){
  int x=i^j;
  return (x&(-x))==x;
}

int main(){
     int n;
     //freopen("in","r",stdin);
     while(scanf("%d",&n)==1){
         memset(arr,0,sizeof(arr));
          for(int i=0,x;i<(1<<n);i++){
               scanf("%d",&x);
               for(int j=0;j<(1<<n);j++){
                   if(i!=j&&check(i,j))arr[j]+=x;
               }
          }
          int ans=0;
          for(int i=0;i<(1<<n);i++){
              for(int j=0;j<(1<<n);j++){
                  if(i!=j&&check(i,j)){
                     ans=max(ans,arr[i]+arr[j]);
                  }
              }
          }
       //   fprintf(stderr,"the time is %d\n ms",(int)clock());
          printf("%d\n",ans);
     }
}