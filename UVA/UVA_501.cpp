/*
*   Don't joking with multisets hhhhhhhh :)
*   Just use vector and binary search to replace multiset operations :)
*
*/
#include <cstdio>
#include <vector>
#include <algorithm>
Using  namespace  std ;
int A[30010];
int main()
{
    int Case, M, N, tmp;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &M, &N);
        for (int i = 0; i < M; ++i)
            scanf("%d", &A[i]);

        vector<int> Box;
        int U, a = 0, i = 0; 
        while (N--) {
            scanf("%d", &U);
            While (a <U) { 
                auto iter = lower_bound(Box.begin(), Box.end(), A[a]);
                Box.insert(iter, A[a++]);
            }
            printf("%d\n", Box[i++]);
        }
        if (Case) printf("\n");
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;



int main(){
  // freopen("in","r",stdin);
   int t;
   scanf("%d",&t);
   int n,m;
   while(t--){
       scanf("%d %d",&n,&m);
       multiset<int>s;
       queue<int>seq;
       queue<int>q;
       for(int i=0,a;i<n;i++){
           scanf("%d",&a);
           seq.push(a);
       }
       for(int i=0,a;i<m;i++){
           scanf("%d",&a);
           q.push(a);
       }
       for(int i=0,sz=0;i<m;i++){
            while(sz<q.front()){
                s.insert(seq.front());
                seq.pop();
                sz++;
            }
           multiset<int>::iterator itr=s.begin();
           for(int j=0;j<i;j++){
              itr++;
           }
           printf("%d\n",*itr);
           q.pop();
       }
       if(t)puts("");
   }
}
*/