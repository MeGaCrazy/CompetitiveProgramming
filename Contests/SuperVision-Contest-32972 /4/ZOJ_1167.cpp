/*
*   Idea:
*        Just make array to  p (root)
*                        2*p (l)    2*p+1 (r)
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=260;
pair<bool,int>tree[N];
char path[N],str[N];
int nodes;
bool check(){
  if(tree[1].first==0)return false;
  for(int i=2;i<=nodes;i+=2){
      bool ret=false;
      ret|=tree[i].first;
      ret|=tree[i+1].first;
      if(ret&&tree[i>>1].first==0)return false;
  }                                           
  return 1;
}                  
int main(){
      int value=0;
     while(scanf("%s",&str)!=EOF){
          bool valid=true;
          nodes=1;
          memset(tree,0,sizeof(tree));
          while(1){
             if(strcmp(str,"()")==0)break;;
             sscanf(str,"(%d,%s)",&value,&path);
             int len=strlen(path);
             int p=1;
             //cerr<<path<<endl;
             for(int i=0;i<len-1;i++){
                p*=2;
                if(path[i]=='R')p++;
             }
             if(tree[p].first)valid=0;
             tree[p].first=1;
             tree[p].second=value;
             nodes=max(p,nodes);
             scanf("%s",&str);
          }
          if(!valid||!check())puts("not complete");
          else{
            for(int i=1;i<=nodes;i++){
               if(tree[i].first){
                 printf(i==1?"%d":" %d",tree[i].second);
               }
            }
            puts("");
          }
     
     }
}