#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[] = { 0,0,-1,1,1,-1,-1,1 };
int y[] = { -1,1,0,0,1,-1,1,-1 };
int dis[N][N][10];
char arr[N][N];
int r, c;
int ansr, ansc;
bool check(int xx, int yy) {
	return xx >= 1 && yy >= 1 && xx <= r&&yy <= c && (arr[xx][yy] == '.' || arr[xx][yy] == 'F');
}
int bfs(int st, int en) {
	/*
	for (int i = 1; i <= r; i++) {
	for (int j = 1; j <= c; j++) {
	for(int k=0;k<10;k++){
	dis[i][j][k] = (int)2e9;
	}
	}
	}                  */
	memset(dis, -1, sizeof(dis));
	queue<pair<int, pair<int, int> > >q;
	q.push(make_pair(9, make_pair(st, en)));
	dis[st][en][9] = 0;
	while (!q.empty()) {
		pair<int, pair<int, int> >u = q.front();
		q.pop();
		if (u.second.first == ansr&&u.second.second == ansc)return dis[u.second.first][u.second.second][u.first];
		//return dis[u.second.first][u.second.second][u.first];
		if (arr[u.second.first][u.second.second] == 'X')continue;
		for (int i = 0; i<8; i++) {
			int xx = u.second.first + x[i], yy = u.second.second + y[i];
			if (check(xx, yy)) {
				int cost = (u.first == i) ? dis[u.second.first][u.second.second][u.first] : dis[u.second.first][u.second.second][u.first] + 1;
				if (dis[xx][yy][i] == -1 || dis[xx][yy][i]>(cost)) {
					dis[xx][yy][i] = (cost);
					q.push(make_pair(i, make_pair(xx, yy)));
				}
			}
		}
	}
		return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &r, &c);
		int st, en;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				scanf(" %c", arr[i] + j);
				if (arr[i][j] == 'F')ansr = i, ansc = j;
				if (arr[i][j] == 'S')st = i, en = j;
			}
		}
			printf("%d\n",bfs(st,en));
		/*
		int ans = (int)2e9;
		for (int i = 0; i<8; i++) {
			if (dis[ansr][ansc][i] == -1)continue;
			ans = min(ans, dis[ansr][ansc][i]);
			cerr << dis[ansr][ansc][i] << endl;
		}


		printf("%d\n", ans);
		*/

		fprintf(stderr, "The Run Time is %d ms \n", (int)clock());
	}
}