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

ll find(auto &v, ll i, ll turn, auto &dp)
{
      ll n = v.size();
      if (i == n)
      {
            return 0;
      }

      ll &ans = dp[i][turn];
      if (ans != -1)
      {
            return ans;
      }

      ll cur = 3;

      if (turn == 1)
      {
            cur = find(v, i + 1, 0, dp) + v[i];

            if (i + 1 < n)
            {
                  cur = min(cur, find(v, i + 2, 0, dp) + v[i] + v[i + 1]);
            }
      }
      else
      {
            cur = find(v, i + 1, 1, dp);
            if (i + 1 < n)
                  cur = min(cur, find(v, i + 2, 1, dp));
      }
      return ans = cur;
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
      vector<vector<ll>> dp(n, vector<ll>(2, -1));
      ll ans = find(v, 0, 1, dp);
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