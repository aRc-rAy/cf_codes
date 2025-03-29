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
ll find(ll x, ll y, ll l, ll r)
{
      if (x > y)
            return 0;
      if (y < l || r < x)
      {
            return 0;
      }

      ll a = max(x, l);
      ll b = min(r, y);

      return b - a + 1;
}
void solve(ll test)
{
      ll k, l, r, p, q;
      cin >> k >> l >> r >> p >> q;
      ll ans = 0;
      for (ll i = 0; i < 40; i++)
      {
            ll cnum = 1;
            bool ispos = 1;
            for (ll j = 0; j < i; j++)
            {
                  cnum = cnum * k;
                  if (cnum > q)
                  {
                        ispos = 0;
                        break;
                  }
            }
            if (ispos)
            {
                  ll x = ceil(p * (1.0) / cnum);
                  ll y = q / cnum;

                  ans += find(x, y, l, r);
                  // cout << cnum << " " << x << " " << y << " " << ans << endl;
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