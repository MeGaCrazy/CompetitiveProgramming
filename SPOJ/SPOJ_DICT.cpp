/**
*  idea : Just make Trie But instead of boolean endofWord Put Set .... and the the Set will Statisfy that is  lexiograical order :) 
*
*
**/


#include <bits/stdc++.h>
using namespace std;
const int N=26;
char str[25005][22];
struct trie{
    trie *arr[N];
    set<string>v;
    trie(){
       memset(arr,0,sizeof(arr));
       v.clear();
    }
   void insert(char *s,int x){
        if(*s=='\0'){
          v.insert((string)str[x]);
          return;
        }
        if(arr[*s-'a']==0){
           arr[*s-'a']=new trie();
        }
        arr[*s-'a']->v.insert((string)str[x]);
        arr[*s-'a']->insert(s+1,x);
    }
   set<string> Query(char *s){
         if(*s=='\0'){
            return v;
         }
         if(arr[*s-'a']==0){
           return set<string>();
         }
         return arr[*s-'a']->Query(s+1);
   } 



};




int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
      int Cas=1;
      int n;
      scanf("%d",&n);
      trie T;
      for(int i=0;i<n;i++){
          scanf("%s",&str[i]);
          char *st=&str[i][0];
          T.insert(st,i); 
      }
      int k;
      scanf("%d",&k);
      char ss[25]={};
      while(k--){
         printf("Case #%d:\n",Cas++);
         scanf("%s",&ss);
          set<string>ans=T.Query(ss);
          if((int)ans.size()==0){
             puts("No match.");
          }else{
              for( string x : ans){
                   if(x==(string)ss)continue;
                   cout<<x<<endl;
              }
          }
      }
}