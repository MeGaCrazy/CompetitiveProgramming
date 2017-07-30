/*
*   just using simple binary search for number of serving
*   and simulate the process 
*
*/
#include <iostream>
#include <cmath>
using namespace std;
#define oo 100000000
 
int ing[101][6];
int n, budget;
bool chk;
bool check(int srg)
{
    int minBudget = 0;
    for(int i = 0; i < n; ++i)
    {
        int diff = ing[i][1] - ing[i][0] * srg;
        if(diff < 0)
        {
            diff *= -1;
            int best = oo;
            for(int j = 0; ; ++j)
            {
                int t;
                if(j * ing[i][2] >= diff)
                    t = j * ing[i][3];
                else
                    t = j * ing[i][3] + (int)ceil( (diff - j * ing[i][2]) / (1.0*ing[i][4]) ) * ing[i][5];
                best =  min(best, t);
                if(j * ing[i][2] >= diff)
                    break;
            }
            minBudget += best;
        }
    }
    return minBudget <= budget;
}
 
 
int main()
{
//    freopen("in.txt", "r", stdin);
    cin >> n >> budget;
    for(int i = 0; i < n; ++i)
        cin >> ing[i][0] >> ing[i][1] >> ing[i][2] >> ing[i][3] >> ing[i][4] >> ing[i][5];
    int l = 0, u = budget/n + 100, ans;
    while(l <= u)
    {
        int mid = (l+u)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
            u = mid-1;
    }
    cout << ans << endl;
    return 0;
}