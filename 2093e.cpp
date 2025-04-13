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
      ll n, k;
      cin >> n >> k;

      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      ll low = 1;
      ll high = n;

      ll ans = 0;
      auto ispos = [&](ll mid) -> bool
      {
            vector<bool> dp(n + 1, 0);
            ll cnt = 0;
            ll mex = 0;
            for (auto it : v)
            {
                  if (it < n + 1)
                        dp[it] = 1;

                  while (mex < n + 1 && dp[mex])
                        mex++;

                  if (mex >= mid)
                  {
                        for (int i = 0; i <= mex; i++)
                              dp[i] = 0;
                        cnt++;
                        mex = 0;
                  }
            }

            return cnt >= k;
      };

      while (low <= high)
      {
            ll mid = (low + high) / 2;

            if (ispos(mid))
            {
                  low = mid + 1;
                  ans = mid;
            }
            else
            {
                  high = mid - 1;
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