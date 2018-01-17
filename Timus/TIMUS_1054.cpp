/*
 *    Idea : Just start from last index  and use the procedure he provides in problems statements
 *           u will notice that from last index if he reach the target position the half of elements moved
 *
 *    Happy Solving :)
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int a[N];
bool bad = false;
int solve(int n, int from, int to, int temp) {
	if (n == 0)
		return 0;
	if (a[n - 1] == from)
		return solve(n - 1, from, temp, to);
	else if (a[n - 1] == to)
		return (1 << (n - 1)) + solve(n - 1, temp, to, from);
	return bad = true;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ret = solve(n, 1, 2, 3);
	printf("%d", (bad ? -1 : ret));
}
