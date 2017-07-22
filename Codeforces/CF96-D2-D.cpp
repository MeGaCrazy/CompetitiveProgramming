/*
*       target : get SSSP with minimum cost
*         sol  : make Dijkstra with 3 parameters cost and the distance he can move and (v) vertex he go to
*                there is probalaity that  he arrive with much cost that i have but will go for distance bigger than me then i can choice him
*                2 Choices :::::
*                1-he can go this road so keep him going and still we don't need to pay for him again
*                2-i can take new taxi from this junction 
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1234;
vector<int>adj[N];
long long dis[N];
pair<int, int>taxi[N];
long long Arrlen[N];
vector<int> Len[N];
long long  solve(int s, int e) {
	// cost ,dis,to
	priority_queue<pair<long long, pair<long long, int> >, vector<pair<long long, pair<long long, int> > >, greater<pair<long long, pair<long long, int> > > >q;
	q.push(make_pair(0, make_pair(0, s)));
	while (!q.empty()) {
		long long cost = q.top().first;
		long long rem_dis = -q.top().second.first;
		int v = q.top().second.second;
		q.pop();
	
		if (dis[v] == -1) {
			dis[v] = cost;
		}
		else {
			if (dis[v] <= cost&&Arrlen[v] >= rem_dis)continue;
			dis[v] = min(dis[v], cost);
		}
		Arrlen[v] = max(Arrlen[v], rem_dis);
		for (int i = 0; i<(int)adj[v].size(); i++) {
			int u = adj[v][i];
			
			long long  dif =rem_dis-Len[v][i];
			if (dif >= 0) {
				q.push(make_pair(cost, make_pair(-dif, u)));
			}
			dif = taxi[v].first - Len[v][i];
			if (dif >= 0 && cost == dis[v]) {
				q.push(make_pair(cost + taxi[v].second, make_pair(-dif, u)));
			}
		}
	}

	return dis[e];

}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y;
	scanf("%d %d", &x, &y);
	memset(Arrlen, 0, sizeof(Arrlen));
	memset(dis, -1, sizeof(dis));
	for (int i = 0, a, b, w; i<m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back(b);
		adj[b].push_back(a);
		Len[a].push_back(w);
		Len[b].push_back(w);
	}
	for (int i = 1, d, w; i <= n; i++) {
		scanf("%d %d", &d, &w);
		taxi[i] = make_pair(d, w);
	}

	printf("%lld\n", (x == y ? 0 : solve(x, y)));
	
}
