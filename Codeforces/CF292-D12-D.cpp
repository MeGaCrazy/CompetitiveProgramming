/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Oct 06 16:58:43 2018
*   @Idea :  make consective range from left to right and from right to left ... making Joining component using 
*            Disjointset algorithm to get parent. and if save only number of edges that not have same parent 
*            then for each query check the number of edge of our saved numbers if is not included in range join it and 
*            at last check the number of nodes that it's parent equal itself.
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=500,M=2e4+7;
int s[M],e[M],vis[M],r[M];
int p[N];

int Find(int x){
 return p[x]==x?x:p[x]=Find(p[x]);
}	
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
    	scanf("%d %d",&a,&b);
    	s[i]=a;
    	e[i]=b;
    }
    int cnt=0;
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++){
       	int x=Find(s[i]);
       	int y=Find(e[i]);
       	if(x!=y){
       	   vis[i]=1;
       	   p[y]=x;
       	   r[cnt++]=i;
       	}
    }
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=m;i>=1;i--){
       int x=Find(s[i]);
       int y=Find(e[i]);
       if(x!=y){
          if(!vis[i]){
             vis[i]=1;
             r[cnt++]=i;
          }
          p[y]=x;
       }
    }
    int k;
    scanf("%d",&k);
    while(k--){
        int from,to;
        scanf("%d %d",&from,&to);
        for(int i=1;i<=n;i++)p[i]=i;
        for(int i=0;i<cnt;i++){
            if(r[i] < from || r[i] > to){
                 int x=Find(s[r[i]]);
                 int y=Find(e[r[i]]);
                 if(x!=y){
                   p[y]=x;
                 }
            } 
        }
      int ans=0;
      for(int i=1;i<=n;i++){
         if(p[i]==i)ans++;
      }
      printf("%d\n",ans);
    }
}