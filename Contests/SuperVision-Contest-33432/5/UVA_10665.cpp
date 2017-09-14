/*
*  Idea : just he want to put heavest and then first alphabetical :)
*         one in left and on right 
*         Corner Case : from left  heavest ,smallest alphabetical ---- right  heavest ,largetst alphabetical
*
*        Happy Solving :)
*/
#include <bits/stdc++.h>
const int N=26;
using namespace std;
pair<int,int>arr[N];
pair<int,int>ans[N];
bool cmp1(pair<int,int>a,pair<int,int>b){
     return a.second > b.second ||(a.second==b.second && a.first < b.first);
}
bool cmp2(pair<int,int>a,pair<int,int>b){
     return a.second > b.second ||(a.second==b.second && a.first > b.first);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
     int n;
     scanf("%d",&n);
     string s;
     cin>>s;
     memset(arr,0,sizeof(arr));
     for(int i=0;i<26;i++){
        arr[i].first=i;
     }
     for(int i=0;i<(int)s.size()-1;i++){
        arr[s[i]-'A'].second++;
     }
     int st=0,en=n-1;
     for(int i=0;i<n;){
         if(i+1==n){ans[st]=arr[i++];continue;}
         sort(arr+i,arr+n,cmp1);
         if(arr[i].second!=arr[i+1].second){
            if(arr[i].first <arr[i+1].first){
               ans[st++]=arr[i];
               sort(arr+i+1,arr+n,cmp2);
               ans[en--]=arr[i+1];
            }else{
              swap(arr[i],arr[i+1]);
              ans[st++]=arr[i];
              sort(arr+i+1,arr+n,cmp2);
              ans[en--]=arr[i+1];
            }
         }
         else{
            sort(arr+i,arr+n,cmp1);
            ans[st++]=arr[i];
            sort(arr+i+1,arr+n,cmp2);
            ans[en--]=arr[i+1];
         }
         i+=2;
     }
     for(int i=0;i<n;i++){
        printf(i==0?"%c":" %c",(char)(ans[i].first+'A'));
     }
     puts("");
     for(int i=0;i<n;i++){
        printf(i==0?"%d":" %d",ans[i].second);
     }
     puts("");
  }


}