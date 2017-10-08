/*
*  Idea : Just make 3x3 matrix to simulate the process start with 0 1 2
*         Tranfer Matrix is : 0 0 1
*                             1 0 1
*                             0 1 1
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int>row;
typedef vector<row>matrix;
const int MOD=(int)1e9+9;
matrix zero(int r,int c){
  return matrix(r,row(c,0));
}
matrix iden(const matrix &a){
    matrix ret=a;
    for(int i=0;i<a.size();i++){
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
             ret[i][j]+=((1ll*a[i][k]*b[k][j]*1ll))%MOD;
             ret[i][j]%=MOD;
          }
       
       }
    }
   return ret;
}
matrix Pow(const matrix &a,long long k){
    if(!k){
       return iden(zero((int)a.size(),(int)a[0].size()));
    }
    if(k&1){
       return mul(a,Pow(a,k-1));
    }
    else
     return Pow(mul(a,a),k/2);                           

}
int solve(long long n){
   if(n==1)return 0;
   if(n==2)return 1;
   matrix trans=zero(3,3);
   trans[1][0]=trans[2][1]=trans[0][2]=trans[1][2]=trans[2][2]=1;
   matrix trans_n=Pow(trans,n-3);
   matrix init=zero(3,3);
   init[0][1]=1;
   init[0][2]=2;
   matrix ret=mul(init,trans_n);
   return (ret[0][2]+MOD)%MOD;
}



int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
     long long n;
     while(scanf("%lld",&n),n){
         printf("%d\n",solve(n));
     
     }

}