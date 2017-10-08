/*
*  Idea : make Matrix Power 1x4 0 1 1 1
*          First col=Contain Current ans;
*          Second col=Next Sum;
*          Third col=N
*          Fourth col=counter to make n+1 :) 
*
*          Transfer matrix be like that to verify the sequence =  0 1 0 0
*                                                                 1 1 0 0 
*                                                                 0 1 1 0
*                                                                 0 0 1 1
*
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int>row;
typedef vector<row>matrix;
int n,m;
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
               ret[i][j]+=(a[i][k]*b[k][j]*1ll)%m;
               ret[i][j]%=m;
            }
         }
      }
      return ret;
}
matrix Pow(const matrix &a,int k){
     if(k==0){
       return iden(zero((int)a.size(),(int)a[0].size()));
     }
     if(k&1){
       return mul(a,Pow(a,k-1));
     }
     else
       return Pow(mul(a,a),k/2);
}
int solve(){
     matrix trans=zero(4,4);
     trans[1][0]=trans[0][1]=trans[1][1]=trans[2][1]=trans[2][2]=trans[3][2]=trans[3][3]=1;
     matrix init=zero(1,4);
     init[0][1]=init[0][2]=init[0][3]=1;
     matrix trans_n=Pow(trans,n);
     matrix ret=mul(init,trans_n);
     return ret[0][0];
}



int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
         scanf("%d %d",&n,&m);
         printf("%d\n",solve());
     
     }

}
