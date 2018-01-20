/*
 * @Author: MeGaCrazy
 * @init: 6:09:13 AM Jan 20, 2018
 * @idea:	Just Make 2 Set One For Partily Song and Full for other,,,
 *          Using Technique 2 pointers ,, move in the array and try to add more element
 *          in cur part set if part > w then erase the smallest one from part and put him in full
 *			and Also when remove a element pull from full set the biggest ones and put in partilly set :)
 * Happy Solving :)
 */
#include <bits/stdc++.h>
using namespace std;

int n, w, k;
const int N = 2e5 + 7;
int p[N], t[N];
set<pair<int, int> > full, part;
long long consume_time;
long long cur_p;
void Push(int idx) {
	part.insert(make_pair(t[idx], idx));
	consume_time += t[idx];
	consume_time -= (t[idx] - ((t[idx] + 1) >> 1));
	cur_p += p[idx];
	while ((int) part.size() > w) {
		int pos = part.begin()->second;
		consume_time += (t[pos] - ((t[pos] + 1) >> 1));
		full.insert(make_pair(t[pos], pos));
		part.erase(*part.begin());
	}
}
void Remove(int idx) {
	cur_p -= p[idx];
	if (full.count(make_pair(t[idx], idx)) == 1) {
		consume_time -= t[idx];
		full.erase(full.find(make_pair(t[idx], idx)));
	} else if (part.count(make_pair(t[idx], idx)) == 1) {
		consume_time -= ((t[idx] / 2) + (t[idx] % 2));
		part.erase(part.find(make_pair(t[idx], idx)));
	}
	while ((int) part.size() < w && (int) full.size() >= 1) {
		int pos = full.rbegin()->second;
		//cerr << "hoi " << pos << endl;
		consume_time -= (t[pos] - ((t[pos] + 1) >> 1));
		part.insert(make_pair(t[pos], pos));
		full.erase(*full.rbegin());
	}
}

int main() {
#ifndef ONLINE_JUDGE
//freopen("src/in","r",stdin);
//freopen("src/out","w",stdout);
#endif
	scanf("%d %d %d", &n, &w, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	int l = 0, r = 0;
	long long ans = 0;
	consume_time = 0;
	while (l < n) {
		r = max(r, l);
		while (r < n) {
			Push(r);
			if (consume_time > k) {
				Remove(r);
				break;
			} else
				r++;
		}
		ans = max(ans, cur_p);
		Remove(l);
		l++;
	}
	printf("%lld", ans);
}
