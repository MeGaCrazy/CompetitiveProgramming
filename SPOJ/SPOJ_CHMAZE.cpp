/*
*           simple bfs just every next step he go to next pattern :)2
*
*/

#include <bits/stdc++.h>
using namespace std;
char arr[11][21][21];
int dis[11][21][21];
int r,c,t;
int x[]={0,0,0,-1,1};
int y[]={0,1,-1,0,0};
bool check(int i,int j){
     return i>=0&&j>=0&&i<r&&j<c;
}
int bfs(){
    queue<pair<int,pair<int,int> > >q;
    dis[0][0][0]=0;
    q.push(make_pair(0,make_pair(0,0)));
    while(!q.empty()){
        pair<int,pair<int,int> >u=q.front();
        q.pop();
        for(int i=0;i<5;i++){
          int xx=u.second.first+x[i],yy=u.second.second+y[i];
          int next_step=(u.first+1)%t;
          if(check(xx,yy)&&dis[next_step][xx][yy]==-1&&arr[next_step][xx][yy]=='0'){
                q.push(make_pair(next_step,make_pair(xx,yy)));
                dis[next_step][xx][yy]=dis[u.first][u.second.first][u.second.second]+1;
                if(xx==r-1&&yy==c-1){
                  return dis[next_step][xx][yy];
                }
          }
        }
    }

  return -1;
}
int main(){
#ifndef ONLINE_JUDGE
        freopen ("in.txt","r",stdin);
#endif
       int cas=1;
       while(scanf("%d %d %d",&r,&c,&t),(r||c||t)){
           for(int i=0;i<t;i++){
               for(int j=0;j<r;j++){
                 scanf("%s",&arr[i][j]);
               }
           }
           memset(dis,-1,sizeof(dis));
            int ans=bfs();
            printf("Case %d: ",cas++);
            if(ans==-1){
             printf("Luke and Leia cannot escape.\n");
            }else{
              printf("Luke and Leia can escape in %d steps.\n",ans);
            }
       }


}