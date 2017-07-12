/*
*    target : make shifting and swaping with optimal way to avoid TLE
*     sol   : treat it like a tree have left and right and swap like the implemention of data-struture :) 
*            Tricky Idea: reverse elements mean that the operations 1 2 only just swaped :) 
*                      
*
*

*/

#include <bits/stdc++.h>
using namespace std;
const int N=123456;
struct node{
  int l;
  int r;
};
node arr[N];
void link(int l,int r){
    arr[r].l=l,arr[l].r=r;
}
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
      int n,m,cas=1;
      while(scanf("%d %d",&n,&m)==2){
          for(int i=1;i<=n;i++){
            arr[i].l=i-1,arr[i].r=i+1;
          }
          arr[0].l=n,arr[0].r=1,arr[n].r=0;
          bool flag=0;
          for(int i=0,q,x,y;i<m;i++){
              scanf("%d",&q);
              if(q==4){
                  flag=!flag;
                  continue;
              }
              scanf("%d %d",&x,&y);
              if(q==3){
                  if(arr[y].r==x)swap(x,y);
                  if(arr[x].r==y){
                     link(arr[x].l,arr[x].r);
                     link(x,arr[y].r);
                     link(y,x);
                  }else{
                    int yl=arr[y].l,yr=arr[y].r;
                    link(arr[x].l,y);
                    link(y,arr[x].r);
                    link(yl,x);
                    link(x,yr);
                  }
              }else{
                 if(flag)q=3-q;
                 if((q==1&&arr[y].l==x)||(q==2&&arr[y].r==x))continue;
                 if(q==1){
                     link(arr[x].l,arr[x].r);
                     link(arr[y].l,x);
                     link(x,y);
                 }else{
                     link(arr[x].l,arr[x].r);
                     link(x,arr[y].r);
                     link(y,x);
                 }
              }
          }
          // output
          long long ans=0;
          for(int i=1,tmp=0;i<=n;i++){
              tmp=arr[tmp].r;
              if(i&1)ans+=tmp;
          }
          if(flag&&n%2==0){
              ans=(long long)n*(n+1)/2-ans;
          }
         printf("Case %d: %lld\n",cas++,ans);
      }
}