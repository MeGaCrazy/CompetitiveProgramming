/*
*         First Step really easy Just get the symmetric of the i or ((int)1e+6 - i +1) where i (1<=i<=(int)1e+6)
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
bool vis[N];
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1,a;i<=n;i++){
       scanf("%d",&a);
       vis[a]=1;
    }
    vector<int>ans;
    int cnt=0;
    for(int i=1;i<=N/2;i++){
        if(vis[i]){
            if(!vis[N-i+1]){
               ans.push_back(N-i+1);
               vis[N-i+1]=1;
            }else{
              cnt++;
            }
        }else if(vis[N-i+1]){
            vis[i]=1;
            ans.push_back(i);
        }
    }
    for(int i=1;cnt&&i<=N/2;i++){
         if(!vis[N-i+1]&&!vis[i]&&cnt){
            cnt--;
            ans.push_back(i);
            ans.push_back(N-i+1);
         }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
      printf("%d ",ans[i]);
    }
}       
