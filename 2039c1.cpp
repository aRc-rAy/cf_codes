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
      ll x, m;
      cin >> x >> m;

      ll ans = 0;

      for (ll i = 1; i < 2 * x && i <= m; i++)
      {
            if (i != x && ((x % (x ^ i)) == 0 || (i % (x ^ i)) == 0))
            {
                  ans++;
            }
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