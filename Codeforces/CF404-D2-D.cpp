#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5,rem=1e9+7;
long long  dp[N][5];



int main(){
    string s;
    cin>>s;
    if(s[0]=='2'){
      puts("0");
      return 0;
    
    }
    else if(s[0]=='?')dp[0][0]=dp[0][1]=dp[0][3]=1;
    else if(s[0]=='0')dp[0][0]=1;
    else if(s[0]=='1')dp[0][1]=1;
    else if(s[0]=='*')dp[0][3]=1;
    int n=s.length();
    for(int i=1;i<n;i++){
       if(s[i]=='?'||s[i]=='0')dp[i][0]=(dp[i-1][0]+dp[i-1][4])%rem;
       if(s[i]=='?'||s[i]=='1'){
          dp[i][1]=(dp[i-1][0]+dp[i-1][4])%rem;
          dp[i][4]=dp[i-1][3];
       }
       if(s[i]=='2'||s[i]=='?')dp[i][2]=dp[i-1][3];
       if(s[i]=='*'||s[i]=='?')dp[i][3]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%rem;
    }
    cout<<((dp[n-1][0]+dp[n-1][3]+dp[n-1][4])%rem)<<endl;
}
