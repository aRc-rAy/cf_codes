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
      string s;
      cin >> s;

      vector<ll> v(n);
      ll ans = 0;
      for (auto &it : v)
      {
            cin >> it;
            ans = max(ans, it);
      }
      ll low = 0;
      ll high = ans;

      auto ispos = [&](ll mid)
      {
            ll seg = 0;
            bool st = 0;
            for (int i = 0; i < n; i++)
            {
                  if (s[i] == 'B' && v[i] > mid)
                  {
                        if (st == 1)
                        {
                        }
                        else
                        {
                              st = 1;
                              seg++;
                        }
                  }
                  else
                  {
                        if (st == 1 && v[i] > mid)
                        {
                              st = 0;
                        }
                  }
            }

            return seg <= k;
      };

      while (low <= high)
      {
            ll mid = low + (high - low) / 2;

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