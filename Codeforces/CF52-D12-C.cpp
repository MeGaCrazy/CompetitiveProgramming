/*
*   usual segment tree senario
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N=200000;
int arr[N];
long long st[N<<2],lazy[N<<2];
#define empty 0
void build(int p,int l,int r){
      lazy[p]=empty;
      if(l==r){
         st[p]=arr[l];
         return;
      }else{
        int mid=(l+r)>>1;
        int np=p<<1;
        build(np,l,mid);
        build(np+1,mid+1,r);
        st[p]=min(st[np],st[np+1]);
      }

}
void update(int p,int l,int r,int x,int y,int value){
         if(l>y||x>r)return;
         int mid=(l+r)>>1;
         int np=(p)<<1;
         if(l>=x&&r<=y){
            lazy[p]+=value;
            return;
         }
         update(np,l,mid,x,y,value);
         update(np+1,mid+1,r,x,y,value);
         st[p]=min(st[np]+lazy[np],st[np+1]+lazy[np+1]);
}
long long query(int p,int l,int r,int x,int y){
         if(l>y||x>r)return 1e18;
         int mid=(l+r)>>1;
         int np=p<<1;
         if(l>=x&&r<=y){
            return st[p]+lazy[p];
         }
         return min(query(np,l,mid,x,y),query(np+1,mid+1,r,x,y))+lazy[p];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    build(1,0,n-1);
    int q;
    string s;
    scanf("%d",&q);
    cin.ignore();
    while(q--){
      int tmp[5]={(int)1e9,(int)1e9,(int)1e9,(int)1e9};
      int cnt=1;
      getline(cin,s);
      istringstream in(s);
      while(in>>tmp[cnt++]);
       int l=tmp[1];
       int r=tmp[2];
       if(tmp[3]!=(int)1e9){
        if(l<=r)
          update(1,0,n-1,l,r,tmp[3]);
         else{
            update(1,0,n-1,l,n-1,tmp[3]);
            update(1,0,n-1,0,r,tmp[3]);
         }

      }else{
         if(l<=r)
         printf("%lld\n",query(1,0,n-1,l,r));
         else{
           printf("%lld\n",min(query(1,0,n-1,l,n-1),query(1,0,n-1,0,r)));
         }
      }
    }
}