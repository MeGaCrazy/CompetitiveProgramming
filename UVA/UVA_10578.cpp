/*
*     Idea : u must statisfy some condition not choose more than 4 from each type and choose efficent stratigy every time :) 
*            So the state is [rem][one][two][three][four][five][six] O( (31*5^6)*6 ~=3 million );
*            Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
int N=31;
int dp[32][5][5][5][5][5][5];
int cnt[7];
bool solve(int rem,int one,int two,int three,int four,int five,int six){
     int &ret=dp[rem][one][two][three][four][five][six];
     if(ret!=-1)return ret;
     if(rem==0){
       return ret=0;
     }
     ret=0;
     for(int i=1;i<=6;i++){
        if(rem-i>=0){
            if(i==1&&one&&solve(rem-i,one-1,two,three,four,five,six)==0)return ret=1;
            if(i==2&&two&&solve(rem-i,one,two-1,three,four,five,six)==0)return ret=1;
            if(i==3&&three&&solve(rem-i,one,two,three-1,four,five,six)==0)return ret=1;
            if(i==4&&four&&solve(rem-i,one,two,three,four-1,five,six)==0)return ret=1;
            if(i==5&&five&&solve(rem-i,one,two,three,four,five-1,six)==0)return ret=1;
            if(i==6&&six&&solve(rem-i,one,two,three,four,five,six-1)==0)return ret=1;
        }
     }
     return ret=0;
}
int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
    string s;
    while(cin>>s){
      memset(dp,-1,sizeof(dp));
      for(int i=1;i<=6;i++)cnt[i]=4;
      int n=s.size();
      int sum=0;
      for(int i=0;i<n;i++){
         sum+=(s[i]-'0');
         cnt[(s[i]-'0')]--;
      }
      cout<<s<<" ";
      if(N-sum <=0){
         cout<<((n&1)==1?"A":"B")<<endl;
      }else{
       int dif=N-sum;
       bool ok=solve(dif,cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],cnt[6]);
       if(ok&&(n&1)==0||!ok&&(n&1)==1){
           puts("A");
       }else{
           puts("B");
       }
     //  cerr<<dif<<" => "<<ok<<endl;
      }
    }  
}