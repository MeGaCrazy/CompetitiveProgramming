/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Dec 29 08:27:36 2017
*   @Idea :   Using BIT and Binary Search
*             1- U can't store values 1e9 in bit so u depend in values position after overall insertion it max 2e5 still valid :)
*             2- treat with the pos for insertion and deletion
*             3- Do Binary Search k-th smallest element
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
pair<char,int>a[N];
int f[N];
int bit[N];
bool ext[N];
void update(int idx,int value){
    while(idx <= N){
       bit[idx]+=value;
       idx += (idx & -idx);
    }
}
int Query(int idx){
    int ret=0;
    while(idx > 0){
      ret+= bit[idx];
      idx -= (idx & -idx);
    }
    return ret;
               }
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
//   freopen("out","w",stdout);
#endif
      int n;
      scanf("%d",&n);
      char c;
      int v;
      int len=0;
      set<int>s;
      for(int i=0;i<n;i++){
         scanf(" %c %d",&c,&v);
         if(c=='I'&&s.count(v)==0){
           f[++len]=v;
      	   s.insert(v);
         }
         a[i]=make_pair(c,v);
      }
      sort(f+1,f+len+1);
      for(int i=0;i<n;i++){
        c = a[i].first;
        v = a[i].second;
        if(c=='I'){
           int pos = lower_bound(f+1,f+len+1,v)-f;
           if(ext[pos]==0) update(pos,1);
           ext[pos]=1;
        }else if(c=='D'){
           int pos = lower_bound(f+1,f+len+1,v)-f;
           if(ext[pos]==1&&f[pos]==v){
             update(pos,-1);
             ext[pos]=0;
          }

        }else if(c=='C'){
           int pos = lower_bound(f+1,f+len+1,v)-f;
           printf("%d\n",Query(pos-1));
        }else{
          int l=1;
          int r=len;
          while(l<=r){
            int mid=(l+r)>>1;
            if(Query(mid) >= v)r=mid-1;
            else l=mid+1;
          }
          if(l > len){
            puts("invalid");
          }else{
            printf("%d\n",f[l]);
          }
        
        }
      }

}