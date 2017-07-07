/*
* target : get max points in same line
* sol : just make 1 is the pivot and the next point it's second point in line and check if the third point on the line .. 
*        like point a,b make line ab and bc see if it's parallel or not by cross product
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N=702;
int x[N],y[N];
bool isSameLine(int i,int j,int k){
 int x1=x[j]-x[i];
 int x2=x[k]-x[i];
 int y1=y[j]-y[i];
 int y2=y[k]-y[i];
 return x1*y2-x2*y1==0;
}
int main(){
   // freopen("in","r",stdin);
    int t;
    scanf("%d",&t);
    bool first=false;
            getchar();
        getchar();
    while(t--){

       if(first)puts("");
       first=true;
       string str;
       int n=0;
       while(1){
         getline(cin,str);
        // cerr<<str<<endl;
         if(str=="")break;
         int a,b;
         sscanf(str.c_str(),"%d %d",&a,&b);
         x[n]=a,y[n]=b;
         n++;
         str="";
       }
       int ans=2;
       for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              int cnt=2;
              for(int k=j+1;k<n;k++){
                if(isSameLine(i,j,k))cnt++;  
              }
              if(cnt>ans)ans=cnt;
          }
       }
       printf("%d\n",ans);
    }
}