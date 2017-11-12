/*
*  Idea : using  matrix power and make  consective range and then subtract sum(m)-sum(n-1);
*        tranfer matrix : 0 1 1
*                         1 1 1
*                         0 0 1
*
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int>row;
typedef vector<row>matrix;
const int MOD=(int)1e9+7;
matrix zero(int r,int c){
   return matrix(r,row(c,0));
}
matrix iden(const matrix &a){
   matrix ret=a;
   for(int i=0;i<(int)a.size();i++){
     ret[i][i]++;
   }
   return ret;
}
matrix mul(const matrix &a,const matrix &b){
     matrix ret=zero((int)a.size(),(int)b[0].size());
     for(int i=0;i<(int)a.size();i++){
        for(int k=0;k<(int)a[0].size();k++){
           if(!a[i][k])continue;
           for(int j=0;j<(int)b[0].size();j++){
             long long x=(1ll*a[i][k]*b[k][j]+MOD)%MOD;
             ret[i][j]=(ret[i][j]+x)%MOD;
           }
        }
     }
    return ret;
}
matrix Pow(const matrix &a,int k){
    if(!k){
      return iden(zero((int)a.size(),(int)a[0].size()));
    }
    if(k&1){
       return mul(a,Pow(a,k-1));
    }
    else 
      return Pow(mul(a,a),k/2);
}
int solve(int n){
     if(n<=0)return 0;
     matrix trans=zero(3,3);
     trans[0][1]=trans[0][2]=trans[1][0]=trans[1][1]=trans[1][2]=trans[2][2]=1;
     matrix trans_n=Pow(trans,n-1);
     matrix init=zero(1,3);
     init[0][1]=init[0][2]=1;
     matrix ret=mul(init,trans_n);
     return ret[0][2];
}
int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
       int t;
       scanf("%d",&t);
       while(t--){
         int n,m;
         scanf("%d %d",&n,&m);
         printf("%d\n",(solve(m)-solve(n-1)+MOD)%MOD);
       }
}