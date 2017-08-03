/*
*    Just using lazy propagation
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1024000;
int st[N*4],lazy[N*4];
string str;
#define zero 0
#define one 1
#define flip 2
#define empty 3
void build(int p,int l,int r){
     lazy[p]=empty;
     if(l==r){
        st[p]=(str[l]=='0')?0:1;
        return;
     }else{
       int mid=(l+r)/2;
       build(2*p,l,mid);
       build(2*p+1,mid+1,r);
       st[p]=st[2*p]+st[2*p+1];
     }
}
int Flip(int x){
   if(x==one)return zero;
   if(x==zero)return one;
   if(x==flip)return empty;
   return flip;
}
void propagate(int p,int l,int r){
     if(lazy[p]==empty)return ;
     if(lazy[p]==one){
         st[p]=(r-l+1);
     }
     else if(lazy[p]==zero){
           st[p]=0;
     }
     else if(lazy[p]==flip){
          st[p]=(r-l+1)-st[p];
     }
     if(l!=r){
         if(lazy[p]==one||lazy[p]==zero){
            lazy[2*p]=lazy[2*p+1]=lazy[p];
         }else{
           lazy[2*p]=Flip(lazy[2*p]);
           lazy[2*p+1]=Flip(lazy[2*p+1]);
         }
     }
     lazy[p]=empty;
}
void update(int p,int l,int r,int x,int y,int value){
       if(lazy[p]!=empty)propagate(p,l,r);
       if(x>r||l>y)
           return ;
      if(l>=x&&r<=y){
          if(value==one||value==zero){
            st[p]=(r-l+1)*value;
            lazy[2*p]=value;
            lazy[2*p+1]=value;
          }else{
            st[p]=(r-l+1)-st[p];
            lazy[2*p]=Flip(lazy[2*p]);
            lazy[2*p+1]=Flip(lazy[2*p+1]);
          }
          return ;
      }
      int mid=(l+r)/2;
      update(2*p,l,mid,x,y,value);
      update(2*p+1,mid+1,r,x,y,value);
      st[p]=st[2*p]+st[2*p+1];
}
int query(int p,int l,int r,int x,int y){
       if(lazy[p]!=empty)propagate(p,l,r);
       if(x>r||l>y)
           return 0;
       if(l>=x&&r<=y){
         return st[p];
       }
       int mid=(l+r)/2;
       return query(2*p,l,mid,x,y)+query(2*p+1,mid+1,r,x,y);

}
int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
       int t,cas=1;
       scanf("%d",&t);                                                     
       while(t--){
          printf("Case %d:\n",cas++);
          int n;
          scanf("%d",&n);
          str="";
          string tmp;
          for(int i=0,rep;i<n;i++){
               scanf("%d",&rep);
               cin>>tmp;
               while(rep--)str+=tmp;
          }
          n=str.length()-1;
          build(1,0,n);
          int q;
          scanf("%d",&q);
          char c; int a,b;
          int Q=1;
          while(q--){
               scanf(" %c %d %d",&c,&a,&b);
               if(c=='F'){
                  update(1,0,n,a,b,one);
               }else if(c=='E'){
                 update(1,0,n,a,b,zero);
               }else if(c=='I'){
                 update(1,0,n,a,b,flip);
               }else{
                printf("Q%d: %d\n",Q++,query(1,0,n,a,b));
               }
          }
       }



}