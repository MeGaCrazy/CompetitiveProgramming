/*
*   Idea:
*        Using Segment Tree => make RSQ Tree okey 
*        Then make he move depend on the number of elemnts before him like we move from last
*        and then i want to move 1 step back then i should be in take the n-1 place now and this place mark is taken By One :)
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int st[4*N];
int arr[N];
int ans[N];
void build(int p,int l,int r){
    if(l==r){
      st[p]=1;
      return;
    }
    int np=p<<1;
    int mid=(l+r)>>1;
    build(np,l,mid);
    build(np+1,mid+1,r);
    st[p]=st[np]+st[np+1];
}
int query(int p,int l,int r,int x){
   if(l==r){
     return l;
   }
   int np=p<<1,mid=(l+r)>>1;
   if(st[np]>=x){
     return query(np,l,mid,x);
   }else{
     return query(np+1,mid+1,r,x-st[np]);
   }
}
void update(int p,int l,int r,int x){
     if(l==r){
       st[p]=0;
       return;
     }
     int np=p<<1,mid=(l+r)>>1;
     if(mid>=x){
        update(np,l,mid,x);
     }else{
       update(np+1,mid+1,r,x);
     }
     st[p]=st[np]+st[np+1];
}
int main(){
     int t;
     scanf("%d",&t);
     while(t--){
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;i++){
         scanf("%d",arr+i);
       }
       build(1,0,n-1);
       for(int i=n-1;i>=0;i--){
            ans[i]=query(1,0,n-1,(i+1)-arr[i]);
            update(1,0,n-1,ans[i]);
       }
       for(int i=0;i<n;i++){
          printf(i==0?"%d":" %d",ans[i]+1);
       }
       puts("");
     }
}