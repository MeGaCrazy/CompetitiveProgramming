#include <bits/stdc++.h>
using namespace std;
const int N=20;
int dp[1<<N];
int solve(int mask){
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    if(mask==0){
      return ret=0;
    }
    ret=(int)1e9;
    for(int i=0;i<N;i++){
      
       if((mask&(1<<i))==0)continue;
       if((mask&(1<<i))&&i==0){
                      cerr<<i<<endl;
          ret=min(ret,solve(mask^(1<<(i+1))));
       }
       else if((mask&(1<<i))&&i==N-1){
                   cerr<<i<<endl;
          ret=min(ret,solve(mask^(1<<(i-1))));
       }
       else {
         //  if((i-1)>=0&&(mask&(1<<(i-1)))||(i+1)<N&&(mask&(1<<(i+1)))){
            cerr<<i<<endl;
            ret=min(ret,solve(mask^(1<<i)^(1<<(i+1))^(1<<(i-1)))+1);
         // }
       }
    }
    return ret;
}


int main(){
    int mask=0;
    for(int i=0,a;i<N;i++){
       scanf("%d",&a);
       if(a)mask|=(1<<i);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(mask));
}
