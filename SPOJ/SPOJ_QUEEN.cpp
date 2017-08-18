#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int x[8]={1,-1,0,0,1,-1,1,-1};
int y[8]={0,0,-1,1,1,-1,-1,1};
int dis[N][N];
char arr[N][N];
bool vis[N][N][8];
int r,c;
bool check(int xx,int yy){
   return xx>=0&&yy>=0&&xx<r&&yy<c&&(arr[xx][yy]=='.'||arr[xx][yy]=='F');
}
int st,en;
int ansr,ansc;
int bfs(){
      for(int i=0;i<=r;i++){
         for(int j=0;j<=c;j++){
            dis[i][j]=(int)2e9;
         }
      }
      memset(vis,0,sizeof(vis));
      for(int i=0;i<8;i++){
       vis[st][en][i]=1;
      }
      queue<pair<int,int> >q;
      q.push(make_pair(st,en));
      dis[st][en]=0;
      while(!q.empty()){
          pair<int,int>u=q.front(); 
          if(u.first==ansr&&u.second==ansc)return dis[u.first][u.second];
          q.pop();
          for(int i=0;i<8;i++){
             int xx=u.first+x[i],yy=u.second+y[i];
             while(check(xx,yy)==1){
                if(dis[xx][yy]>(dis[u.first][u.second]+1)){
                   dis[xx][yy]=(dis[u.first][u.second]+1);
                   q.push(make_pair(xx,yy));
                }else{
                 if(vis[xx][yy][i])break;
                }
                vis[xx][yy][i]=1;
                xx+=x[i],yy+=y[i];
             }
          }
      }
      return -1;
}
int main(){
#ifndef ONLINE_JUDGE
      //  freopen("in","r",stdin);
#endif
       int t;
       scanf("%d",&t);
       while(t--){
          scanf("%d %d",&r,&c);
          for(int i=0;i<r;i++){
              cin>>arr[i];              
          }
          for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]=='F'){
                   ansr=i,ansc=j;
                   continue;
               }
               if(arr[i][j]=='S'){
                 st=i,en=j;
                 continue;
               }
            }
          }
          printf("%d\n",bfs());
      }
}