/*
*  target : check if can make this sequence palindrome with less than or equal k insertion
*   sol   : Just make 2 choice insert in front or in back :) easy Still get good run time without carring about memoization 
*
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N=12345;
int arr[N];
int n,k;
#define inf 12356
int solve(int i,int j,int mv)
{
    if(mv>k)return inf;
    if(i>=j )return mv;

    if(arr[i]==arr[j]) return solve(i+1,j-1,mv);

    else{
         return min(solve(i,j-1,mv+1), solve(i+1,j,mv+1));
        }

}
int main()
{
   // FRD;

    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",arr+i);
        }
        int ans=solve(0,n-1,0);
        printf("Case %d: ",cas++);
        if(ans==0)printf("Too easy");
        else if(ans<=k) printf("%d",ans);
        else printf("Too difficult");
        cout<<endl;
    }
    return 0;
}