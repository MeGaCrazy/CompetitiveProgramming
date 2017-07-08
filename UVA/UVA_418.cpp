#include <bits/stdc++.h>
using namespace std;
const int N=11;
char str[5][200];
bool vis[5];
int cur[5];
int ans;
void solve(){
      for(int i=1;i<N;i++){
          for(int j=1;j<N;j++){
             if(str[cur[0]][i]==str[cur[1]][j]){
               for(int k=i+1;k<N;k++){
                   int w=k-i;
                   for(int l=1;l<N;l++){
                      if(str[cur[0]][k]==str[cur[2]][l]){
                         for(int s=j+1;s<N;s++){
                             int w2=s-j;
                             for(int ll=1;ll<N;ll++){
                                if(str[cur[1]][s]==str[cur[3]][ll]){
                                    if(w+ll<N&&w2+l<N){
                                     if(str[cur[3]][w+ll]==str[cur[2]][w2+l]){
                                         ans=max(ans,(w-1)*(w2-1));
                                     }
                                   }
                                }
                             }
                         }
                     }
                  }
               }
             }
          }
        }

}
void dfs(int index){
   if(index==4){
     solve();
     return;
   }
   for(int i=0;i<4;i++){
       if(!vis[i]){
          vis[i]=1;
          cur[index]=i;
          dfs(index+1);
          vis[i]=0;
       }
   }
}
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
    while(scanf("%s %s %s %s",str[0],str[1],str[2],str[3])==4){
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
}