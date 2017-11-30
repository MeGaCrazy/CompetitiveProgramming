/**
*    Idea : First Part make add Function to simulate the process of adding 2 BigInteger :) 
*           Second part make trie But make it in static array like that [number of possible paths][possible digits]
*           and another array for save the First arrive in  this path for satisfy the Queries 
*
*           what is  maximum the number of possible paths = the maximum word is 40 digit and there is 100k index in fibonacci 
*            ..... so if every index take a path of 40 then the maxium paths will be [40 * 100k]
*           Corner Case : you don't need to add more than 50 digit ....
*
**/


#include <bits/stdc++.h>
using namespace std;
int cnt=1,len[3],a[3][51];

void add(int A[],int lenA,int B[],int lenB,int C[],int &lenC){
      lenC=0;
      for(int i=0,cr=0;i<lenA||i<lenB||cr;cr/=10,i++){
         if(i<lenA)cr+=A[i];
         if(i<lenB)cr+=B[i];
         C[i]=cr%10;
         lenC++;
      }
}
const int N=4000000;
int trie[N][10],id[N];
void add(int A[],int lenA,int value){
    int cur=0;
    for(int i=lenA-1;i>=max(0,lenA-40);i--){
        if(trie[cur][A[i]]==0){
          id[cnt]=value;
          trie[cur][A[i]]=cnt++;
        }
        cur=trie[cur][A[i]];
    }
}
int Query(string &s){
    int cur=0;
    for(int i=0;i<(int)s.size();i++){
       int k=s[i]-'0';
       if(trie[cur][k]==0)return -1;
       cur=trie[cur][k];
    }
  return id[cur];
}
void modify(int A[],int &lenA,int B[],int &lenB){
    for(int i=1;i<lenA;i++){
       A[i-1]=A[i];
    }
    lenA--;
    for(int i=1;i<lenB;i++){
       B[i-1]=B[i];
    }
    lenB--;
}

void Fib(){
    len[0]=1;
    a[0][0]=1;
    len[1]=1;
    a[1][0]=1;
    add(a[1],len[1],0);
    for(int i=0,j=1,k=2,idx=2;idx<100000;idx++){
        add(a[i],len[i],a[j],len[j],a[k],len[k]);
        if(len[k] > 50){
           modify(a[k],len[k],a[j],len[j]);
        }
        add(a[k],len[k],idx);
        /*
        if(idx < 10){
          cerr<<"idx -> "<<idx<<" ";
          for(int f=len[k]-1;f>=0;f--){
             cerr<<a[k][f];
          }
          cerr<<endl;
        
        }
        */


        i=(i+1)%3;
        j=(j+1)%3;
        k=(k+1)%3;
    
    }

}


int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
     Fib();
     int t;
     scanf("%d",&t);   
     int Cas=1;
     while(t--){
        string s;
        cin>>s;
        printf("Case #%d: %d\n",Cas++,Query(s));
     }


}

