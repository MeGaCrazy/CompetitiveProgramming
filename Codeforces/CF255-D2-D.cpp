#include <bits/stdc++.h>
using namespace std;  	
int n,x,y,c;
bool check(int sec){
     long long ans=(sec*sec)+(sec+1)*(sec+1);      // that if we have all branches of box switch on getting from obervation 1,5,13
     if(x-t<0){             // up
        ans-=(x-sec)*(x-sec);
     }
     if(x+t>=n){                   // down
      ans-=((n-x-1)-sec)*((n-x-1)-sec);
     }
     if(y-t<0){                      // left
        ans-=(y-sec)*(y-sec);
     }
     if(y+t>=n){                          //right
      ans-=((n-y-1)-sec)*((n-y-1)-sec);
     }
     // now the part is to get the handle cutting same part twice 
     if(n-x+n-y<=t){
                   
     }	           // up left

     	                           // up right

     	                        // down left
     	                        // down right

     	return ans >=c;                       
}

int main(){
     scanf("%d %d %d %d",&n,&x,&y,&c);
     x--,y--;
     int l=0,r=(int)1e9;
     while(l<r){
         int mid=(l+r)>>1;
         if(check(mid))r=mid;
         else l=mid;
      }
      printf("%d",r);

}