/*
*   idea : Generate the fibonacci by Matrix Power and then the ans is =2*fib(n)-1%b
*         Take Care if the mod go to Negative So make (2*fib(n)-1+b)%b
*
*
*/
#include <bits/stdc++.h>
using namespace std;
int mod;
typedef vector<int>row;
typedef vector<row>matrix;
matrix zero(int r,int c){
  matrix ret=matrix(r,row(c,0));
   return ret;
}
matrix iden(const matrix &a){
    matrix ret=a;
    for(int i=0;i<(int)a.size();i++){
      ret[i][i]++;
    }
    return ret;
}
matrix mul(const matrix &a,const matrix &b){
    matrix ret=zero(a.size(),b[0].size());
    for(int i=0;i<(int)a.size();i++){
       for(int k=0;k<(int)a[0].size();k++){
           if(!a[i][k])continue;
           for(int j=0;j<(int)b[0].size();j++){
            ret[i][j]+=(1ll*a[i][k]*b[k][j]);
            ret[i][j]%=mod;
           }
       }
    
    }
    return ret;
}
matrix Pow(const matrix &a,long long  k){
    if(k==0)
    {
      return iden(zero(a.size(),a[0].size()));
    }
    if(k&1){
       return mul(a,Pow(a,k-1));
    }
    else 
      return Pow(mul(a,a),k/2);
}
int solve(long long n){
    matrix trans=zero(2,2);
    trans[0][1]=trans[1][0]=trans[1][1]=1;
    matrix n_trans=Pow(trans,max(0ll,n-1));           
    matrix init=zero(2,2);
    init[0][0]=init[0][1]=1;
    matrix ret=mul(init,n_trans);
    return ret[0][1];
}






int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
     long long n;
     int b,Cas=1;
     while(scanf("%lld %d",&n,&b),(n||b)){
       printf("Case %d: ",Cas++);
        printf("%lld %d ",n,b);
        mod=b;
        printf("%d\n",(solve(n)*2-1+mod)%mod);
     }
}