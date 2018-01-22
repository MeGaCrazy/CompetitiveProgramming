/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Jan 22 23:03:13 2018
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
const int N=19;
int dp[1<<(N+2)];
int a[N+2];
bool zone[N+2][N+2];
map<int,pair<int,int> >mp;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int best(int mask,int idx){
    pair<int,int> cur=a[idx];
    int opt=-1,opti=-1;
    for(int i=0;i<4;i++){
        int xx=cur.first ,yy=cur.second;
        int cnt=0;
        while(xx >=0&&yy>=0&&zone[xx][yy]&&(mask&(1<<(mp[xx,yy])))==0){
           cnt++;
           xx+=dx[i];
           yy+=dy[i];
        }
        if(cnt > opt){
          opt=cnt;
          opi=i;
        }
    }
    if(opti==-1){
      return mask|(1<<idx);
    }
     int xx=cur.first ,yy=cur.second;
     while(xx >=0&&yy>=0&&zone[xx][yy]&&(mask&(1<<(mp[xx,yy])))==0){
           mask|=(1<<mp[xx,yy]);
           xx+=dx[opti];
           yy+=dy[opti];
    }
     return mask;                              	
}
int solve(int mask){
    int &ret=dp[mask];
    if(ret!=-1){
    	return ret;
    }
    for(int i=1;i<=19;i++){
       if((mask & (1<<i))==0){
            int tmp=best(mask,i);
            if(solve(tmp)==0)return 1;
       }
    }
    return 0;

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
    string s;
    int cnt=0;
    int mask=0;
    for(int i=0;i<5;i++){
	getline(cin,s);
	for(int j=0;j<(int)s.size();j++){
	    if(s[j]==' ')continue;
	    cnt++;
	    if(s[j]=='.')mask|=(1<<cnt);	
            a[cnt]=make_pair(i,j);
            mp[make_pair(i,j)]=cnt;
	}
	zone[i][j]=1;
    }
    memset(dp,-1,sizeof(dp));
    if(solve(mask)==1){
       puts("Karlsson");
    }else{
      puts("Lillebror");
    }

}