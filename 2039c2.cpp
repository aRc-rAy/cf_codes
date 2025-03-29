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

      // div by x
      {
            // if (m >= x)
            // {
            //       ans += (m - x) / x;
            // }

            // for (ll i = m - x + 1; i <= m + x; i++)
            // {
            //       if (i <= 0)
            //             continue;
            //       ll p = (i ^ x);
            //       if (p >= 1 && p <= m && p % x == 0)
            //             ans++;
            // }

            // divisible by x
            ll p = m - m % x;
            ans = p / x - (x < p);
            if ((x ^ p) >= 1 and (x ^ p) <= m)
                  ++ans;
            p += x;
            if ((x ^ p) >= 1 and (x ^ p) <= m)
                  ++ans;
      }
      // div by y
      for (ll i = 1; i <= x; i++)
      {
            ll p = x ^ i;
            if (p % i == 0 && p <= m)
            {
                  ans++;
            }
      }

      // div by both
      if (x <= m)
      {
            ans--;
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