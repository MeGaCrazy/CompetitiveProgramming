/**
*    idea : due to sort work lexiographical check everyone with his next 
**/

#include <bits/stdc++.h>
using namespace std;


const int N=10005;
string s[N];
set<string>a[N];

int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        bool f=1;
        sort(s+1,s+n+1);
        for(int i=1;i<n;i++){
             if(s[i+1].size()>=s[i].size()){
               string x=s[i+1].substr(0,s[i].size());
                if(x==s[i]){
                  f=0;
                  break;
                }
             }
        }
        if(!f){
          puts("NO");
        }else{
          puts("YES");
        }
    
    }

}