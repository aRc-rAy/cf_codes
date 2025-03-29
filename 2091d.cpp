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
      ll n, m, k;
      cin >> n >> m >> k;

      ll ans = m;
      ll low = 1;
      ll high = m;

      auto ispos = [&](ll mid) -> bool
      {
            ll kitne = m / (mid + 1);
            ll rem = m % (mid + 1);
            if (rem >= mid)
            {
                  kitne++;
                  rem = 0;
            }

            ll onerow = kitne * mid + rem;

            ll tot = onerow * n;

            return tot >= k;
      };

      while (low <= high)
      {
            ll mid = (low + high) / 2;

            if (ispos(mid))
            {
                  high = mid - 1;
                  ans = mid;
            }
            else
            {
                  low = mid + 1;
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