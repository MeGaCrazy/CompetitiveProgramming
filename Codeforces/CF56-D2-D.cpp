/*
*     Idea : Just make DP output builder and for dp the choices for really clear
*            But some Corner Case need to consider to avoid Runtime Error
*            pos of string s reach it's end but the other still u must insert and in reverse case u must delete :)
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N][N];

string s,t;
int solve(int i,int j){
       int &ret=dp[i][j];
       if(ret!=-1)return ret;
       ret=0;
       if(i==s.size()&&j==t.size())return ret=0;
       if(i==s.size()&&j<t.size()){
         ret=solve(i,j+1)+1;
       }else if(i<s.size()&&j==t.size()){
          ret=solve(i+1,j)+1;
       }
       else if(s[i]==t[j]){
         ret=solve(i+1,j+1);
       }else{
         ret=min(solve(i,j+1),min(solve(i+1,j),solve(i+1,j+1)))+1;
       }
       return ret;                                                          
}
void out(int i,int j){
      if(i==s.size()&&j==t.size())return ;
      if(i==s.size()&&j<t.size()){
         printf("INSERT %d %c\n",j+1,t[j]);
         out(i,j+1);
       }else if(i<s.size()&&j==t.size()){
         printf("DELETE %d\n",j+1);
         out(i+1,j);
       }
      else if(s[i]==t[j]){
        out(i+1,j+1);
      }else{
      int ins=solve(i,j+1)+1;
      int del=solve(i+1,j)+1;
      int rep=solve(i+1,j+1)+1;
      int f=min(ins,min(del,rep));
      if(f==rep){
        printf("REPLACE %d %c\n",j+1,t[j]);
        out(i+1,j+1);
      }else if(f==ins){
        printf("INSERT %d %c\n",j+1,t[j]);
        out(i,j+1);
      }else if(f==del){
        printf("DELETE %d\n",j+1);
        out(i+1,j);
      }          
    }
}
int main(){
      cin>>s>>t;
      memset(dp,-1,sizeof(dp));
      int ans=solve(0,0);
      printf("%d\n",ans);
      out(0,0);
}




