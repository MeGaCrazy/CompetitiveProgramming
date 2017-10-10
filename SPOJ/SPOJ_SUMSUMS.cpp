/*
        idea : trans matrix is = 0 n-1
                                 1 n-2

               base matrix = a[i] sum-a[i]
                               0    0
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int>row;
typedef vector<row>matrix;
const int MOD=98765431ll;
const int N=50500;
int arr[N];
matrix zero(int r, int c){
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
                 ret[i][j]=(ret[i][j]+1ll*a[i][k]*b[k][j])%MOD;
               }
           }
       }
       return ret;
}
matrix Pow(const matrix &a,int k){
      if(!k)
          return iden(zero((int)a.size(),(int)a[0].size()));
      else if(k&1)
           return mul(a,Pow(a,k-1));
      else 
          return Pow(mul(a,a),k>>1);
}
int main(){
#ifndef ONLINE_JUDGE

       freopen("in","r",stdin);
#endif
      int n,t;
      scanf("%d %d",&n,&t);
      long long sum=0;
      for(int i=0;i<n;i++){
         scanf("%d",arr+i);
         sum+=arr[i];
      }
      matrix trans=zero(2,2);
      trans[0][1]=n-1;
      trans[1][0]=1;
      trans[1][1]=n-2;
      matrix trans_n=Pow(trans,t);
      matrix init=zero(2,2);
      for(int i=0;i<n;i++){ 
            init[0][0]=arr[i],init[0][1]=(sum-arr[i])%MOD;
            printf("%d\n",mul(init,trans_n)[0][0]);
      }
}