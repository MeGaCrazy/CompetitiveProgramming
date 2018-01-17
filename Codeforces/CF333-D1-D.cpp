/*
 *
 * @Author : MeGaCrazy
 * @init : 4:59:44 PM Jan 17, 2018
 * @idea :  First we will use binary search to check for the ans and now how to know if and valid
 *          we will go for every row and mark all columns that have number larger than or equal  ans
 *          if we found in row+i that column y,yy have value >= ans and also marked before than return True
 * Happy Solving :)
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m;
int a[N][N];
bool visit[N][N];
int sz[N];
int col[N][N];
int solve(int v) {
	memset(sz, 0, sizeof(sz));
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= v) {
				col[i][sz[i]++] = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int) sz[i]; j++) {
			for (int k = j + 1; k < (int) sz[i]; k++) {
				int y = col[i][j], yy = col[i][k];
				if (visit[y][yy])
					return 1;
				visit[y][yy] = 1;
			}
		}
	}
	return 0;
}
int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}

	}
	int l = 0, r = (int) 1e9 + 9;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (solve(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d", l);

}
