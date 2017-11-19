/**
*  idea : Just Use Trie and counter+1 if u stand on zero or one and Check max to take the length so far * number of same prefix or contiune :)
*
*  Happy Solving :)                                                                                                                                           
**/
#include <bits/stdc++.h>
using namespace std;
int ans;
char s[205];
struct trie{
  trie* a[2];
  int cntZero;
  int cntOne;
  trie(){
      memset(a,0,sizeof(a));
      cntZero=0;
      cntOne=0;
  }
  void Insert(char *str,int dep){
       if(*str=='\0'){
           return;
        }
        if((*str-'0')==1){
          cntOne++;
          ans=max(ans,cntOne*dep);
        }else{
          cntZero++;
          ans=max(ans,cntZero*dep);
        }                         
        
        if(a[(*str-'0')]==0){
           a[(*str-'0')]=new trie();
        }
        a[(*str-'0')]->Insert(str+1,dep+1);
  }
};

int main(){
#ifndef ONLINE_JUDGE
         freopen("in","r",stdin);
         freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        trie T;
        ans=0;
        for(int i=0;i<n;i++){
           scanf("%s",&s);
           T.Insert(s,1);
        }
         printf("%d\n",ans);
    
    }


}