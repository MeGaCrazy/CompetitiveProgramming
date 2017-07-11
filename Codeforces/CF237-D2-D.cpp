/*
*         target :find the optimal T-decomposition of the given tree s that has the minimum number of nodes.
*         sol    :first to achieve the first 2 conditions that he want if there edge between a,b in orginial
*                 tree must be there is a node contain the both in t tree and he want the weight be minimum
*                 so just make the edge as a node :) now there is n-1 node containe both every edge;
*                 now the third condition he want tree t contain a as anode must be from connected subtree and u can think as set if intersection 
*                 put no now u build graph not tree .....
*                 so just enough for vertex v to select x
*
*
*/

#include <bits/stdc++.h>
using namespace std;
int n;
const int N=123456;
vector<int>adj[N];
int main(){
      scanf("%d",&n);
      printf("%d\n",n-1);
      for(int i=1,a,b;i<=n-1;i++){
          scanf("%d %d",&a,&b);
          printf("2 %d %d\n",a,b);
          adj[a].push_back(i);
          adj[b].push_back(i);
      }
      for(int i=1;i<=n;i++){
          for(int j=0;j<adj[i].size()-1;j++){
              printf("%d %d\n",adj[i][j],adj[i][j+1]);
          } 
      }
}

