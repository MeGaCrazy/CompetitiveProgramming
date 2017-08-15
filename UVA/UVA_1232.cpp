/*
*   Twist using of Segment Tree 
*   There is no need for query founction just if in range and valid that >= max height get add to answer :)
*    Second if there is in interval height less than the mx height that get from other parent interval the 
*    Update Function won't see it so u need to get varabile mn also to manage that he can go further :) 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e5+7;
struct node{
  int lazy;
  int mx;
  int mn;
};
node st[N*4];
int ans;
void pro(int p){
     if(st[p].lazy){
        int np=p<<1;
        st[np].mx=st[np].mn=st[np].lazy=st[p].lazy;
        st[np+1].mx=st[np+1].mn=st[np+1].lazy=st[p].lazy;
     }
     st[p].lazy=0;
}
void update(int p,int l,int r,int a,int b,int h){
       if(l>b||a>r)return;
       if(l!=r){
        pro(p);
       }
       if(st[p].mn>h)return;
       if(l>=a&&r<=b){
         if(h>=st[p].mx){
            ans+=(r-l+1);
            st[p].mx=st[p].mn=st[p].lazy=h;
            return;
         }
       }
       int mid=(l+r)>>1;
       int np=(p)<<1;
       if(a>mid){
         update(np+1,mid+1,r,a,b,h);
       }else if(b<=mid){
           update(np,l,mid,a,b,h);
       }else{
         update(np,l,mid,a,b,h);
         update(np+1,mid+1,r,a,b,h);
       }

       st[p].mx =max(st[np].mx, st[np + 1].mx);
       st[p].mn=min(st[np].mn,st[np+1].mn);
}
int main(){
  freopen("in","r",stdin);
   int t;
   scanf("%d",&t);
   while(t--){
      int n;
      scanf("%d",&n);
      memset(st,0,sizeof(st));
      ans=0;
      for(int i=1,a,b,c;i<=n;i++){
         scanf("%d %d %d",&a,&b,&c);
          update(1,1,N-7,a,b-1,c);
      }
      printf("%d\n",ans);
   }
}