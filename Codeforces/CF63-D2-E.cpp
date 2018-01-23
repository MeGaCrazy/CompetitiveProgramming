/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Jan 22 23:03:13 2018
*   @Idea :  First :we need to put for each point put it's number for example [0][2]=0 [0][6]=1 and so one 
*            to make us able to statisfy it's choices coool ... 
*
*            Second: We will make Mask and every O will Put 1 For Each Point try to get all his choices from goining diagonal 
*                    and columns and Put in Vector 
*	
*            Third : Try From state number 1 to CurrentState[That contain the o's in mask]
*                    if state number i is belong to CurrentState how I know if CurrentState & i == i :)
*                    Second Try For Each state to Win 
*
*            Fourth : Check if Move is beelong to state number I with same trick :) and if I take Do Move I win Then I Can Win in 
*                     this state 
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N = 19;
int zone[N][N];
int Win[(1<<N)+7];
int dx[] = {0,1,1};
int dy[] = {2,-1,1};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	//  freopen("out","w",stdout);
#endif
	string s[5];
	int cnt = 0;
	int mask=0;
	memset(zone, -1, sizeof(zone));
	memset(Win,0,sizeof(Win));
	vector<int>v;
	for (int i = 0; i<5; i++) {
		getline(cin, s[i]);
		for (int j = 0; j<(int)s[i].size(); j++) {
			if (s[i][j] == ' ')continue;
			if(s[i][j]=='O')mask|=(1<<cnt);
			zone[i][j] = cnt++;
		}
	}
	for(int i=0;i<5;i++){
	   for(int j=0;j<(int)s[i].size();j++){
	        if(s[i][j]==' ')continue;
	     	for(int k=0;k<3;k++){
                   int xx=i;
 	     	   int yy=j;
	     	   int curmove=0;
     	            while (xx >= 0 && yy >= 0 && zone[xx][yy]!=-1) { 	
			     curmove|=(1<<(zone[xx][yy]));
			     v.push_back(curmove);
			     xx += dx[k];
			     yy += dy[k];
		    }
	       }   
	  }
       }
       for(int i=1;i<=mask;i++){
           if( (mask & i)!=i)continue;
           for(int j=0;j<(int)v.size();j++){
              if( (i & v[j])==v[j] && !Win[ i ^ v[j]]){
                   Win[i]=1;
                   break;
              }
           }
       }
       if(Win[mask]){
         printf("Karlsson");
       }else{
         printf("Lillebror");
       }

}