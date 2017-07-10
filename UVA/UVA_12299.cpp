/*
*   target : make shift for some index in array and get RMQ
*    sol   : get build segment tree and (and make shifting in original array and then update tree with the elements that had shiftig :)
*
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N=123456;
int st[4*N],arr[N],val[N],sz;
char str[50];
void convert(){
    sz=0;
    int ans=0;
    int len=strlen(str);
    for(int i=0;i<len;i++){
       if(str[i]>='0'&&str[i]<='9'){
         ans=ans*10+(str[i]-'0');
       }else if(str[i]==','||str[i]==')'){
            val[sz++]=ans;
            ans=0;
       }
    }
}
int build(int p,int l,int r){
   if(l==r)return st[p]=arr[l];
   int mid=(l+r)/2;
   return st[p]=min(build(2*p,l,mid),build(2*p+1,mid+1,r));
   
}
int update(int p,int l,int r,int x,int value){
      if(x>r||x<l)return st[p];
      if(l==r&&l==x)return st[p]=value;
      int mid=(l+r)/2;
      return st[p]=min(update(2*p,l,mid,x,value),update(2*p+1,mid+1,r,x,value));
}
int query(int p,int l,int r,int i,int j){
     if(i>r||l>j)return 1e9;
     if(l>=i&&r<=j)return st[p];
     int mid=(l+r)/2;
     return  min(query(2*p,l,mid,i,j),query(2*p+1,mid+1,r,i,j));
}
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
       int n,q;
       scanf("%d %d",&n,&q);
       for(int i=1;i<=n;i++){
           scanf("%d",arr+i);
       }
       build(1,1,n);
       while(q--) {
           scanf("%s",str);
           convert();
            if(str[0]=='q'){
               printf("%d\n",query(1,1,n,val[0],val[1]));
            }else{                        
               int t=arr[val[0]];
               for(int i=1;i<sz;i++){
                   arr[val[i-1]]=arr[val[i]];
               }
               arr[val[sz-1]]=t;
               for(int i=0;i<sz;i++){
                  update(1,1,n,val[i],arr[val[i]]);
               }
            }
       }

}

