#include <bits/stdc++.h>
using namespace std;
vector<int>v;


int main(){
      int n;
      scanf("%d",&n);
      for(int i=0,a;i<n;i++){
         scanf("%d",&a);
         vector<int>::iterator it=lower_bound(v.begin(),v.end(),a);
         if(it==v.end())v.push_back(a);
         else *it=a;
      }
      printf("%d\n",v.size());
}

