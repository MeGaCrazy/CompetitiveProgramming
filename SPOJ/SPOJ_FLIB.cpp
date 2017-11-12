

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
                long long x=(1ll*a[i][k]*b[k][j]);
                if(x >=MOD){
                  x%=MOD;
                }
                ret[i][j]=(x+ret[i][j])%MOD;
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
      return Pow(mul(a,a),k>>1);
}
int solve(long long n){
     matrix trans=zero(3,3);
     trans[0][0]=trans[0][2]=1;
     trans[2][2]=trans[0][1]=2;
     trans[1][2]=trans[2][1]=3;
     trans[1][1]=5;
     matrix trans_n=Pow(trans,n);
     matrix init=zero(3,1);
     init[1][0]=1;
     matrix ret=mul(trans_n,init);
     return ret[0][0];
}
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}               



int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
     int t=read_int();
     while(t--){
         long long n;
         n=read_int();
         printf("%d\n",solve(n));
      //  fprintf(stderr,"The Test Run in =%d ms\n",(int)clock());
     }
}