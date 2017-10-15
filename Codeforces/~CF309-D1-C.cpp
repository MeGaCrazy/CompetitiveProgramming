#include <bits/stdc++.h>
using namespace std;
const int N=105;
int f[N],b[(int)1e6+7];

void build(int x){
    for(int i=30;i>=0;i--){
       if(x >= (1<<i)){
          f[i]++;
          x-=(1<<i);
       }
    }
}
void solve(int a,int b){
   f[b]--;
   for(int i=b-1;i>=a;i--){
      f[i]++;
   }
}





int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
       int n,m;
       scanf("%d %d",&n,&m);
       for(int i=0,a;i<n;i++){
          scanf("%d",&a);
          build(a);
       }
       for(int i=0;i<m;i++){
         scanf("%d",&b[i]);
       }
       sort(b,b+m);
       int ans=0;
       for(int i=0;i<m;i++){
         for(int j=b[i];j<=30;j++){
             if(f[j] >0){
                ans++;
                solve(b[i],j);
                break;
             }
         }
       }
       printf("%d\n",ans);
}