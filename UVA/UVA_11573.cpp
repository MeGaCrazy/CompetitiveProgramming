/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Oct 03 14:38:44 2018
*   @Idea :  Just usual dijktstra
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int cost[1001][1001];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};

int r,c;
int solve(int x,int y,int xx,int yy){
    if(x==xx&&y==yy)return 0;
     memset(cost,-1,sizeof(cost));
     cost[x][y]=0;
     priority_queue< pair<int,pair<int,int> >,vector< pair<int,pair<int,int> > >,greater< pair<int,pair<int,int> > > >pq;
     pq.push(make_pair(cost[x][y],make_pair(x,y)));
     while(!pq.empty()){

        int fx=pq.top().second.first;
        int fy=pq.top().second.second;
     //  cerr<<fx<<" "<<fy<<endl;
        int cur_cost=pq.top().first;
      	pq.pop();
        if(fx==xx&&fy==yy){
           return cost[fx][fy];
        }
        if(cost[fx][fy] < cur_cost)continue;
        for(int i=0;i<8;i++){
            int idx=dx[i]+fx;
            int idy=dy[i]+fy;
            int nxt_cost=a[fx][fy]==(i)?0:1;
            if( idx >=1 && idx <= r && idy>=1 && idy<= c && (cost[idx][idy]==-1 || cost[idx][idy] > cur_cost+nxt_cost)){
               cost[idx][idy]=cur_cost+nxt_cost;
               pq.push(make_pair(cost[idx][idy],make_pair(idx,idy)));
            }
        }
     
     }
     return cost[xx][yy]; 

}


int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
   // int r,c;
    scanf("%d %d",&r,&c);
    char s[1001];
    for(int i=1;i<=r;i++){
        scanf("%s",&s);
     	for(int j=1;j<=c;j++){
     	   a[i][j]=s[j-1]-'0'; 	
     	}	
    }
     int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
       int x,y,xx,yy;
       scanf("%d %d %d %d",&x,&y,&xx,&yy);
       int ans=solve(x,y,xx,yy);
       printf("%d\n",ans);
    }



}