/**
*  Idea : Just use try and Check for prefix
*
*
**/

#include <bits/stdc++.h>
using namespace std;


const int N=10005;
string s[N];
const int MaxN=15;
struct trie{
   trie* arr[MaxN];
   bool Leaf;
   trie(){
      memset(arr,0,sizeof(arr));
      Leaf=0;
   }
  void Insert(char *str){
       if(*str=='\0'){
          Leaf=1;
          return;
       }
       if(arr[(*str-'0')]==0){
         arr[(*str-'0')]=new trie();
       }
       arr[(*str-'0')]->Insert(str+1);
   }
  bool Check(char *str){
      if(*str=='\0'){
         return 1;
      }
      if(arr[(*str-'0')]==0){
        return 0;
      }
      return arr[(*str-'0')]->Check(str+1);
  }
};

int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        trie T;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        bool f=1;
        sort(s+1,s+n+1);
        for(int i=n;i>=1;i--){
           char *str= &s[i][0];
           if(T.Check(str)==1){
              f=0;
              break;
           }
           T.Insert(str);
        }
        if(!f){
          puts("NO");
        }else{
          puts("YES");
        }
    
    }

}