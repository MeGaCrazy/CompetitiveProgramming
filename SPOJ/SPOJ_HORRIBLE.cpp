#include <bits/stdc++.h>
using namespace std;
const int N=100005;
long long  st[N*4],lazy[N*4];
void build(int p,int l,int r){
      lazy[p]=0;
      if(l==r){
         st[p]=0;
         return;
      }else{
        int mid=(l+r)>>1;
        int np=p<<1;
        build(np,l,mid);
        build(np+1,mid+1,r);
        st[p]=0;
      }
}
void pro(int p,int l,int r){
        st[p]+=(1ll*lazy[p]*((r-l)+1));
        int np=(p)<<1;
        if(l!=r){
          lazy[np]+=lazy[p];
          lazy[np+1]+=lazy[p];
        }
        lazy[p]=0;
}
void update(int p,int l,int r,int x,int y,int value){
          if(lazy[p])pro(p,l,r);
          if(l>y||x>r)return;
          int np=p<<1;
          int mid=(l+r)>>1;
          if(l>=x&&r<=y){
              st[p]+=(1ll*value*((r-l)+1));
              if(l!=r){
                 lazy[np]+=value;
                 lazy[np+1]+=value;
              }
              return;
          }
          update(np,l,mid,x,y,value);
          update(np+1,mid+1,r,x,y,value);
          st[p]=st[np]+st[np+1];
}
long long query(int p,int l,int r,int x,int y){
          if(lazy[p])pro(p,l,r);
          if(l>y||x>r||x>y)return 0;
          int np=p<<1;
          int mid=(l+r)>>1;
          if(l>=x&&r<=y){
            return st[p];
          }
          return query(np,l,mid,x,y)+query(np+1,mid+1,r,x,y);
}
int main(){
#ifndef ONLINE_JUDGE
     //  freopen("in","r",stdin);
#endif                        
      int t;
      scanf("%d",&t);
      while(t--){
          int n,q;
          scanf("%d %d",&n,&q);
          build(1,1,n);
          while(q--){
             int w,a,b,c;
             scanf("%d",&w);
             if(!w){
                scanf("%d %d %d",&a,&b,&c);
                update(1,1,n,a,b,c);
             }else{
               scanf("%d %d",&a,&b);
               printf("%lld\n",query(1,1,n,a,b));
             }
          }
      }

}
