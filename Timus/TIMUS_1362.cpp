/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Jan 13 18:18:52 2018
*   @Idea :   We need to simulate the problem that it tree and his root is Tanya Put if u look at tree from  root u will not reach any solution 
*             Let Think in leaf and go up try to generate forumla 
*             assume tree like this          
*                                    x       we will put every leaf with 0 that mean no child in it z=0,y=0
*                                  y   z
*
*             now try from any node not leaf to calculate how many second will take to visit all his childs  in sample above obviously 2
*
*             But let go more larger     a          now d,e,f = 0  then c =1 and b =2 now if u want choose b or c it will depend on number of  child
*                                      b    c
*                                    d   e   f
*
*             if b's child > c's child will visit his childs before c does ,,,
*             for more ellaboration if c have no childs and i take c then sec  =1 and taken node {c} in snd second sec=2 taken nodes {b,c}
*             But if take b first in 1st second taken nodes {b} in 2nd second {b,d,c}
*
*             when we in a we will sort his childs depend on their # of childs 
*             get max of {number of child - his position} + number of child in child 
                                          ^
                                          |
*                           second taken to be visited from parent          
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int visit[N];
int q[N];
vector<int>adj[N];
int childs[N];
int dp[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	//freopen("out","w",stdout);
#endif
	int n;
	scanf("%d", &n);
	int st;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++) {
		while (1) {
			int x;
			scanf("%d", &x);
			if (!x)break;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
	}
	scanf("%d", &st);
	int head = 0, tail = 0;
	q[tail++] = st;
	visit[st]=1;
	while (head <= tail) {
		int v = q[head++];
		for (int u : adj[v]) {
			if (!visit[u]) {
				visit[u] = 1;
				q[tail++]=u;
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = N - 1; i >= 0; i--) {
		int v = q[i];
		int len = 0;
		for (int u : adj[v]) {
			if (dp[u] != -1)childs[len++] = dp[u];
		}
		dp[v] = 0;
		sort(childs, childs + len);
		for (int j = 0; j<len; j++) {
			dp[v] = max(dp[v], len - j + childs[j]);
		}
	}
	printf("%d", dp[st]);

}