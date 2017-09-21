/*
*   Idea : First of all Multiply the benefit by 2 to avoid float numbers and result divide by 2
*          Second The Recurrence is [day][prev_cost][prev_dish][prev_dish_count] 
*          Third : when u want to print path from last Day to First Day Try to Consider 2 things
                   (If i was the same like the prev i must eat Numberdishes-1 than the prev)
*          The Tricky Condition : u must eat anything in this day even the dish won't give u benefit :)
*
*
*          Happy Solving :)
*/

#include <bits/stdc++.h>
using namespace std;
int dp[22][105][55][22];
pair<int,int> arr[55];



int main(){
      int k,n,m;
      while(scanf("%d %d %d",&k,&n,&m),(k+n+m)){
            for(int i=1;i<=n;i++){
              scanf("%d %d",&arr[i].first,&arr[i].second);
              arr[i].second<<=1;
            }
            memset(dp,0,sizeof(dp));
            int ans=0;
            for(int i=1;i<=k;i++){
               for(int j=0;j<=m;j++){
                 for(int cur=1;cur<=n;cur++){
                    for(int prev=1;prev<=n;prev++){
                       for(int cnt=0;cnt<i;cnt++){
                         int nextcnt=1;
                         if(prev==cur)nextcnt=cnt+1;
                         if(j + arr[cur].first > m)continue;
                         if((i-1)!=0 && dp[i-1][j][prev][cnt]==0)continue;
                         if(nextcnt<=2) dp[i][j+arr[cur].first][cur][nextcnt]=max(dp[i][j+arr[cur].first][cur][nextcnt],dp[i-1][j][prev][cnt]+(arr[cur].second/nextcnt));
                         else  dp[i][j+arr[cur].first][cur][nextcnt]=max(dp[i][j+arr[cur].first][cur][nextcnt],dp[i-1][j][prev][cnt]);
                      }
                    }
                 }
               }
            }
            int st=0;
            for(int i=0;i<=m;i++){
               for(int j=1;j<=n;j++){
                  for(int f=1;f<=k;f++){
                    if(ans < dp[k][i][j][f]){
                       ans=dp[k][i][j][f];
                       st=i;
                    }
                  }
               }
            }
          int tmp=ans;
          printf("%.1f\n",ans/2.0);
            //path
          if(ans){
            stack<int>s;
            int prev=0,prev_cnt=0;
            for(int i=k;i>=1;i--){
               bool ok=1;
               for(int j=1;j<=n&&ok;j++){
                  for(int cnt=1;cnt<=k&&ok;cnt++){
                      if(prev_cnt>=2&&j!=prev)continue;
                      if((dp[i][st][j][cnt]==tmp&&(prev!=j ||(prev==j &&cnt==prev_cnt-1 )))){
                         s.push(j);
                         st-=(arr[j].first);
                         if(cnt<=2){
                          tmp-=(arr[j].second/cnt);
                         }
                         ok=0;
                         prev=j;
                         prev_cnt=cnt;
                      }
                  }
               }
            }
            printf("%d",s.top());
            s.pop();
            while(!s.empty()){
               printf(" %d",s.top());
               s.pop();
            }
            puts("");
          }
      }
}



/*
  First Trying
#include <bits/stdc++.h>
using namespace std;
double dp[25][55][2];
const double eps=1e-6;
#define cost first
#define f second
pair<int,int> arr[55];
int p[55][55];
void print(int d,int y){
     if(d==1){
       printf("%d\n",y);
       return;
     }                                         
      print(d-1,p[d][y]);
      printf("%d\n",y);
}





int main(){

    int k,n,m;
    while(scanf("%d %d%d",&k,&n,&m),(k||n||m)){
        for(int i=1;i<=n;i++){
           scanf("%d %d",&arr[i].cost,&arr[i].f);
        }
        for(int i=0;i<=k;i++){
          for(int j=0;j<=n;j++){
            dp[i][j][0]=0;
            dp[i][j][1]=1e9;
            if(i==0)dp[i][j][0]=0,dp[i][j][1]=0;
          }
        }
        memset(p,-1,sizeof(p));
        for(int i=1;i<=k;i++){
           for(int x=1;x<=n;x++){
             for(int j=1;j<=n;j++){
               if(arr[x].cost + dp[i-1][j][1] > m)continue;
               if(x==j&&i>2)continue;
               else{
                 double bf=0;
                 int Cost=arr[x].cost + dp[i-1][j][1];
                 if(x==j){
                     bf=(((double)arr[x].f/i)+dp[i-1][j][0]);
                 }else{
                     bf=(((double)arr[x].f)+dp[i-1][j][0]);
                     }
                  if( ((dp[i][j][0] - bf) < eps)||((dp[i][j][0] - bf) >= eps && dp[i][j][1]  > Cost)  ){
                       dp[i][j][0]=bf;
                       dp[i][j][1]=Cost;
                       p[i][j]=x;
                  }
               }
            }
          }
        }
        double ans=0;
        int Cost=(int)1e9;
        int y=0;
        for(int i=1;i<=n;i++){
           if(((ans - dp[k][i][0]) < eps) ||(dp[k][i][1] < Cost && (ans - dp[k][i][0] ) <= eps) ){
              y=i;
              ans=dp[k][i][0];
              Cost=dp[k][i][1];
           }
       }
       printf("%.1f\n",ans);
       if((ans >eps)) print(k,y); 
       puts("");
    }
}
*/

