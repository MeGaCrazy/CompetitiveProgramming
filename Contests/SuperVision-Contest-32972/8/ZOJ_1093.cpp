/*
*      Idea:
*           just make all possible orientation of shape x,y,z;
*           then try to get LDS :) i try to get it by binary search but failed so i get it bruteforce
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=250;
struct node{
  int x;
  int y;
  int z;
  bool operator <(node t)const{
         if(x!=t.x)return x > t.x;
         if(y!=t.y)return y > t.y;
         return   z > t.z;
      }
};
node arr[N];
//node lis[N];
int ans[N];
int main(){
    int n,Case=1;
    while(scanf("%d",&n),n){
       int nodes=0;
       for(int i=1,a,b,c;i<=n;i++){
             scanf("%d %d %d",&a,&b,&c);
             arr[nodes++]={a,b,c};
             arr[nodes++]={a,c,b};
             arr[nodes++]={b,a,c};
             arr[nodes++]={b,c,a};
             arr[nodes++]={c,a,b};
             arr[nodes++]={c,b,a};
       }
       sort(arr,arr+nodes);
       int len=1;
       /*
       lis[0]=arr[0];
       for(int i=1;i<nodes;i++){
          int l=0,r=len;
          while(l!=r){
             int mid=(l+r)>>1;
             if(arr[mid].x>arr[i].x&&arr[mid].y>arr[i].y){l=mid+1;
//               cerr<<"lis "<<lis[mid].x<<" => "<<lis[mid].y<<" => "<<lis[mid].z<<endl;
  //             cerr<<"arr "<<arr[mid].x<<" => "<<arr[mid].y<<" => "<<arr[mid].z<<endl;
             }
             else r=mid;
          }
          if(l>0&&lis[l-1].x==arr[i].x&&lis[l-1].y==arr[i].y&&arr[i].z==lis[l-1].z)continue;
          if(l==len){
             len++;
             lis[l]=arr[i];
          }
         
         // else if(arr[i].z>lis[l].z){
         //    lis[l]=arr[i];
         
         // }
       }
       */
        for(int i=0;i<nodes;i++){
           ans[i]=arr[i].z;
        }
        for(int i=1;i<nodes;i++){
           int t=0;
           for(int k=0;k<i;k++){
              if(arr[i].x<arr[k].x&&arr[i].y<arr[k].y){
                 t=max(t,arr[i].z+ans[k]);
              }
           }
           if(t)ans[i]=t;
        }
        int p=0;
        for(int i=0;i<nodes;i++){
            p=max(p,ans[i]);
        }
       printf("Case %d: maximum height = %d\n",Case++,p);
    }
}