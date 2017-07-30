/*
*   just using simple binary search for number of serving
*   and simulate the process 
*
*/
#include <bits/stdc++.h>
using namespace std;
#define oo 100000000

int arr[101][6];
int n, budget;
bool chk;
bool check(int srg)
{
	int minBudget = 0;
	for (int i = 0; i < n; ++i)
	{
		int diff = arr[i][1] - arr[i][0] * srg;
		if (diff < 0)
		{
			diff *= -1;
			int best = oo;
			for (int j = 0; ; ++j)
			{
				int t;
				if (j * arr[i][2] >= diff)
					t = j * arr[i][3];
				else
					t = j * arr[i][3] + (int)ceil((diff - j * arr[i][2]) / (1.0*arr[i][4])) * arr[i][5];
				best = min(best, t);
				if (j * arr[i][2] >= diff)
					break;
			}
			minBudget += best;
		}
	}
	return minBudget <= budget;
}


int main()
{
#ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
#endif
	cin >> n >> budget;
	for (int i = 0; i < n; ++i)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4] >> arr[i][5];
	int l = 0, u = budget / n + 100, ans;
	while (l <= u)
	{
		int mid = (l + u) / 2;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
			u = mid - 1;
	}
	printf("%d", ans);
	return 0;
}