/**
*   idea :  cnt how many number from each 2^n eg arr[2^[1..n]] and then 
*           try for store the bits in first cell suitable for it ... 
*
*         Corner Case : all array will come in even number except 2^0 =1 so it best way to take the 1 cell of every  ("Odd") crustle if exist :) 
*
**/

#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e6+7;
int a[N],b[30];
int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
     int n,m;
     scanf("%d %d",&n,&m);
     for(int i=0;i<n;i++){
       scanf("%d",a+i);
     }
     sort(a,a+n);
     for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        b[x]++;
     }
     int ans=0;                 
     for(int i=0;i<n&&b[0];i++){
         if(a[i]&1){
           b[0]--;
           a[i]--;
           ans++;
         }
     }
     for(int i=0,pw=0;pw<30&&i<n;){
          if(!b[pw]){
             pw++;
             continue;
          }
          if(a[i] >= (1<<pw)){
            a[i]-=(1<<pw);
            ans++;
            b[pw]--;
          }else 
            i++;
     
     }

     printf("%d\n",ans);

}