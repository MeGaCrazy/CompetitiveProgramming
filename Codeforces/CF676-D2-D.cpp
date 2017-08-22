/*
*      Idea : if i come from bottom my direction is up and so on for all :)  so u must check this condition =D 
*             then must check if he can rotate or not :)
*             There is only 4 rotation if more return to original :)
*             then the maze be like that [rotation-state (0..3)][x][y] 
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct node {
	int x, y, rot, t;
	friend bool operator <(node a, node b) {
		return  a.t > b.t;
	}
}s, e;
priority_queue<node>q;
bool vis[5][N][N];
char maze[5][N][N];
const int x[] = { 1,0,-1,0 };
const int y[] = { 0,-1,0,1 };
int n, m;
char next_rot(char c) {
	if (c == '*')return '*';
	if (c == '+')return '+';
	if (c == '-')return '|';
	if (c == '|')return '-';
	if (c == '^')return '>';
	if (c == '>')return 'v';
	if (c == 'v')return '<';
	if (c == '<')return '^';
	if (c == 'L')return 'U';
	if (c == 'R')return 'D';
	if (c == 'U')return 'R';
	if (c == 'D')return 'L';
	return '*';
}
bool check(int x, int y, int rot, int dir) {
	if (maze[rot][x][y] == '+')return 1;
	char c = maze[rot][x][y];
	if (dir == 0) {  // bottom
		if (c == 'v' || c == '|' || c == 'L' || c == 'R' || c == 'U')return 1;
	}
	if (dir == 1) { // left
		if (c == '-' || c == '<' || c == 'R' || c == 'U' || c == 'D')return 1;
	}
	if (dir == 2) { // up
		if (c == '^' || c == '|' || c == 'R' || c == 'L' || c == 'D')return 1;
	}
	if (dir == 3) {  // right
		if (c == '>' || c == '-' || c == 'L' || c == 'U' || c == 'D')return 1;
	}
	return 0;
}
int bfs() {
	q.push(s);
	vis[s.rot][s.x][s.y] = 1;
	while (!q.empty()) {
		node u = q.top();
//		cerr << u.x << " => " << u.y << " => " << u.rot << endl;
		q.pop();
		if (u.x == e.x&&u.y == e.y)return u.t;
		for (int i = 0; i<4; i++) {
			int xx = u.x + x[i], yy = u.y + y[i];
			if (xx <= 0 || xx>n || yy>m || yy <= 0 || vis[u.rot][xx][yy] || maze[u.rot][xx][yy] == '*')continue;
			if (check(u.x, u.y, u.rot, i) && check(xx, yy, u.rot, (i + 2) % 4)) {
				q.push({ xx,yy,u.rot,u.t + 1 });
				vis[u.rot][xx][yy] = 1;
			}
		}
		if (!vis[(u.rot + 1) % 4][u.x][u.y]) {
			vis[(u.rot + 1) % 4][u.x][u.y] = 1;
			q.push({ u.x,u.y,(u.rot + 1) % 4,u.t + 1 });
		}
	}
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[0][i][j];
		}
	}
	scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);
	s.rot = s.t = 0;
	for (int i = 1; i<4; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				maze[i][j][k] = next_rot(maze[i - 1][j][k]);
			}
		}
	}
	printf("%d", bfs());

}




