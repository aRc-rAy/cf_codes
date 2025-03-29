#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void solve(ll test)
{
      ll n, m;
      cin >> n >> m;
      ll ans = 0;
      ll px = 0;
      ll py = 0;
      for (int i = 0; i < n; i++)
      {
            ll x, y;
            cin >> x >> y;
            if (i == 0)
            {
                  ans += 4 * m;
            }
            else
                  ans += (2 * m + x + y) - (m - x) - (m - y);
      }
      cout << ans << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}