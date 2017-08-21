/*
*   exactly like in tutorial 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int ci[N],cj[N];
long long x[N],y[N];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         scanf("%d",&a);
         ci[i]+=a;
         cj[j]+=a;
      }
    }
    int ansi,ansj;
    long long mini=8e18,minj=8e18;   
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          x[i]+=1ll*(2*i-2*j-1)*(2*i-2*j-1)*ci[j];
       }
       if(x[i]<mini){
         mini=x[i];
         ansi=i;
       }
    }
    for(int i=0;i<m;i++){
       for(int j=0;j<m;j++){
         y[i]+=1ll*(2*i-2*j-1)*(2*i-2*j-1)*cj[j];
       }
       if(y[i]<minj){
         minj=y[i];
         ansj=i;
       }
    }
    printf("%I64d\n%d %d",4*(mini+minj),ansi,ansj);
}