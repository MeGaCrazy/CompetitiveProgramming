/*
* target : cal num of complete covered by circle and the cell that contained segment
* sol    :  work on 1/4 of grid coz every 1/4 is repeat i mean symmetry
            do the check condition if left and right are inside the radius to valid and the at result multiply all by 4 .. 

*/



#include <bits/stdc++.h>
using namespace std;
int comp,seg,n;
int cal(int i,int j){
    return i*i+j*j;
}
void solve(){
   comp=seg=0;
   double rad=(n-0.5)*(n-0.5);
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          if((double)cal(i,j)<rad&&(double)cal(i+1,j+1)<rad)comp++; // if segment cross with i,j that must cross with i+1,j+1 :) 
          else if((double)cal(i,j)<rad&&(double)cal(i+1,j+1)>rad)seg++;
      }
   }
}

int main(){
     bool first=false;
     while(scanf("%d",&n)==1){
         if(first)puts("");
         first=true;
          solve();
          printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n",n,seg*4,comp*4);
     }




}
