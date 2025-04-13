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
      ll n;
      cin >> n;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      vector<ll> dp(42, 0);

      ll maxSet = 0;
      for (auto it : v)
      {
            for (ll i = 0; i <= 40; i++)
            {
                  ll key = (1LL << i) & it ? 1 : 0;
                  dp[i] += key;
                  maxSet = max(maxSet, i);
            }
      }
      ll ans = 0;
      for (auto it : v)
      {
            ll cur = 0;
            for (ll i = 0; i <= 40; i++)
            {
                  ll key = (1LL << i) & it ? 1 : 0;
                  if (key == 0)
                  {
                        ll rem = dp[i];

                        cur = cur + (rem * (1LL << i));
                  }
                  if (key == 1)
                  {
                        ll rem = n - dp[i];

                        cur = cur + (rem * (1LL << i));
                  }
            }
            ans = max(ans, cur);
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