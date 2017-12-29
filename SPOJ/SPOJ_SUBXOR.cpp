#include <bits/stdc++.h>
using namespace std;
struct trie{
  trie *a[2];
  int cnt[2];
  trie(){
    memset(a,0,sizeof(a));
    cnt[0]=cnt[1]=0;
  }
};
void Insert(trie *cur,int x){
      for(int i=20;i>=0;i--){
          if( x & (1<<i)){
               if(cur->a[1]==0){
                  cur->a[1]=new trie();
               }
               cur->cnt[1]++;
               cur=cur->a[1];
          
          }else{
             if(cur->a[0]==0){
              cur->a[0]=new trie();
             }
             cur->cnt[0]++;
             cur=cur->a[0];
          }
      }
}
void Query(trie *cur,int x,int k){
      for(int i=20;i>=0;i--){
          int p=k & (1<<i);
          int q=x & (1<<i);
          if(p){
               if(q){}
          
          }else{
          
          
          }
      
      }


}





int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
      int t;
      scanf("%d",&t);
      while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        trie *T=new trie();
        Insert(T,0);
        int Xor=0;
        int x;
        long long ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            Xor^=x;
            ans+=Query(T,Xor,k);
        }
        printf("%d\n",ans);
      
      }


}