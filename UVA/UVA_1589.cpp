/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 01 07:11:03 2018
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
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
const int N=15;
char a[N][N];
bool Valid(int x,int y){
  return 1<=x&&x<=10&&1<=y&&y<=9;
}
bool charMove(int x,int y,int xx,int yy){
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        while(Valid(nx,ny)&&a[nx][ny]=='-'){
           if(nx==xx&&ny==yy)return 1;
            nx+=dx[i];
            ny+=dy[i];
        }
    }
    return 0;
}
bool cannonMove(int x,int y,int xx,int yy){
   for(int i=0;i<4;i++){
      int nx=x+dx[i],ny=y+dy[i];
      while(Valid(nx,ny)&&a[nx][ny]=='-'){
         nx+=dx[i],ny+=dy[i];
      }
      if(Valid(nx,ny)&&a[nx][ny]!='-'){
          nx=x+dx[i],ny=y+dy[i];
          while(Valid(nx,ny)&&a[nx][ny]=='-'){
           if(nx==xx&&ny==yy)return 1;
           nx+=dx[i],ny+=dy[i];
         }
         if(Valid(nx,ny)&&nx==xx&&ny==yy)return 1;
      }
   }
   return 0;

}           
bool horseMove(int x,int y,int xx,int yy){
    int hx[]={2,2, -2,-2,1, 1,-1,-1};
    int hy[]={1,-1, 1,-1,2,-2,2,-2};
    int fx[]={1,1, -1,-1,0, 0,0,0};
    int fy[]={0,0,  0,0, 1,-1,1,-1};
    for(int i=0;i<8;i++){
       int nx=x+hx[i],ny=y+hy[i];
       if(nx==xx&&ny==ny){
         int tx=x+fx[i],ty=y+fy[i];
         if(Valid(tx,ty)&&a[tx][ty]=='-'){
           return 1;
         }
       }
    }
    return 0;
}

bool Solve(int x,int y){
    for(int i=1;i<=10;i++){
        for(int j=1;j<=9;j++){
            //if(x==i&&y==j)continue;
            if(a[i][j]=='G'){
                if(charMove(i,j,x,y))return 1;
            }else if(a[i][j]=='R'){
                if(charMove(i,j,x,y))return 1;
            }else if(a[i][j]=='H'){
                if(horseMove(i,j,x,y))return 1;
            }else if(a[i][j]=='C'){
                if(cannonMove(i,j,x,y))return 1;
            }
        }
    }
   return 0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   freopen("out","w",stdout);
#endif
    int n,x,y;
    while(scanf("%d %d %d",&n,&x,&y),(x||y||n)){
         for(int i=0;i<=10;i++){
            for(int j=0;j<=10;j++){
              a[i][j]='-';
            }
         }
         for(int i=0;i<n;i++){
            int xx,yy;
            char c;
            scanf(" %c %d %d",&c,&xx,&yy);
            a[xx][yy]=c; 
         }
         bool f=1;
         for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
           
            if(!Valid(nx,ny)||!(1 <= nx && nx <= 3 && 4 <= ny && ny <= 6)){
              continue;
            }
            char temp=a[nx][ny];
            a[nx][ny]='-';
   	    f &= Solve(nx, ny);
            a[nx][ny]=temp;
         }
                     getchar();
          puts(f?"YES":"NO");    
    }



}