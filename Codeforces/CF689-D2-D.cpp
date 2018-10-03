/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Sep 24 17:01:52 2018
*   @Idea :
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+7;
int Max[N<<2],Min[N<<2];
int a1[N],a2[N];
int build(int p,int l,int r,bool ind){
	if(l==r){
	   if(ind){
	   	return Max[p]=a1[l];
	   }else{
	   	return Min[p]=a2[l];
	   }
	}
	int np=p<<1;
	int mid=(l+r)>>1;
	int left=build(np,l,mid,ind);
	int right=build(np+1,mid+1,r,ind);
	if(ind){
	 return Max[p]=max(left,right);
	}else{
	 return Min[p]=min(left,right);
	}
}

int query(int p,int l,int r,int x,int y,bool ind){
      
        if(x>r || l>y){
          return ind?-2e9:2e9;   	 
        }
        if(x<=l&&r<=y){
           if(ind){
            return Max[p];
           }
           return Min[p];
        }
        int np=p<<1;
        int mid=(l+r)>>1;
        int left=query(np,l,mid,x,y,ind);
        int right=query(np+1,mid+1,r,x,y,ind);
        if(ind){
              return max(left,right);
        }else{
             return min(left,right); 	
        }
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a1[i]);
    }
    for(int i=1;i<=n;i++){
    	scanf("%d",&a2[i]);
    }
    build(1,1,n,0);
    build(1,1,n,1);
    long long ans=0;
    
    for(int i=1;i<=n;i++){

       if (a1[i] > a2[i])
          continue;
       int fmax=a1[i];
       int fmin=a2[i];
       int st=i,en=n+1;
       while(en-st>1){
           int mid=(en+st)>>1;
           int maxx=query(1,1,n,st,mid,1);
           int minn=query(1,1,n,st,mid,0);

           if(maxx <= minn)st=mid;
           else en=mid-1;
       }
       if(query(1,1,n,st,en,1)<=query(1,1,n,st,en,0)){
          st=en;
       }
       int right=st;
       st=i,en=n+1;
       while(en-st>1){
           int mid=(en+st)>>1;
           int maxx=query(1,1,n,st,mid,1);
           int minn=query(1,1,n,st,mid,0);
           if(maxx < minn)st=mid;
           else en=mid-1;
       }
       if(query(1,1,n,st,en,1)<query(1,1,n,st,en,0)){
          st=en;
      }
       else if(query(1,1,n,i,st,1)>=query(1,1,n,i,st,0)){
         st=st-1;
       }

       int left=st;
       cerr<<i<<" "<<left<<" "<<right<<endl;
       ans+=(right-left
       );
    } 
    printf("%lld\n",ans);

}