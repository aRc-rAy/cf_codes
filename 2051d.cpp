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
      ll n, x, y;
      cin >> n >> x >> y;

      vector<ll> v(n);
      ll tot = 0;
      for (auto &it : v)
      {
            cin >> it;
            tot += it;
      }
      sort(begin(v), end(v));

      ll ans = 0;
      for (int i = 0; i < n; i++)
      {
            ll low = tot - v[i] - y;
            ll high = tot - v[i] - x;

            ll li = lower_bound(begin(v), end(v), low) - begin(v);

            ll hi = upper_bound(begin(v), end(v), high) - begin(v);

            ll tans = hi - li;

            // cout << tans << " " << li << " " << hi << endl;

            if (i >= li && i < hi)
            {
                  tans--;
            }
            if (tans >= 0)
            {
                  ans += tans;
            }
      }
      cout << ans / 2 << endl;
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