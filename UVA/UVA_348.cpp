/*
*     The transfer formula 
*          :  DP [l] [s] = min (dp[l][k]+dp[k+1][s] + multiplication cost(p[l]*p[k]*p[s])) {l <k<s};
*              For Proves it's correctness : https://www.youtube.com/watch?v=u6Y055g4mOE&t=460s
*              Or from this paper http://www3.cs.stonybrook.edu/~jgao/CSE548-fall07/David-mount-DP.pdf
*              And the second issue to get the path 
*                                   from the the forumla the k get from 2 interval so the key is have interval i,j 
*                                   and branch left and right with k that has been stored
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=12;
struct node{
  int r;
  int c;
};
node arr[N];
int dp[N][N];
int path[N][N];
void p(int i,int j){
        if(i==j){
           printf("A%d",i+1);
           return;
        }else{
           int mid=path[i][j];
           printf("(");
           p(i,mid);
           printf(" x ");
           p(mid+1,j);
           printf(")");
        }
}

int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
        int n,Case=1;
        while(scanf("%d",&n),n){
            for(int i=0;i<n;i++){
              scanf("%d %d",&arr[i].r,&arr[i].c);
            }
            for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                if(i==j)dp[i][j]=0;
                else  dp[i][j]=(int)2e9;
              }

            }
           memset(path,0,sizeof(path));
           for(int k=1;k<n;k++){
              for(int i=0;i+k<n;i++){
                 for(int j=i;j<(k+i);j++){
                    int cost=dp[i][j]+dp[j+1][i+k]+arr[i].r*arr[j].c*arr[k+i].c;
                    if(dp[i][k+i] > cost){
                       dp[i][k+i]=cost;
                       path[i][k+i]=j;
                     }
                 }
              }
           }
           printf("Case %d: ",Case++);
           p(0,n-1);
           puts("");           
        }
}