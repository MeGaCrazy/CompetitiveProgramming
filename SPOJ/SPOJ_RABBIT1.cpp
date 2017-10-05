/*
*   idea: Just making Matrix power to generate fibocntaic :) 
*          transitive matrix 0 1
*                            1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int>row;
typedef vector<row>matrix;
int m;
matrix zero(int r,int c){
   return matrix(r,row(c,0));
}
matrix iden(const matrix &a){
   matrix ret=a;
   for(int i=0;i<(int)ret.size();i++){
      ret[i][i]++;
   }
   return ret;
}
matrix mul(const matrix &a,const matrix &b){
   matrix ret=zero(a.size(),b[0].size());
   for(int i=0;i<(int)a.size();i++){
       for(int k=0;k<a[0].size();k++){
         if(!a[i][k])continue;
         for(int j=0;j<(int)b[0].size();j++){
             ret[i][j]+=((1ll*a[i][k]*b[k][j])%(1<<m));
             ret[i][j]%=(1<<m);
         }
       }
   
   }
   return ret;
}
matrix Pow(const matrix &a,int k){
     if(k==0){
      return iden(zero(a.size(),a[0].size()));
     }
     if(k&1){
       return mul(a,Pow(a,k-1));
     }
     else 
       return Pow(mul(a,a),k/2);
}
int solve(int n){
     matrix trans=zero(2,2);
     trans[0][1]=trans[1][0]=trans[1][1]=1;
     matrix Ntrans=Pow(trans,max(0,n-1));
     matrix init=zero(2,2);
     init[0][0]=1,init[0][1]=1;
     matrix ret=mul(init,Ntrans);
     return ret[0][1];
}
/*
int Two_pow(int k){
    if(k==0){
      return 1;
    }
    if(k==1){
       return 2;
    }
    else if((k&1)==0){
      int ret=Two_pow(k/2); 
        return  ret*ret;
    }
    else{        
      int ret=Two_pow(k/2); 
      return (ret*ret +(ret+ret));
    }
}
*/




int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);

#endif                             
      int t;
      scanf("%d",&t);
      while(t--){
          int n;
          scanf("%d %d",&n,&m);
          printf("%d\n",solve(n)%(1<<m));
      }

}