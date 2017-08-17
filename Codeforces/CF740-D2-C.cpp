#include <bits/stdc++.h>
using namespace std;
int main(){ 
     int n,m;
     scanf("%d %d",&n,&m);
     int ans=1e9;
     for(int i=1,a,b;i<=m;i++){
       scanf("%d %d",&a,&b);
       ans=min(ans,b-a+1);
     }
     printf("%d\n",ans);
     for(int i=0;i<n;i++){
        printf("%d ",i%ans);
     }
}